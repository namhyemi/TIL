# 스택

# 함수 선언부
# 스택 가득 찼는지 확인 (overflow)
def isStackFull():
    global SIZE, stack, top

    if top >= SIZE-1:
        return True
    else:
        return False


# 스택 비어있는지 확인 (underflow)
def isStackEmpty():
    global SIZE, stack, top

    if top == -1:
        return True
    return False


# 데이터 추가
def push(data):
    global SIZE, top, stack
    if(isStackFull()):
        print("스택 자리 없음")
        return
    top += 1
    stack[top] = data


# 데이터 추출
def pop():
    global SIZE, top, stack

    if(isStackEmpty()):
        print("스택 비어 있음")
        return
    data = stack[top]
    stack[top] = None
    top -= 1
    return data


# 데이터 확인
def peek():
    global SIZE, top, stack

    if(isStackEmpty()):
        print("스택이 비어있습니다.")
        return None
    return stack[top]


# 전역 변수부
SIZE = int(input("스택 크기를 입력하세요 --> "))
stack = [None for _ in range(SIZE)]
top = -1


# 메인 코드부
if __name__ =='__main__':

    select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")

    while(select != 'X' and select != 'x'):
        if select == 'I' or select == 'i':
            data = input("입력될 데이터 --> ")
            push(data)
            print("스택 상태", stack)
        elif select == 'E' or select == 'e':
            data = pop()
            print("추출된 데이터 --> ", data)
            print("스택 상태", stack)
        elif select == 'V' or select == 'v':
            data = peek()
            print("추출된 데이터 --> ", data)
            print("스택 상태", stack)
        else:
            print("다시 입력해주세요.")

        select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")
    print("프로그램 종료")