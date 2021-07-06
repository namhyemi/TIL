# 이진 탐색 트리

## 클래스와 함수 선언부
# 이진 트리 노드 생성
class TreeNode():
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None


## 전역 변수
memory = []
root = None
# 데이터 베이스 또는 크롤링으로 얻은 로우 데이터 집합
nameAry = ['블랙핑크','레드벨벳','에이핑크','걸스데이','트와이스','마마무']


# 메인 코드 부분
# 첫번째 노드 생성
node = TreeNode()
name = nameAry[0]
node.data = name
root = node
memory.append(node)

# 이진 탐색 트리 생성
for name in nameAry[1:]:
    node = TreeNode()
    node.data = name
    current = root
    while True:
        if name < current.data:
            if current.left == None:
                current.left = node
                break
            current = current.left
        else:
            if current.right == None:
                current.right = node
                break
            current = current.right
    memory.append(node)


### 데이터 검색
findName = '마마무'
current = root

while True:
    if findName == current.data:
        print(findName + '를 찾았다.')
        break
    elif findName < current.data:
        if current.left == None:
            print('없다.')
            break
        current = current.left
    else:
        if current.right == None:
            print('없다.')
            break
        current = current.right
