# 원형 큐

## 함수 선언부
# 비어 있는지 확인
def isQueueEmpty():
    global SIZE, queue, rear, front

    if front == rear:
        return True
    else:
        return False


# 자리가 있는지 확인
def isQueueFull():
    global SIZE, queue, rear, front

    if (rear+1) % SIZE == front:
        return True
    else:
        return False


# 데이터 추가
def enQueue(data):
    global SIZE, queue, rear, front

    if isQueueFull():
        print("큐 자리 없음")
        return
    rear = (rear+1) % SIZE
    queue[rear] = data


#데이터 삭제
def deQueue():
    global SIZE, queue, rear, front

    if isQueueEmpty():
        print("큐 비어 있음")
        return
    front = (front+1) % SIZE
    data = queue[front]
    queue[front] = None
    return data


#데이터 확인
def peek():
    global SIZE, queue, rear, front

    if isQueueEmpty():
        print("큐 비어 있음")
        return
    return queue[(front+1)%SIZE]



## 전역 변수부
SIZE = int(input("큐 크기를 입력하세요 --> "))
queue = [None for _ in range(SIZE)]
front = rear = 0



## 메인 코드부
if __name__ == '__main__':
    select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")

    while(select != 'X' and select != 'x'):
        if select == 'I' or select == 'i':
            data = input("입력될 데이터 --> ")
            enQueue(data)
            print("큐 상태", queue)
        elif select == 'E' or select == 'e':
            data = deQueue()
            print("추출된 데이터 --> ", data)
            print("큐 상태", queue)
        elif select == 'V' or select == 'v':
            data = peek()
            print("추출된 데이터 --> ", data)
            print("큐 상태", queue)
        else:
            print("다시 입력해주세요.")

        select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")
    print("프로그램 종료")