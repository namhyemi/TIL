# 미로 최단 거리 탈출

from collections import deque

# N, M을 공백을 기준으로 구분하여 입력 받기
n, m = map(int, input("행과 열을 입력하세요(0과 1) : ").split())

graph = []
# 2차원 리스트의 맵 정보 입력 받기
for i in range(n):
    graph.append(list(map(int, input("{}행을 입력하세요 : ".format(i+1)))))


def bfs(x, y):

    queue = deque()
    queue.append((x, y))

    while queue:

        x, y = queue.popleft()

        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]

            # 미로 찾기 공간을 벗어난 경우 무시
            if (x >= n) or (y >= m) or (x <= -1) or (y <= -1):
                continue

            # 벽인 경우 무시
            if graph[x][y] > 0:
                continue

            # 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx,ny))

    # 가장 오른쪽 아래까지의 최단 거리 반환
    return graph[n-1][m-1]


# 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
dx = [-1,1,0,0]
dy = [0,0,-1,1]

print(bfs(0,0))



'''
min_count = 1000000
count = 0

def dfs(a,b,count):
    global min_count

    if a >= n or b >= m or a <= -1 or b <= -1:
        return 100000

    if a == n-1 and b == m-1 :
        return count

    if graph[a][b] == 1:
        count += 1
        # temp = dfs(a-1,b,count)
        # if min_count > temp:
        #     min_count = temp
        # temp = dfs(a,b-1,count)
        # if min_count > temp:
        #     min_count = temp
        temp = dfs(a+1,b,count)
        if min_count > temp:
            min_count = temp
        temp = dfs(a,b+1,count)
        if min_count > temp:
            min_count = temp

    return 100000

dfs(0,0,count)

print(min_count)
'''