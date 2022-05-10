## BFS
---

### 1. 개념 🌱

Breadth First Search : 그래프 자료에서 데이터를 탐색할 때 너비를 우선해서 찾는 방식. 시작점 노드와 같은 거리에 있는 노드를 우선으로 방문한다.

<과정 및 알고리즘>

<img width="715" alt="스크린샷 2022-05-10 오후 11 30 56" src="https://user-images.githubusercontent.com/77239220/167653342-3404d3df-81fd-4bbe-bd33-314358fc1193.png">
<img width="712" alt="스크린샷 2022-05-10 오후 11 36 05" src="https://user-images.githubusercontent.com/77239220/167654488-d0f69af7-0340-42ca-931f-4d6cb4923607.png">

    1. 큐 의사코드
    DFS(G, v)
        v.visited = true  // v를 방문되었다고 표시
        Q.append(v)  // 큐에 정점 v를 삽입
        while Q:  // Q가 공백이 아니면
            Q.pop()  // Q에서 정점 w를 제거
            for all u ∈ G.Adj[w]  // w에 인접한 정점 u
                if u.visited == false  // u가 아직 방문되지 않았으면
                    Q.append(u)
                    u.visited = true


### 2. 특징 🌸

- 큐를 사용해 구현된다.
- sparse graph 의 경우 인접리스트가 효율적이다.

### 3. 시간 복잡도 ⏰

- 인접리스트 : O(n+e)
- 인접행렬 : O(n^2)

### 4. 코드 🧑‍💻

- 파이썬
    ```python
    ##########
    # 1. 큐 #
    ##########
    from collections import deque

    def bfs_deque(graph, root):
        visited = []
        queue = deque([root]) 
        
        while queue:
            node = queue.popleft()
    
            if node not in visited:  # node가 아직 방문되지 않았으면
                visited.append(node)  # 방문하고
                queue.extend(graph[node])  # node의 자식 노드들을 추가
                    
        return visited
    ```
