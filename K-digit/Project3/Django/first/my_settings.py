# my_settings.py

DATABASES = {
    'default' : {
        'ENGINE': 'django.db.backends.mysql', #사용할 엔진 설정
        'NAME': 'bpm', #연동할 MySQL 의 데이터 베이스 이름
        'USER': 'bpm', #DB 접속 계정명
        'PASSWORD': '123123', #해당 DB 접속 계정 비밀번호
        'HOST': '15.164.41.157', #실제 DB주소
        'PORT': '3306', #포트번호
    }
}

# DATABASES = {
#     'default' : {
#         'ENGINE': 'django.db.backends.mysql', #사용할 엔진 설정
#         'NAME': 'bpm', #연동할 MySQL 의 데이터 베이스 이름
#         'USER': 'test', #DB 접속 계정명
#         'PASSWORD': '1234', #해당 DB 접속 계정 비밀번호
#         'HOST': 'localhost', #실제 DB주소
#         'PORT': '3306', #포트번호
#     }
# }

# DATABASES = {
#     'default' : {
#         'ENGINE': 'django.db.backends.mysql', #사용할 엔진 설정
#         'NAME': 'bpm', #연동할 MySQL 의 데이터 베이스 이름
#         'USER': 'test', #DB 접속 계정명
#         'PASSWORD': '1234', #해당 DB 접속 계정 비밀번호
#         'HOST': '192.168.56.1', #실제 DB주소
#         'PORT': '3306', #포트번호
#     }
# }