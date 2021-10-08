from .models import Nutrition, Foodimage, Foodlist
from user.models import *
from django.core.files.storage import FileSystemStorage
from django.http.response import HttpResponse
from django.shortcuts import render, redirect
from django.db.models import Q
from datetime import datetime, timedelta
import os, json, datetime


# Create your views here.
def main(request):
    # try:
    #     if request.session['user']:
            if request.method == 'POST':
                mainTime = request.POST['mainDate']
                if 'deleteSeq' in request.POST.dict().keys():
                    deleteImage = Foodimage.objects.get(fileSeq=request.POST['deleteSeq'])
                    deleteImage.isDeleted = 1
                    deleteImage.save()
            else:
                mainTime = datetime.datetime.now().strftime("%Y-%m-%d")
                # current = datetime.datetime.now().strftime("%Y-%m-%d")
            user = User.objects.get(user_name=request.session['user'])
            ## 총 섭취 칼로리
            BMI = user.userWeight / ((user.userHeight/100) ** 2) # BMI 
            # 과체중 이상 (BMI >= 25 : 과체중, BMI >= 30 비만)
            if(BMI >= 25): 
                std_kcal = user.userWeight * 30 - 250
            # 과체중 이하
            else :
                std_kcal = (user.userHeight-100)*0.9 * 30 # 표준체중 (편집됨) 

            ## 아침 식단
            Breakfast_final = []
            Breakfast_image_final = []
            Breakfast_images = Foodimage.objects.filter(Q(user_name = request.session['user']) & Q(eatDate=mainTime) & Q(eatTime='B')&Q(isDeleted=0))
            for Breakfast_image in Breakfast_images:
                Breakfast_image_final.append({"BreakfastImage" : Breakfast_image.foodImg, "FileSeq" : Breakfast_image.fileSeq})
                Breakfast_list = Foodlist.objects.filter(fileSeq=Breakfast_image.fileSeq)
                for Breakfast in Breakfast_list:
                    gram = float(Breakfast.food_id.에너지_field)*float(Breakfast.food_gram/float(Breakfast.food_id.number_1회_제공량_g_field))
                    Breakfast_final.append({"FileSeq" : Breakfast.fileSeq.fileSeq, "name": Breakfast.food_id.food_name, 'gram': Breakfast.food_gram, 'cal': round(gram,2)})
            

            ## 점심 식단
            Lunch_final = []
            Lunch_image_final = []
            Lunch_images = Foodimage.objects.filter(Q(user_name = request.session['user']) & Q(eatDate=mainTime) & Q(eatTime='L')&Q(isDeleted=0))
            for Lunch_image in Lunch_images:
                Lunch_image_final.append({"LunchImage" : Lunch_image.foodImg, "FileSeq" : Lunch_image.fileSeq})
                Lunch_list = Foodlist.objects.filter(fileSeq=Lunch_image.fileSeq)
                for Lunch in Lunch_list:
                    gram = float(Lunch.food_id.에너지_field)*float(Lunch.food_gram/float(Lunch.food_id.number_1회_제공량_g_field))
                    Lunch_final.append({"FileSeq" : Lunch.fileSeq.fileSeq, "name": Lunch.food_id.food_name, 'gram': Lunch.food_gram, 'cal': round(gram,2)})

            ## 저녁 식단
            Dinner_final = []
            Dinner_image_final = []
            Dinner_images = Foodimage.objects.filter(Q(user_name = request.session['user']) & Q(eatDate=mainTime) & Q(eatTime='D')&Q(isDeleted=0))
            for Dinner_image in Dinner_images:
                Dinner_image_final.append({"DinnerImage" : Dinner_image.foodImg, "FileSeq" : Dinner_image.fileSeq})
                Dinner_list = Foodlist.objects.filter(fileSeq=Dinner_image.fileSeq)
                for Dinner in Dinner_list:
                    gram = float(Dinner.food_id.에너지_field)*float(Dinner.food_gram/float(Dinner.food_id.number_1회_제공량_g_field))
                    Dinner_final.append({"FileSeq" : Dinner.fileSeq.fileSeq, "name": Dinner.food_id.food_name, 'gram': Dinner.food_gram, 'cal': round(gram,2)})

            ## 하루 섭취 영양 성분

            image_file = Foodimage.objects.filter(Q(user_name = request.session['user'])&Q(eatDate=mainTime)&Q(isDeleted=0))

            단백질=0; 탄수화물=0; 지방=0; 에너지=0
            for image in image_file:
                food_list = Foodlist.objects.filter(fileSeq=image.fileSeq)
                for food in food_list:
                    nutrition = Nutrition.objects.filter(food_id = food.food_id.food_id)

                    섭취량 = nutrition[0].number_1회_제공량_g_field
                    단백질 += (float(nutrition[0].단백질_g_field) * (int(food.food_gram)/int(섭취량)))
                    탄수화물 += (float(nutrition[0].탄수화물_g_field) * (int(food.food_gram)/int(섭취량)))
                    지방 += (float(nutrition[0].지방_g_field) * (int(food.food_gram)/int(섭취량)))
                    에너지 += (float(nutrition[0].에너지_field) * (int(food.food_gram)/int(섭취량)))
            contents = {'기준에너지': std_kcal, '에너지': round(에너지,2), '단백질' : round(단백질,2), '탄수화물': round(탄수화물,2), '지방' : round(지방, 2),
                        'mainTime': mainTime, 'Breakfast': Breakfast_final, 'Lunch' : Lunch_final, 'Dinner' : Dinner_final,
                        'BreakfastImage' : Breakfast_image_final, 'LunchImage' : Lunch_image_final, 'DinnerImage' : Dinner_image_final, 'user' : request.session['user']}
            return render(request, 'main/main.html',contents)
    # except:
    #     return HttpResponse('로그인 후 이용 가능합니다.')
def warning(request):

    username = request.session['user'] # 로그인되어 있는 user 값 받기
    foodimage_list = Foodimage.objects.filter(Q(user_name = username)).order_by('-fileSeq') # Foodimage 받기 (foodimage_list[0] : user 가 올린 사진 중 제일 최근에 업로드한 파일) 
    
    ### 하루 동안 섭취한 단백질 / 탄수화물 / 지방 / 포화지방산 / 불포화지방산 / 콜레스테롤 / 나트륨 / 총당류   
    sum_pro = 0; sum_cy = 0; sum_f = 0; sum_sf = 0; sum_tf = 0;  sum_chol = 0; sum_sodi = 0; sum_sug=0
    image_list = Foodimage.objects.select_related('user_name').filter(Q(user_name=username) & Q(eatDate=foodimage_list[0].eatDate) & Q(isDeleted=0)) # Foodimage 와 User(image_list[i].user_name) 정보 접근 가능
    user = image_list[0].user_name # user 상세 정보
    for image in image_list: 
        food_list = Foodlist.objects.select_related('food_id').filter(Q(fileSeq=image.fileSeq)) # Foodlist 와 Nutrition(foodlist[i].food_id) 접근 가능
        for food in food_list:
            nutrition = food.food_id # nutrition 상세 정보 
            food_gram = nutrition.number_1회_제공량_g_field # 기본 제공량 (cf. food.food_gram : 사용자가 먹은 양)
            sum_pro += (nutrition.단백질_g_field * (food.food_gram/food_gram)) 
            sum_cy += (nutrition.탄수화물_g_field * (food.food_gram/food_gram))
            sum_f += (nutrition.지방_g_field * (food.food_gram/food_gram))
            sum_sf += (nutrition.총_포화_지방산_g_field * (food.food_gram/food_gram))
            sum_tf += (nutrition.트랜스_지방산_g_field * (food.food_gram/food_gram))
            sum_chol += (nutrition.콜레스테롤_field * (food.food_gram/food_gram))
            sum_sodi += (nutrition.나트륨_field * (food.food_gram/food_gram))
            sum_sug += (nutrition.총당류_g_field * (food.food_gram/food_gram))
    
    std_kal = ((((int(user.userHeight))-100)*0.9)*25) # user 섭취 칼로리 기준
    check_list = {"base_gram_pro" : 1000000, "base_gram_cy" : 1000000, "base_gram_f" : 1000000, "base_gram_sf" : 1000000, "base_gram_tf" : 1000000, # 영샹성분 섭취 기준 
                "base_gram_chol" : 1000000, "base_gram_sodi" : 1000000, "base_gram_sug" : 100000}
    results = []

    ## 이상지혈증 가진 사람
    if (user.userDysl == '1' or user.userDysl=='2a' or user.userDysl=='2b' or user.userDysl=='3' or user.userDysl=='4' or user.userDysl=='5'):
        # 포화지방산
        base_gram_sf  = (std_kal * 0.07)/9 
        if base_gram_sf < check_list["base_gram_sf"]:
            check_list["base_gram_sf"] = base_gram_sf
            if base_gram_sf < sum_sf:
                results.append({'nutrition': '포화지방', 'base' : str(round(base_gram_sf,2))+'g', 'user' : str(round(sum_sf-base_gram_sf,2))+'g'})
            else : pass
        else: pass
        # 지방
        base_gram_f = (std_kal * 0.3)/9
        if base_gram_f < check_list["base_gram_f"]:
            check_list["base_gram_f"] = base_gram_f
            if base_gram_f < sum_f :
                results.append({'nutrition': '지방', 'base' : str(round(base_gram_f,2))+'g', 'user' : str(round(sum_f-base_gram_f,2))+'g'})
            else: pass
        else: pass
        # 콜레스테롤
        base_gram_chol = 200
        if base_gram_chol < check_list["base_gram_chol"]:
            check_list["base_gram_chol"] = base_gram_chol
            if base_gram_chol < sum_chol :
                results.append({'nutrition': '콜레스테롤', 'base' : str(round(base_gram_chol,2))+'mg', 'user' : str(round(sum_chol-base_gram_chol,2))+'mg'})
            else: pass
        else: pass
        # 탄수화물
        base_gram_cy = (std_kal*0.65)/4
        if base_gram_cy < check_list["base_gram_cy"]:
            check_list["base_gram_cy"] = base_gram_cy
            if  base_gram_cy < sum_cy:
                results.append({'nutrition': '탄수화물', 'base' : str(round(base_gram_cy,2))+'g', 'user' : str(round(sum_cy-base_gram_cy,2))+'g'})
            else: pass
        else: pass    

    ## 고혈압을 가진 사람
    if(user.userHyper == '1' or user.userHyper=='2'):
        # 나트륨
        base_gram_sodi = 2000
        if base_gram_sodi < check_list["base_gram_sodi"]:
            check_list["base_gram_sodi"] = base_gram_sodi
            if base_gram_sodi < sum_sodi :
                results.append({'nutrition': '나트륨', 'base' : str(round(base_gram_sodi,2))+'mg', 'user' : str(round(sum_sodi-base_gram_sodi,2))+'mg'})
            else: pass
        else: pass
        # 단백질
        base_gram_pro = (std_kal*0.2)/4
        if base_gram_pro <= check_list["base_gram_pro"]:
            check_list["base_gram_pro"] = base_gram_pro
            if sum_pro >= base_gram_pro:
                results.append({'nutrition': '단백질', 'base' : str(round(base_gram_pro,2))+'g', 'user' : str(round(sum_pro-base_gram_pro,2))+'g'})
            else: pass
        else: pass
        # 콜레스테롤 
        base_gram_chol = 300
        if base_gram_chol < check_list["base_gram_chol"]:
            check_list["base_gram_chol"] = base_gram_chol
            if  base_gram_chol < sum_chol :
                results.append({'nutrition': '콜레스테롤', 'base' : str(round(base_gram_chol,2))+'mg','user' : str(round(sum_chol-base_gram_chol,2))+'mg'})
            else: pass
        else: pass
    
    ## 당뇨를 가진 사람
    if(user.userDia == '1' or user.userDia=='2'):
        # 나트륨
        base_gram_sodi = 3000
        if base_gram_sodi < check_list["base_gram_sodi"]:
            check_list["base_gram_sodi"] = base_gram_sodi
            if base_gram_sodi < sum_sodi:
                results.append({'nutrition': '나트륨', 'base' : str(round(base_gram_sodi,2))+'mg', 'user' : str(round(sum_sodi-base_gram_sodi,2))+'mg'})
            else: pass
        else: pass
        # 단백질
        base_gram_pro = (std_kal*0.24)/4
        if base_gram_pro < check_list["base_gram_pro"]:
            check_list["base_gram_pro"] = base_gram_pro
            if base_gram_pro < sum_pro:
                results.append({'nutrition': '단백질', 'base' : str(round(base_gram_pro,2))+'g', 'user' : str(round(sum_pro-base_gram_pro,2))+'g'})
            else: pass
        else: pass
        # 포화지방
        base_gram_sf = (std_kal*0.1)/9
        if base_gram_sf <= check_list["base_gram_sf"]:
            check_list["base_gram_sf"] = base_gram_sf
            if sum_sf >= base_gram_sf:
                results.append({'nutrition': '포화지방', 'base' : str(round(base_gram_sf,2))+'g', 'user' : str(round(sum_sf-base_gram_sf,2))+'g'})
            else: pass
        else: pass
        # 트랜스지방
        base_gram_tf = 0
        if base_gram_sf <= check_list["base_gram_tf"]:
            check_list["base_gram_tf"] = base_gram_tf
            if sum_tf >= base_gram_tf:
                results.append({'nutrition': '트랜스지방', 'base' : str(round(base_gram_tf,2))+'g', 'user' : str(round(sum_tf-base_gram_tf,2))+'g'})
            else: pass
        else: pass

    contents = {'results' : results, 'user' : username ,'User': user, 'fileSeq' : foodimage_list[0].fileSeq}

    # return HttpResponse("DB 테스트 중입니다.")
    return render(request, 'main/warning.html', contents)

def delete(request):
    if 'foodPass' in request.POST.dict().keys():
        print(request.POST['foodPass'])
        if request.POST['foodPass'] == '1':
            deleteImg = Foodimage.objects.get(fileSeq = request.POST['foodSeq'])
            deleteImg.isDeleted = 1
            deleteImg.save()
            return redirect('main')
    return redirect('main')

def upload(request):
    # try:
    #     if request.session['user']:
            if request.method == 'POST':
                if len(request.POST) == 1:
                    myfile = request.FILES['foodImg']
                    fs = FileSystemStorage(location='main/static/main/image', base_url='main/static/main/image')  ## 확인 필요
                    fs.save(request.session['user']+myfile.name, myfile)
                    os.system("./darknet/darknet detector test darknet/data/obj_final.data \
                                darknet/cfg/yolov4test-final.cfg darknet/backup/yolov4-final_best.weights \
                                -dont_show -save_labels -out output/output_" + request.FILES['foodImg'].name[:-4] +  ".json\
                                main/static/main/image/" + request.session['user'] + request.FILES['foodImg'].name + " -gpus 0")

                    with open(('output/output_' + request.FILES['foodImg'].name[:-4]+ '.json'), 'r') as f:
                        jsonData = json.load(f)
                        detectFoodList = []
                        for objectData in jsonData[0]['objects']:
                            foodName = Nutrition.objects.get(food_id=int(objectData['name']))
                            detectFoodList.append(foodName)
                    return render(request, 'main/analyze.html', {'detectFoodList' : detectFoodList, 'imageName' : request.FILES['foodImg'].name, 'userName' : request.session['user'], 'user' : request.session['user']})
                
                if len(request.POST) == 6:
                    food_image = Foodimage()
                    food_image.foodImg = request.POST['imageName']
                    food_image.eatTime = request.POST['eatTime']
                    food_image.eatDate = request.POST['eatDate']
                    food_image.user_name = User.objects.get(user_name=request.session['user'])
                    food_image.save()

                    foodNameList = request.POST.getlist('foodName')
                    foodGramList = request.POST.getlist('foodGram')
                    for i in range(len(foodNameList)):
                        try :
                            Nutrition.objects.get(food_name=foodNameList[i])
                            if foodNameList[i] != '' and foodGramList[i] != '':
                                food_list = Foodlist()
                                food_list.fileSeq = food_image
                                food_list.food_id = Nutrition.objects.get(food_name=foodNameList[i])
                                food_list.food_gram = foodGramList[i]
                                food_list.save()
                        except:
                            pass

                    # warning 검색 : 영양성분 초과 머시기머시기 출력 모달
                    # return warning(request, food_image.fileSeq)
                    return redirect('warning')

                # if 'foodPass' in request.POST.dict().keys():
                #     print(request.POST['foodPass'])
                #     if request.POST['foodPass'] == '1':
                #         deleteImg = Foodimage.objects.get(fileSeq = request.POST['foodSeq'])
                #         deleteImg.isDeleted = 1
                #         deleteImg.save()
                #     return redirect('main')
                
            return render(request, 'main/upload.html', {'user' : request.session['user']})
    # except:
    #     return HttpResponse('로그인 후 이용 가능합니다.')

    ### 주간 분석
def check(request):
    ## 날짜 
    if request.method == 'POST': # 사용자 입력
        mainTime = request.POST['mainDate']
        mainTime = datetime.datetime.strptime(mainTime, "%Y-%m-%d")
    else: # 현재 날짜
        mainTime = datetime.datetime.now()
    ## 날짜별 사용자의 총 섭취 영양소 계산 
    칼로리_list = []; 단백질_list = []; 탄수화물_list = []; 지방_list = []; 나트륨_list = []; 총당류_list = []; 콜레스테롤_list = []; 총포화지방산_list = []; 트랜스지방산_list = [] #html 에 전송할 영양소 정보 리스트
    week_dates = [mainTime-timedelta(6), mainTime-timedelta(5), mainTime-timedelta(4), mainTime-timedelta(3), mainTime-timedelta(2), mainTime-timedelta(1), mainTime]
    for week_date in week_dates:
        week_date = week_date.strftime("%Y-%m-%d")
        에너지=0; 단백질=0; 탄수화물=0; 지방=0; 나트륨=0; 총당류=0; 콜레스테롤=0; 총포화지방산=0; 트랜스지방산=0
        image_file = Foodimage.objects.filter(Q(user_name = request.session['user']) & Q(eatDate=week_date) & Q(isDeleted=0))
        for image in image_file:
            food_list = Foodlist.objects.filter(fileSeq=image.fileSeq)
            for food in food_list:
                nutrition = Nutrition.objects.filter(food_id = food.food_id.food_id)
                섭취량 = nutrition[0].number_1회_제공량_g_field
                에너지 += (float(nutrition[0].에너지_field) * (int(food.food_gram)/int(섭취량))) 
                단백질 += (float(nutrition[0].단백질_g_field) * (int(food.food_gram)/int(섭취량)))
                탄수화물 += (float(nutrition[0].탄수화물_g_field) * (int(food.food_gram)/int(섭취량)))
                지방 += (float(nutrition[0].지방_g_field) * (int(food.food_gram)/int(섭취량)))
                나트륨 += (float(nutrition[0].나트륨_field) * (int(food.food_gram)/int(섭취량)))
                총당류 += (float(nutrition[0].총당류_g_field) * (int(food.food_gram)/int(섭취량)))
                콜레스테롤 += (float(nutrition[0].콜레스테롤_field) * (int(food.food_gram)/int(섭취량)))
                총포화지방산 += (float(nutrition[0].총_포화_지방산_g_field) * (int(food.food_gram)/int(섭취량)))
                트랜스지방산 += (float(nutrition[0].트랜스_지방산_g_field) * (int(food.food_gram)/int(섭취량)))
        # 날짜별로 리스트에 저장
        칼로리_list.append({"date" : week_date, "칼로리" : round(에너지,2)})
        단백질_list.append({"date" : week_date, "단백질" : round(단백질,2)})
        탄수화물_list.append({"date" : week_date, "탄수화물" : round(탄수화물,2)})
        지방_list.append({"date" : week_date, "지방" : round(지방,2)})
        나트륨_list.append({"date" : week_date, "나트륨" : round(나트륨,2)})
        총당류_list.append({"date" : week_date, "총당류" : round(총당류,2)})
        콜레스테롤_list.append({"date" : week_date, "콜레스테롤" : round(콜레스테롤,2)})
        총포화지방산_list.append({"date" : week_date, "총포화지방산" : round(총포화지방산,2)})
        트랜스지방산_list.append({"date" : week_date, "트랜스지방산" : round(트랜스지방산,2)})
    ## 체중별 하루 칼로리 기준 
    user = User.objects.get(user_name=request.session['user'])
    BMI = user.userWeight / ((user.userHeight/100) ** 2) # BMI
    # 과체중 이상 (BMI >= 25 : 과체중, BMI >= 30 비만) 
    if(BMI >= 25): 
        std_kal = user.userWeight * 30 - 250
    # 과체중 이하
    else :
        std_kal = (user.userHeight-100)*0.9 * 30 # 표준체중 (편집됨) 
    # 기준 단백질(g) : 체중(kg)*1.0g / 탄수화물(g) : 칼로리 * 0.55 / 지방(g) : 51 / 나트륨(mg) : 2000 / 총당류(g) : 100 / 콜레스테롤(mg) : 300 / 총포화지방산(g) : 15 / 트랜스지방산(g) : 2 
    std_list = {"base_에너지" : round(std_kal, 2), "base_단백질": round((user.userHeight-100)*0.9*1, 2) ,"base_탄수화물": round(std_kal*0.55/4, 2),"base_지방": 51,"base_나트륨": 2000,"base_총당류": 100, "base_콜레스테롤": 300,"base_총포화지방산": 15,"base_트랜스지방산": 2}
    ## 이상지혈증 (총포화지방산, 지방, 콜레스테롤, 탄수화물)
    if(user.userDysl == 'X'):
        # 총포화지방산
        base_gram_sf  = round((std_kal * 0.07)/9,2)
        if base_gram_sf  < std_list['base_총포화지방산']:
            std_list['base_총포화지방산'] = base_gram_sf 
        else: pass
        # 지방
        base_gram_f = round((std_kal*0.3)/9,2)
        if base_gram_f < std_list['base_지방']:
            std_list['base_지방'] = base_gram_f
        else: pass
        # 콜레스테롤
        if 200 < std_list['base_콜레스테롤']:
            std_list['base_콜레스테롤'] = 200
        else: pass
        # 탄수화물
        base_gram_cy = round((std_kal*0.65)/4,2)
        if base_gram_cy < std_list['base_탄수화물']:
            std_list['base_탄수화물'] = base_gram_cy
        else: pass
    else : pass
    ## 고혈압 (나트륨, 단백질, 콜레스테롤)
    if(user.userHyper == '1' or user.userHyper=='2'):
        # 나트륨
        if 2000 < std_list['base_나트륨']:
            std_list['base_나트륨'] = 2000
        else: pass
        # 단백질
        base_gram_pro = round((std_kal*0.2)/4,2)
        if base_gram_pro < std_list['base_단백질']:
            std_list['base_단백질'] = base_gram_pro
        else : pass
        # 콜레스테롤
        if 300 < std_list['base_콜레스테롤']:
            std_list['base_콜레스테롤'] = 300
        else: pass
    ## 당뇨 (나트륨, 단백질, 총포화지방산, 트랜스지방, 총당류)
    if(user.userDia == '1' or user.userDia=='2'):
        # 나트륨
        if 3000 < std_list['base_나트륨']:
            std_list['base_나트륨'] = 3000
        else: pass
        # 단백질
        base_gram_pro = round((std_kal*0.24)/4,2)
        if base_gram_pro < std_list['base_단백질']:
            std_list['base_단백질'] = base_gram_pro
        else: pass
        # 총포화지방산
        base_gram_sf = round((std_kal*0.1)/9,2)
        if base_gram_sf < std_list['base_총포화지방산']:
            std_list['base_총포화지방산'] = base_gram_sf
        else: pass
        # 트랜스지방
        std_list['base_트랜스지방산'] = 0
        # 총당류
        base_gram_sug = 50
        if base_gram_sug < std_list['base_총당류']:
            std_list['base_총당류'] = base_gram_sug
    contents = {'mainTime' : mainTime.strftime("%Y-%m-%d"), '기준_list' : std_list, '칼로리_list' : 칼로리_list, '단백질_list' : 단백질_list, '탄수화물_list' : 탄수화물_list, 
    '지방_list' : 지방_list, '나트륨_list' : 나트륨_list, '총당류_list':총당류_list, '콜레스테롤_list' : 콜레스테롤_list, '총포화지방산_list' : 총포화지방산_list, '트랜스지방산_list' : 트랜스지방산_list, 'user' : request.session['user']}
    return render(request, 'main/check.html', contents)

def dia_recommend(request):
    return render(request, 'main/diabetes.html')

def hyper_recommend(request):
    return render(request, 'main/hypertension.html')

def recommend(request):
    return render(request, 'main/rec.html')



