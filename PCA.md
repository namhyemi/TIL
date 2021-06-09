## PCA (Principal Component Analysis)

: Big_Data_Analysis - feature_selection - credit_cards/Data_USD.csv (github)

: Big_Data_Analysis - feature_selection  - XGBoost_System.pdf / xgboost_pdp_ice.ipynb (github)

: uci credit cards (kaggle)



![image-20210609091544161](PCA.assets/image-20210609091544161.png)



- - 







**[Covariance Matrix]**

![image-20210609153106736](PCA.assets/image-20210609153106736.png)



- TP : 실제 True인 정답을 True 라고 예측 (정답)
- FP : 실제 False인 정답을 True라고 예측 (오답) 
- FN : 실제 True인 정답을 False라고 예측 (오답)
- TP : 실제 False인 정답을 False 라고 예측 (정답)



- recall(재현율) : 조금의 불량품 찾기 위함(얼마나 못맞췄나), 실제 True 인데 False로 라벨링 한 것에 민감하게 반응
  - TP / (TP +FN) 
- precision(정밀도) 
  - TP / (TP + FP) : Positive 정답률(얼마나 맞췄나), 실제 False 이지만 True로 라벨링 한 것에 민감하게 반응
- accuracy(정확도)
  - (TN+TP) / (TN+FP+FN+TP)



- degree of freedom 
  - 통제된 변수를 제외한 변수의 개수
  - 주어진 조건하에 통제적 제한 받지 않고 자유롭게 변화될 수 있는 요소의 수 (n-1)





- 차원의 저주
  - 데이터 학습을 위해 차원이 증가하면서 학습데이터 수가 차원의 수보다 적어져 성능이 저하되는 현상
  - 차원이 증가할 수록 개별 차원 내 학습할 데이터 수가 적어지는(space) 현상 발생
  - 주로 시각화를 위해서 차원 축소
  - 차원을 축소하거나 데이터를 많이 획득하는 것으로 해결

![image-20210609155745473](PCA.assets/image-20210609155745473.png)


- 다중공선성(Multicolinearity)
  - 일치에 가까울 정도로 관련성(상관관계)가 높은 경우 분산교란을 일으킨다.
  - 독립변수들 사이에 높은 상관성을 보여주는 경우 문제가 발생하게 된다.
  - 이를 해결하기 위해 통합 또는 평균, 선택을 하여 차원 축소를 한다.





