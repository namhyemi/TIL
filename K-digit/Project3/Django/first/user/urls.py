from django.urls import path
from . import views

app_name = 'user'

urlpatterns = [
    path('', views.home, name='home'),
    path('join', views.join, name='join'),
    path('login', views.login, name='login'),
    path('logout', views.logout, name='logout'),
    path('information', views.information, name='information'),
    path('change', views.change, name='change'),
]