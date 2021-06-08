# Pandas

21-06-08

- series 와 dataFrame



1. 0-Pandas.ipynb

   dictionary : key 와 value

## series 

- series : 1차원 데이터 구조 
  - s = pd.Series()
  - 순서가 존재한다.  (그래서 key 가 아닌 index 라고 부른다.)
  - 인덱스 : 숫자(순서)뿐만 아니라 문자열도 가능 (s[숫자], s['index'])
  - 파이썬 딕셔너리로 생성 가능 {'one' : 1, 'two':2, 'three':3}
  - 연산 가능 (index 기반)
  - 

## dataFrame

- dataFrame : 2차원 데이터 구조(엑셀)
  - df = pd.DataFrame()
  - series가 합쳐진 상태(하나의 열은 series 타입)
  - table 형태 (column 과 index)
  - 중첩 리스트와 딕셔너리로 생성 가능 ([[리스트],[리스트],[리스트]])
  - 속성 : index, columns, values, dtype(각 행별 타입), info()
  - index 만으로는 검색 불가능
  - 여러개의 index를 가질 수 있다
  - 연산가능

``` python
df_index_with_country_and_capital = df.set_index(['Country', 'Capital'])
```

```python
df_index_with_country_and_capital.loc[['Belgium', 'Brusseles']]
```



## pandas Importing/Exproting

: csv(모든 text파일 연결에 사용), excel, sql(모든 데이터베이스 연결), hdf5, json, html, pickle, ...



### csv 

- importing

  - ```python
    df_iris_sample = pd.read_csv('iris_sample.csv')
    ```

- exporting

  - ```python
    df_iris_sample_2.to_csv('iris_sample_2.csv')
    ```

  - ```python
    df_iris_sample_2.to_csv('iris_sample_2_no_index.csv', index=False)
    ```

  - to_csv() 시 index 도 함께 파일에 저장되는 문제는 index = False 로 해결할 수 있다.



## indexing / slicing

- [] 연산자를 사용하면 원하는 데이터를 가져올 수 있다.
- [] 사용한 슬라이싱은 row에 적용된다. 
- [] 인자를 위치로하면 마지막 index 제외하지만, 라벨 사용시 포함되어 출력 (시작, 마지막은 통일)



### indexing 

- loc (Label based indexing)
- iloc (Positional indexing)
- ix (사용 권장 X)

```python
df.loc[0, 'Country'] # 라벨을 통한 인덱싱
```

```python
df.iloc[0,0] # 위치를 통한 인덱싱
```

### slicing

``` python
df.loc[0:1, 'Country':'Capital'] # 라벨을 통한 슬라이싱 (끝 포함)
```

``` python
df.iloc[0:1,0:2] # 위치를 통한 슬라이싱 (끝은 미포함)
```



### filtering

조건을 제시하고 조건이 True 인 요소만 조회하는 방식

``` python
df[df['Population'] > 200000000] 
```



## 삭제

1. row 삭제 (axis = 0)

``` python
df.drop(1) # 단일 Row 삭제
```

``` python
df.drop([0,1]) # 복수 Row 삭제
```

2. column 삭제(axis = 1)

``` python
df.drop('Country', axis=1)
```

```python
df.drop(['Country', 'Population'], axis=1)
```



## 함수

1. 탐색 함수

   - describe() : 숫자 열에만 적용, 통계값, 최대값, 최소값 출력
   - head(n) : 초반n행 출력 (기본 5행 출력)
   - sort_values() : 오름차순 정렬 (ascending = False : 내림차순)
   - isnull() : null값이 있는지 확인(.any(axis=0) : column별로 출력)

   ```python
   df.isnull().any().any() #DataFrame 내에 하나라도 있는지 확인 (True/False 로 결과 출력) 
   ```

   - copy() : 복사

2.  aggregate 함수 (column 기준)

   - count() 
   - sum()
   - min()
   - max()
   - mean() : 평균값
   - median()  : 중간값

3. apply 함수
   - 요소별로 적용된다.

```python
df.loc[:, 'Population':'Population'].apply(lambda x: x + 1)
```

```python
df.loc[:, 'Country':'Capital'].apply(lambda x: x['Country'] + "'s capital is " + x['Capital'], axis=1)
```

```python
df.loc[:, 'Country':'Capital'].apply(lambda x: x[0] + "'s capital is " + x[1], axis=1)
```



### Group By 



- Split-Apply-Combine (key값에 따라 나눠 함수 적용 후 다시 합친다.)
- SQL 과 유사하다.

```python
df[df['key'] == "A"].sum()
df[df['key'] == "B"].sum() 
df[df['key'] == "C"].sum()
```

```python
df.groupby('key').sum()
```







