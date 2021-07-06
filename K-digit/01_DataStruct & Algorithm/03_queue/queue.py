## 큐

## 함수 선언부
# 비었는지 확인
def isQueueEmpty():
    global SIZE, queue, front, rear

    if rear == front:
        return True
    else:
        return False


# 가득 차있는지 확인
def isQueueFull():
    global SIZE, queue, front, rear

    if rear != SIZE-1:
        return False
    elif rear == SIZE-1 and front == -1:
        return True
    else:
        for i in range(front+1, SIZE):
            queue[i-1] = queue[i]
            queue[i] = None
        front -= 1
        rear -= 1
        return False

# 데이터 추가
def enQueue(data):
    global SIZE, queue, front, rear

    if(isQueueFull()):
        print("자리 없음")
        return
    rear += 1
    queue[rear] = data


# 데이터 추출
def deQueue():
    global SIZE, queue, front, rear
    if(isQueueEmpty()):
        print("비어 있음")
        return None
    front += 1
    data = queue[front]
    queue[front] = None
    return data


# 데이터 확인
def peek():
    global SIZE, queue, front, rear
    if(isQueueEmpty()):
        print("큐가 비었습니다.")
        return None
    return queue[front+1]


## 전역 변수부
SIZE = int(input("큐 크기를 입력해주세요 --> "))
queue = [None for _ in range(SIZE)]
front = rear = -1


## 메인 코드부
if __name__ == '__main__':

    select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")

    while(select != 'x' and select !='X'):
        if select == 'I' or select == 'i':
            data = input("입력될 데이터 --> ")
            enQueue(data)
            print(queue)
        elif select == 'E' or select == 'e':
            data = deQueue()
            print("추출된 데이터 --> ", data)
            print("스택 상태", queue)
        elif select == 'V' or select == 'v':
            data = peek()
            print("추출된 데이터 --> ", data)
            print("스택 상태", queue)
        else:
            print("다시 입력해주세요")

        select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")
    print("프로그램 종료")