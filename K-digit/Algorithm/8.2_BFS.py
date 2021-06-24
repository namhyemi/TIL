# Breath-First Search (너비 우선 탐색)

from collections import deque

# BFS 메서드 정의
def bfs(graph, start, visited):
    # 큐(Queue) 구현을 위해 deque 라이브러리 사용
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited[start] = True
    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력하기
        i = queue.popleft()
        print(i, end=' ')
        # 아직 방문하지 않은 인접한 원소들을 큐에 삽입
        for v in graph[i]:
            if not visited[v]:
                queue.append(v)
                visited[v] = True


graph = [
    [],
    [2,3,8], #1번 노드와 연결된 노드
    [1,7],
    [1,4,5],
    [3,5,],
    [3,4,],
    [7],
    [2,6,8],
    [1,7] #8번 노드와 연결된 노드
]

# 각 노드가 방문된 정보를 표현 (1차원 리스트)
visited = [False]*9 #인덱스 0은 사용 안함

# 정의된 DFS 함수 호출
bfs(graph, 1, visited)