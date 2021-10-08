from django.db import models

# Create your models here.
class User(models.Model):
    user_name = models.CharField(max_length=20, primary_key=True)
    user_password = models.CharField(max_length=100)
    userAge = models.IntegerField(default=0)
    userWeight = models.IntegerField(default=0)
    userHeight = models.IntegerField(default=0)
    userDia = models.CharField(max_length=3, default="X")
    userHyper = models.CharField(max_length=3, default="X")
    userDysl = models.CharField(max_length=3, default="X")

    # class Meta:
    #     managed = False
    #     db_table = 'user_user'

# class Nutrition(models.Model):
#     food_id = models.IntegerField(primary_key=True)
#     food_name = models.CharField(max_length=15)
#     number_1회_제공량_g_field = models.CharField(db_column='1회 제공량(g)', max_length=15)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'. Field renamed because it wasn't a valid Python identifier.
#     에너지_field = models.CharField(db_column='에너지(㎉)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     단백질_g_field = models.CharField(db_column='단백질(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     지방_g_field = models.CharField(db_column='지방(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     탄수화물_g_field = models.CharField(db_column='탄수화물(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     총당류_g_field = models.CharField(db_column='총당류(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     자당_g_field = models.CharField(db_column='자당(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     포도당_g_field = models.CharField(db_column='포도당(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     과당_g_field = models.CharField(db_column='과당(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     유당_g_field = models.CharField(db_column='유당(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     맥아당_g_field = models.CharField(db_column='맥아당(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     총_식이섬유_g_field = models.CharField(db_column='총 식이섬유(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     캄슘_mg_field = models.CharField(db_column='캄슘(mg)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     철_field = models.CharField(db_column='철(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     철_field_0 = models.CharField(db_column='철(㎍)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'. Field renamed because of name conflict.
#     마그네슘_field = models.CharField(db_column='마그네슘(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     인_field = models.CharField(db_column='인(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     칼륨_field = models.CharField(db_column='칼륨(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     나트륨_field = models.CharField(db_column='나트륨(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     아연_field = models.CharField(db_column='아연(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     구리_field = models.CharField(db_column='구리(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     망간_field = models.CharField(db_column='망간(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     셀레늄_field = models.CharField(db_column='셀레늄(㎍)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     레티놀_field = models.CharField(db_column='레티놀(㎍)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     베타카로틴_field = models.CharField(db_column='베타카로틴(㎍)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     토코페롤_field = models.CharField(db_column='토코페롤(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     토코트리에놀_field = models.CharField(db_column='토코트리에놀(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     비타민_b1_field = models.CharField(db_column='비타민 B1(㎎)', max_length=15, blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     비타민_b2_field = models.CharField(db_column='비타민 B2(㎎)', max_length=15, blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     나이아신_field = models.CharField(db_column='나이아신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     엽산_dfe_field = models.CharField(db_column='엽산(DFE)(㎍)', max_length=15, blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     비타민_b12_field = models.CharField(db_column='비타민 B12(㎍)', max_length=15, blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     비타민_c_field = models.CharField(db_column='비타민 C(㎎)', max_length=15, blank=True, null=True)  # Field name made lowercase. Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     총_아미노산_field = models.CharField(db_column='총 아미노산(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     이소류신_field = models.CharField(db_column='이소류신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     류신_field = models.CharField(db_column='류신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     라이신_field = models.CharField(db_column='라이신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     메티오닌_field = models.CharField(db_column='메티오닌(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     페닐알라닌_field = models.CharField(db_column='페닐알라닌(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     트레오닌_field = models.CharField(db_column='트레오닌(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     발린_field = models.CharField(db_column='발린(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     히스티딘_field = models.CharField(db_column='히스티딘(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     아르기닌_field = models.CharField(db_column='아르기닌(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     티로신_field = models.CharField(db_column='티로신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     시스테인_field = models.CharField(db_column='시스테인(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     알라닌_field = models.CharField(db_column='알라닌(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     아스파르트산_field = models.CharField(db_column='아스파르트산(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     글루탐산_field = models.CharField(db_column='글루탐산(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     글리신_field = models.CharField(db_column='글리신(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     프롤린_field = models.CharField(db_column='프롤린(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     세린_field = models.CharField(db_column='세린(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     콜레스테롤_field = models.CharField(db_column='콜레스테롤(㎎)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     총_포화_지방산_g_field = models.CharField(db_column='총 포화 지방산(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     미리스트산_14_0_g_field = models.CharField(db_column='미리스트산(14:0)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     팔미트산_16_0_g_field = models.CharField(db_column='팔미트산(16:0)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     스테아르산_18_0_g_field = models.CharField(db_column='스테아르산(18:0)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     아라키드산_20_0_g_field = models.CharField(db_column='아라키드산(20:0)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     미리스톨레산_14_1_g_field = models.CharField(db_column='미리스톨레산(14:1)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     팔미톨레산_16_1_g_field = models.CharField(db_column='팔미톨레산(16:1)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     올레산_18_1_n_9_g_field = models.CharField(db_column='올레산(18:1(n-9))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     박센산_18_1_n_7_g_field = models.CharField(db_column='박센산(18:1(n-7))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     가돌레산_20_1_g_field = models.CharField(db_column='가돌레산(20:1)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     리놀레산_18_2_n_6_c_g_field = models.CharField(db_column='리놀레산(18:2(n-6)c)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     알파_리놀렌산_18_3_n_3_g_field = models.CharField(db_column='알파 리놀렌산(18:3(n-3))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     감마_리놀렌산_18_3_n_6_g_field = models.CharField(db_column='감마 리놀렌산(18:3(n-6))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     에이코사디에노산_20_2_n_6_g_field = models.CharField(db_column='에이코사디에노산(20:2(n-6))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     에이코사트리에노산_20_3_n_6_g_field = models.CharField(db_column='에이코사트리에노산(20:3(n-6))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     아라키돈산_20_4_n_6_g_field = models.CharField(db_column='아라키돈산(20:4(n-6))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     에이코사펜타에노산_20_5_n_3_g_field = models.CharField(db_column='에이코사펜타에노산(20:5(n-3))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     도코사펜타에노산_22_5_n_3_g_field = models.CharField(db_column='도코사펜타에노산(22:5(n-3))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     도코사헥사에노산_22_6_n_3_g_field = models.CharField(db_column='도코사헥사에노산(22:6(n-3))(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     트랜스_지방산_g_field = models.CharField(db_column='트랜스 지방산(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     트랜스_올레산_18_1_n_9_t_g_field = models.CharField(db_column='트랜스 올레산(18:1(n-9)t)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     트랜스_리놀레산_18_2t_g_field = models.CharField(db_column='트랜스 리놀레산 (18:2t)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     트랜스_리놀렌산_18_3t_g_field = models.CharField(db_column='트랜스 리놀렌산(18:3t)(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.
#     회분_g_field = models.CharField(db_column='회분(g)', max_length=15, blank=True, null=True)  # Field renamed to remove unsuitable characters. Field renamed because it ended with '_'.


# class CameraFoodimage(models.Model):
#     fileseq = models.AutoField(db_column='fileSeq', primary_key=True)  # Field name made lowercase.
#     foodimg = models.CharField(db_column='foodImg', max_length=100)  # Field name made lowercase.
#     created_at = models.DateTimeField()
#     eattime = models.CharField(db_column='eatTime', max_length=10)  # Field name made lowercase.
#     userid = models.ForeignKey("User", on_delete=models.CASCADE, db_column='userId', max_length=50)  # Field name made lowercase.


# class CameraFoodlist(models.Model):
#     id = models.BigAutoField(primary_key=True)
#     fileseq = models.ForeignKey("CameraFoodimage", on_delete=models.CASCADE, db_column='fileSeq')  # Field name made lowercase.
#     foodid = models.ForeignKey("Nutrition", on_delete=models.CASCADE, db_column='foodId')  # Field name made lowercase.
