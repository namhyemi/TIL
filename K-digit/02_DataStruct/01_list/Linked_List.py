# 연결 리스트

## 클래스와 함수 선언 부분
class Node():
    def __init__(self):
        self.data = None
        self.link = None

# 노드 추가 함수
def insertNode(findData, insertData):
    global memory, head, current, pre

    # 처음 위치 노드 추가
    if head.data == findData:
        node = Node()
        node.data = insertData
        node.link = head
        head = node
        return

    # 중간 위치 노드 추가
    current = head
    while current.link != None:
        pre = current
        current = current.link
        if current.data == insertData:
            node = Node()
            node.data = insertData
            node.link = current
            pre.link = node
            return

    # 마지막 위치 노드 추가
    node = Node()
    node.data = insertData
    current.link = node


# 노드 삭제 함수
def deleteNode(deleteData):
    global memory, pre, current, head

    if head.data == deleteData:
        current = head
        head = head.link
        del(current)
        return

    current = head
    while current.link != None:
        pre = current
        current = current.link

        if current.data == deleteData:
            pre.link = current.link
            del(current)
            return


# 노드 출력 함수
def printNode(start):
    current = start
    if current == None:
        return
    print(current.data, end=' ')

    while (current.link != None):
        current = current.link
        print(current.data, end=' ')
    print()


# 전역 변수
memory = []
head, pre, current = None, None, None
# dataArray = ['다현', '정연', '쯔위', '사나', '지효'] # DB, 크롤링...

from random import randint
dataArray = [randint(100,1000) for _ in range(20)]


# 메인 코드
if __name__ == '__main__':  # C, Java, C++, C# --> main() 함수
    node = Node()
    node.data = dataArray[0]
    head = node
    memory.append(node)

    for data in dataArray[1:]:  # ['정연', '쯔위', '사나', '지효']
        pre = node
        node = Node()
        node.data = data  # 정연, 쯔위 ...
        pre.link = node
        memory.append(node)

    printNode(head)
