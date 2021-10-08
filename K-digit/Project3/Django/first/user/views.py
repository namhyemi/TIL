from django.http.response import HttpResponse
from django.shortcuts import redirect, render
from .models import User
from argon2 import PasswordHasher

# Create your views here.
def home(request):
    return render(request, 'user/landing.html')

def join(request):
    if request.method == 'POST':
        if request.POST['password1'] == request.POST['password2']:
            user = User(
                        user_name=request.POST['username'],
                        user_password=PasswordHasher().hash(request.POST['password1']),
                        userAge=request.POST['userAge'],
                        userWeight=request.POST['userWeight'],
                        userHeight=request.POST['userHeight'],
                        userDia=request.POST['dia'],
                        userHyper=request.POST['hyper'],
                        userDysl=request.POST['dysl'],)
            user.save()
            return redirect('user:login')
        return render(request, 'user/join.html')
    return render(request, 'user/join.html')

def logout(request):
    if request.session['user'] :
        del(request.session['user'])
        return redirect('user:login')
    return redirect('main')

    
def login(request):
    if request.method =='POST' :
        username = request.POST.get('user_name')
        password = request.POST.get('user_password')

        #유효성 처리
        res_data = {}
        if not (username and password):
            res_data['error']='모든 칸을 다 입력해주세요.'
        else:
            try:
                # 기존(DB)에 있는 모델과 같은 값인 걸 가져온다.
                user = User.objects.get(user_name = username) #(필드명 = 값)
                #비밀번호가 맞는지 확인한다.
                try:
                    if PasswordHasher().verify(user.user_password, password):
                    #응갑 데이터 세션에 fuser의 기본키(pk)값인 id 추가. 나중에 쿠키에 저장됨
                        request.session['user'] = user.user_name
                    # return redirect('/')
                        return redirect('main')
                except:
                    res_data['error'] = '비밀번호가 일치하지 않습니다.'
                    return render(request,'user/login.html', res_data)
            except:
                res_data['error'] = "존재하지 않는 사용자입니다."
                return render(request,'user/login.html', res_data)
        return render(request, 'user/login.html', res_data) #응답 데이터 res_data 전달
    else :
        return render(request,'user/login.html')

def information(request):
    return render(request,'user/information.html')

def change(request):
    res_data = {}
    if request.method == "POST":
        username = request.POST['username']
        user = User.objects.get(user_name = username)
        if username == user.user_name: 
            if request.POST['password1'] == request.POST['password2']:
                user.user_password=PasswordHasher().hash(request.POST['password1'])
                user.userAge=request.POST['userAge']
                user.userWeight=request.POST['userWeight']
                user.userHeight=request.POST['userHeight']
                user.userDia=request.POST['dia']
                user.userHyper=request.POST['hyper']
                user.userDysl=request.POST['dysl']
                user.save()
                return redirect('user:logout')
            else:
                res_data = '비밀번호가 일치하지 않습니다.'
                return render(request,'user/change.html', {'user':User.objects.get(user_name = request.session['user']), 'error':res_data})
    else:
        return render(request, 'user/change.html', {'user':User.objects.get(user_name = request.session['user'])})
