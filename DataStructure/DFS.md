## DFS
---

### 1. 개념 🌱

Depth First Search : 그래프 자료에서 데이터를 탐색할 때 위에서 아래로 찾는 방식. 한 방향으로 갈 수 있을 때까지 가다가 더 이상 갈 수 없게 되면 가장 가까운 갈림길로 돌아와 다른 방향으로 다시 탐색한다. 

<과정 및 알고리즘>

![스크린샷 2022-03-16 오후 9 03 06](https://user-images.githubusercontent.com/77239220/158585818-d7337ed2-ceb9-4479-adf7-c512d36b3930.png)

    1. 재귀
    DFS(G, v)
        v.visited = true  // v를 방문되었다고 표시
        for each u ∈ G.Adj[v]  // v에 인접한 정점 u
            if u.visited == false  // u가 아직 방문되지 않았으면
                DFS(G, u)  // u에서부터 다시 DFS 시작

    2. 스택
    DFS(G, v)
        S.init()  // 스택 생성
        S.push(v) 
            while (not is_empty(S)) do
                v = S.pop()
                if (v가 방문되지 않았으면)
                    v를 방문되었다고 표시
                    for all u ∈ (v에 인접한 정접) do
                        if (u가 아직 방문되지 않았으면)
                            S.push(u)


### 2. 특징 🌸

- 현재 경로의 노드들만 기억하면 되기 때문에 저장 공간을 비교적 적게 필요로 한다.
- 해가 없는 경우에 빠질 수 있다..
- 해를 구하면 탐색이 종료되기 때문에 구한 해가 최단 경로(최적해)가 아닐 수 있다. 

### 3. 시간 복잡도 ⏰

- 인접리스트 : O(n+e)
- 인접행렬 : O(n^2)

### 4. 코드 🧑‍💻

- 파이썬
    ```python
    ##########
    # 1. 재귀 #
    ##########
    def dfs_recursive(graph, start, visited = []):
        visited.append(start)
    
        for node in graph[start]:
            if node not in visited:
                dfs_recursive(graph, node, visited)
        return visited

    ##########
    # 2. 스택 #
    ##########
    from collections import deque

    def dfs_deque(graph, start_node):
        visited = []
        need_visited = deque()  # deque이 list보다 성능이 좋음
        
        need_visited.append(start_node)
        
        while need_visited:
            node = need_visited.popleft()
    
            if node not in visited:  # node가 아직 방문되지 않았으면
                visited.append(node)  # 방문하고
                need_visited.extend(reversed(graph[node]))  # node의 자식 노드들을 추가
                    
        return visited
    ```
