# Django 

django 가상환경 구축과 Tutorial 중심



### conda env for Django

- conda deactivate
- conda create --name django python=3.8.3
- conda env list
- pip install ipykernel
- pip liste
- python -m ipykernel install --user --name django --display-name "Python Django"
- conda install -c conda-forge jupyterlab
- pip install Django==3.2.4
- python -m django --version
- (conda remove --name django --all)



- django-admin startproject mysite #디렉토리 생성

- python manage.py runserver

- http://127.0.0.1:8000/ 

  

- VSCode 에서 conda 실행 안될 시 시스템 환경 변수 추가

  - \anaconda3
  - \anaconda3\Library\bin
  - \anaconda3\Library\usr\bin
  - \anaconda3\Library\mingw-w64\bin



### 프로젝트 만들기 

- python manage.py startapp polls  #polls 디렉토리 생성



### MySQL 연동

- mysite/settings.py

```
DATABASES = {
	'default':{
		'ENGINE':'django.db.backends.mysql',
		'NAME':'tip',
		'USER':'root',
		'PASSWORD':'비밀번호',
		'HOST':'localhost',
		'PORT':'3306',
     }
}

```

- pip install mysqlclient

  (MySQL installer - MySQL Server : reconfigure)

- python manage.py migrate



### 관리자 생성

- python manage.py createsuperuser 
  - Username : admi





**참고 사이트**

https://docs.djangoproject.com/ko/3.2/