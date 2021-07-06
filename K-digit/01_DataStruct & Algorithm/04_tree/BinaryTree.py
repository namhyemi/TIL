# 이진 트리 순회

## 클래스와 함수 선언부
class TreeNode():
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None

# 전위 순회
def preorder(node):
    if node == None:
        return
    print(node.data, end='->')
    preorder(node.left)
    preorder(node.right)


# 중위 순회
def inorder(node):
    if node == None:
        return
    inorder(node.left)
    print(node.data, end='->')
    inorder(node.right)


# 후위 순회
def postorder(node):
    if node == None:
        return
    postorder(node.left)
    postorder(node.right)
    print(node.data, end='->')


## 전역 변수 부분
node1 = TreeNode()
node1.data = '화사'

node2 = TreeNode()
node2.data = '솔라'
node1.left = node2

node3 = TreeNode()
node3.data = '문별'
node1.right = node3

node4 = TreeNode()
node4.data ='휘인'
node2.left = node4

node5 = TreeNode()
node5.data ='슬기'
node2.right = node5


node6 = TreeNode()
node6.data ='웬디'
node3.left = node6



if __name__ == '__main__':
    print("전위 순회 :", end = ' ')
    preorder(node1)
    print("끝")

    print("중위 순회 :", end = ' ')
    inorder(node1)
    print("끝")

    print("후위 순회 :", end = ' ')
    postorder(node1)
    print("끝")