## 두 배열의 원소 교체

N,K =input("N(1<=N<=100,000),K(0<=K<=N)를 입력하세요(띄어쓰기 구분) : ").split(" ")

A = list(map(int, input("A를 입력하세요 : ").split(" ")))
B = list(map(int, input("B를 입력하세요 : ").split(" ")))

A.sort()
B.sort(reverse=True)

#첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 K번 비교
for i in range(int(K)):
    if A[i] < B[i]:
        A[i], B[i] = B[i], A[i]
    else:
        break

print(sum(A))

