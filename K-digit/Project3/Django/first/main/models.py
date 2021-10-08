from django.db import models
from user.models import User
from django.utils.timezone import now

class Foodimage(models.Model):
    fileSeq = models.AutoField(db_column='fileSeq', primary_key=True)  # Field name made lowercase.
    user_name = models.ForeignKey(User, on_delete=models.CASCADE, db_column='user_name', max_length=50)  # Field name made lowercase.
    foodImg = models.CharField(db_column='foodImg', max_length=250)  # Field name made lowercase.
    eatTime = models.CharField(db_column='eatTime', max_length=10)  # Field name made lowercase.
    eatDate = models.DateField(db_column='eatDate')  # Field name made lowercase.
    isDeleted = models.BooleanField(default=False)

    # class Meta:
    #     managed = False
    #     db_table = 'main_foodimage'

class Nutrition(models.Model):
    food_id = models.BigIntegerField(primary_key=True)
    food_name = models.TextField(blank=True, null=True)
    number_1회_제공량_g_field = models.IntegerField(db_column='1회 제공량(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'. Field renamed because it wasn't a valid Python identifier.
    에너지_field = models.FloatField(db_column='에너지(㎉)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    단백질_g_field = models.FloatField(db_column='단백질(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    지방_g_field = models.FloatField(db_column='지방(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    탄수화물_g_field = models.FloatField(db_column='탄수화물(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    총당류_g_field = models.FloatField(db_column='총당류(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    자당_g_field = models.FloatField(db_column='자당(g)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    포도당_g_field = models.FloatField(db_column='포도당(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    과당_g_field = models.FloatField(db_column='과당(g)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    유당_g_field = models.FloatField(db_column='유당(g)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    맥아당_g_field = models.FloatField(db_column='맥아당(g)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    총_식이섬유_g_field = models.FloatField(db_column='총 식이섬유(g)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    칼슘_mg_field = models.FloatField(db_column='칼슘(mg)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    철_field = models.FloatField(db_column='철(㎎)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    철_field_0 = models.FloatField(db_column='철(㎍)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'. Field renamed because of name conflict.
    마그네슘_field = models.FloatField(db_column='마그네슘(㎎)',  blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    인_field = models.FloatField(db_column='인(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    칼륨_field = models.FloatField(db_column='칼륨(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    나트륨_field = models.FloatField(db_column='나트륨(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    아연_field = models.FloatField(db_column='아연(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    구리_field = models.FloatField(db_column='구리(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    망간_field = models.FloatField(db_column='망간(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    셀레늄_field = models.FloatField(db_column='셀레늄(㎍)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    레티놀_field = models.FloatField(db_column='레티놀(㎍)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    베타카로틴_field = models.FloatField(db_column='베타카로틴(㎍)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    토코페롤_field = models.FloatField(db_column='토코페롤(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    토코트리에놀_field = models.FloatField(db_column='토코트리에놀(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    비타민_b1_field = models.FloatField(db_column='비타민 B1(㎎)', blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    비타민_b2_field = models.FloatField(db_column='비타민 B2(㎎)', blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    나이아신_field = models.FloatField(db_column='나이아신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    엽산_dfe_field = models.FloatField(db_column='엽산(DFE)(㎍)', blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    비타민_b12_field = models.FloatField(db_column='비타민 B12(㎍)', blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    비타민_c_field = models.FloatField(db_column='비타민 C(㎎)', blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    총_아미노산_field = models.FloatField(db_column='총 아미노산(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    이소류신_field = models.FloatField(db_column='이소류신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    류신_field = models.FloatField(db_column='류신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    라이신_field = models.FloatField(db_column='라이신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    메티오닌_field = models.FloatField(db_column='메티오닌(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    페닐알라닌_field = models.FloatField(db_column='페닐알라닌(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    트레오닌_field = models.FloatField(db_column='트레오닌(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    발린_field = models.FloatField(db_column='발린(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    히스티딘_field = models.FloatField(db_column='히스티딘(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    아르기닌_field = models.FloatField(db_column='아르기닌(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    티로신_field = models.FloatField(db_column='티로신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    시스테인_field = models.FloatField(db_column='시스테인(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    알라닌_field = models.FloatField(db_column='알라닌(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    아스파르트산_field = models.FloatField(db_column='아스파르트산(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    글루탐산_field = models.FloatField(db_column='글루탐산(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    글리신_field = models.FloatField(db_column='글리신(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    프롤린_field = models.FloatField(db_column='프롤린(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    세린_field = models.FloatField(db_column='세린(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    콜레스테롤_field = models.FloatField(db_column='콜레스테롤(㎎)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    총_포화_지방산_g_field = models.FloatField(db_column='총 포화 지방산(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    미리스트산_14_0_g_field = models.FloatField(db_column='미리스트산(14:0)(g)',blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    팔미트산_16_0_g_field = models.FloatField(db_column='팔미트산(16:0)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    스테아르산_18_0_g_field = models.FloatField(db_column='스테아르산(18:0)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    아라키드산_20_0_g_field = models.FloatField(db_column='아라키드산(20:0)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    미리스톨레산_14_1_g_field = models.FloatField(db_column='미리스톨레산(14:1)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    팔미톨레산_16_1_g_field = models.FloatField(db_column='팔미톨레산(16:1)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    올레산_18_1_n_9_g_field = models.FloatField(db_column='올레산(18:1(n-9))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    박센산_18_1_n_7_g_field = models.FloatField(db_column='박센산(18:1(n-7))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    가돌레산_20_1_g_field = models.FloatField(db_column='가돌레산(20:1)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    리놀레산_18_2_n_6_c_g_field = models.FloatField(db_column='리놀레산(18:2(n-6)c)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    알파_리놀렌산_18_3_n_3_g_field = models.FloatField(db_column='알파 리놀렌산(18:3(n-3))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    감마_리놀렌산_18_3_n_6_g_field = models.FloatField(db_column='감마 리놀렌산(18:3(n-6))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    에이코사디에노산_20_2_n_6_g_field = models.FloatField(db_column='에이코사디에노산(20:2(n-6))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    에이코사트리에노산_20_3_n_6_g_field = models.FloatField(db_column='에이코사트리에노산(20:3(n-6))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    아라키돈산_20_4_n_6_g_field = models.FloatField(db_column='아라키돈산(20:4(n-6))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    에이코사펜타에노산_20_5_n_3_g_field = models.FloatField(db_column='에이코사펜타에노산(20:5(n-3))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    도코사펜타에노산_22_5_n_3_g_field = models.FloatField(db_column='도코사펜타에노산(22:5(n-3))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    도코사헥사에노산_22_6_n_3_g_field = models.FloatField(db_column='도코사헥사에노산(22:6(n-3))(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    트랜스_지방산_g_field = models.FloatField(db_column='트랜스 지방산(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    트랜스_올레산_18_1_n_9_t_g_field = models.FloatField(db_column='트랜스 올레산(18:1(n-9)t)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    트랜스_리놀레산_18_2t_g_field = models.FloatField(db_column='트랜스 리놀레산 (18:2t)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    트랜스_리놀렌산_18_3t_g_field = models.FloatField(db_column='트랜스 리놀렌산(18:3t)(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
    회분_g_field = models.FloatField(db_column='회분(g)', blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.

    # class Meta:
    #     managed = False
    #     db_table = 'main_nutrition'

class Foodlist(models.Model):
    id = models.BigAutoField(primary_key=True)
    fileSeq = models.ForeignKey(Foodimage, on_delete=models.CASCADE, db_column='fileSeq', blank=True, null=True)  # Field name made lowercase.
    food_id = models.ForeignKey(Nutrition, on_delete=models.CASCADE, db_column='food_id', blank=True, null=True)
    food_gram = models.IntegerField(blank=True, null=True)

    # class Meta:
    #     managed = False
    #     db_table = 'main_foodlist'
