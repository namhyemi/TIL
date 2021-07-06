# 음료수 얼려 먹기 : DFS

# N, M을 공백을 기준으로 구분하여 입력 받기
n, m = map(int, input("행과 열을 입력하세요 : ").split())

# 2차원 리스트의 맵 정보 입력 받기
graph = []
for i in range(n):
    graph.append(list(map(int,input("{}행을 입력하세요(0과1) : ".format(i+1)))))


# DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
def dfs(index, column):
    # 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (index >= n) or (column >= m) or (index <= -1) or (column <= -1):
        return False

    # 현재 노드를 아직 방문하지 않았다면
    if graph[index][column] == 0:
        # 해당 노드 방문 처리
        graph[index][column] = 1
        # 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
        dfs(index+1,column)
        dfs(index,column+1)
        dfs(index-1,column)
        dfs(index,column-1)
        return True
    return False


result = 0

# 모든 노드(위치)에 대하여 음료수 채우기
for i in range(n):
    for j in range(m):
        # 현재 위치에서 DFS 수행
        if dfs(i,j) == True:
            result += 1

print("얼음의 개수는 {}개 입니다.".format(result))