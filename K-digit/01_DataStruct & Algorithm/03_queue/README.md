# 선형 자료구조



## 큐 

- 들어가는 입구와 나가는 입구가 다르다 (터널)

- 선입선출(FIFO)

- 큐에 데이터를 추가하는 작동 : enQueue(인큐)

- 데이터를 추출하는 작동 : deQueue(데큐)

- 저장된 데이터 중 첫 번째 데이터 : front(머리)

- 저장된 데이터 중 마지막 데이터 : rear(꼬리)

- front = rear = -1

- 데이터가 크면 오버헤드가 발생함

  

## 원형 큐 

- 큐의 응용
- 큐의 오버헤드 발생 방지
- 원형 큐는 한칸 낭비
- front = rear = 0
- rear+1 과  front가 같은 경우 원형 큐가 꽉 찬 것으로 처리 ((rear+1) % SIZE == front)
