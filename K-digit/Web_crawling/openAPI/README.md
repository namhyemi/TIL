### 오픈 API 사용하기 



공공데이터포털 https://www.data.go.kr/

 

소상공인 상가업소 정보 서비스 검색  - 소상공인시장진흥공단_상가(상권)정보 클릭 -  활용신청 - 일반 인증키 두개 사용 - smb0.ipynb 열고 api_key 입력

End Point = http://apis.data.go.kr/B553077/api/open/sdsc

End Point 뒤에 원하는 데이터에 따라 메뉴얼 확인 후 작성

api_key = 'R5paJqm2Ehw2tHeFBRXuD62PIxD4Xej%2FgAs7AiQT5dAu0F0o6h%2BAkHW8sLzZ2Bkq9xzdw6mHV6EH9oSTh%2FHfew%3D%3D'



**smb0.ipynb 실행**

#-*- coding:utf-8 -*-
url = 'http://apis.data.go.kr/B553077/api/open/sdsc/storeListInDong?divId=ctprvnCd&key=11&ServiceKey='+api_key+'&type=json'

--> storeListInDong (행정동 단위 상가업소 조회)



다음내용을 주소 창에 검색하면 내용 볼 수 있다.

 http://apis.data.go.kr/B553077/api/open/sdsc/storeListInDong?divId=ctprvnCd&key=11&ServiceKey=R5paJqm2Ehw2tHeFBRXuD62PIxD4Xej%2FgAs7AiQT5dAu0F0o6h%2BAkHW8sLzZ2Bkq9xzdw6mHV6EH9oSTh%2FHfew%3D%3D

---

활용

baroApi 오퍼레이션 사용 예시 (다른 오퍼레이션과의 관계)

③ 사각형내 상권조회(storeZoneInRectangle) 

storeZoneInRectangle 오퍼레이션 사용 **:** 

http://apis.data.go.kr/B553077/api/open/sdsc/storeZoneInRectangle?minx=126.978020&miny=37.557825&maxx=126.987732&maxy=37.562022&ServiceKey=내가 받은 API

baroApi 오퍼레이션 사용 :

http://apis.data.go.kr/B553077/api/open/sdsc/baroApi?resId=storezone&catId=rectangle&minx=126.978020&miny=37.557825&maxx=126.987732&maxy=37.562022&ServiceKey=서비스인증키

---





### 데이터 추출

깔끔하게 출력하기 위해서

url = 'http://apis.data.go.kr/B553077/api/open/sdsc/storeListInDong?divId=ctprvnCd&key=11&ServiceKey='+api_key+'&**type=json**

response = urllib.request.urlopen(url)

response

json_str = response.read().decode("utf-8")

import json
json_object = json.loads(json_str)

json_object

그대로 출력하면 복잡함

.

원하는 내용만 추출해서

데이터 프레임 변형시키고으로 **파일 저장**하기

import pandas as pd
from pandas.io.json import json_normalize

body = [json_object['body'] ['items']]] --> type(body) 는 리스트

df = pd.DataFrame(body)

df.to_csv('smb.csv') 



사용하기 위해서는 메뉴얼을 꼭 참조해야한다.

