from django.urls import path
from . import views

# app_name = 'main'

urlpatterns = [
    path('', views.main, name="main"),
    path('upload', views.upload, name='upload'),
    path('warning', views.warning, name='warning'),
    path('check', views.check, name='check'),
    path('delete', views.delete, name='delete'),
    path('dia_recommend', views.dia_recommend, name='dia_recommend'),
    path('hyper_recommend', views.hyper_recommend, name='hyper_recommend'),
    path('recommend', views.recommend, name='recommend'),
]
