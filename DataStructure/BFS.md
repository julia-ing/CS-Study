## BFS
---

### 1. ๊ฐ๋ ๐ฑ

Breadth First Search : ๊ทธ๋ํ ์๋ฃ์์ ๋ฐ์ดํฐ๋ฅผ ํ์ํ  ๋ ๋๋น๋ฅผ ์ฐ์ ํด์ ์ฐพ๋ ๋ฐฉ์. ์์์  ๋ธ๋์ ๊ฐ์ ๊ฑฐ๋ฆฌ์ ์๋ ๋ธ๋๋ฅผ ์ฐ์ ์ผ๋ก ๋ฐฉ๋ฌธํ๋ค.

<๊ณผ์  ๋ฐ ์๊ณ ๋ฆฌ์ฆ>

<img width="715" alt="แแณแแณแแตแซแแฃแบ 2022-05-10 แแฉแแฎ 11 30 56" src="https://user-images.githubusercontent.com/77239220/167653342-3404d3df-81fd-4bbe-bd33-314358fc1193.png">
<img width="712" alt="แแณแแณแแตแซแแฃแบ 2022-05-10 แแฉแแฎ 11 36 05" src="https://user-images.githubusercontent.com/77239220/167654488-d0f69af7-0340-42ca-931f-4d6cb4923607.png">

    1. ํ ์์ฌ์ฝ๋
    DFS(G, v)
        v.visited = true  // v๋ฅผ ๋ฐฉ๋ฌธ๋์๋ค๊ณ  ํ์
        Q.append(v)  // ํ์ ์ ์  v๋ฅผ ์ฝ์
        while Q:  // Q๊ฐ ๊ณต๋ฐฑ์ด ์๋๋ฉด
            Q.pop()  // Q์์ ์ ์  w๋ฅผ ์ ๊ฑฐ
            for all u โ G.Adj[w]  // w์ ์ธ์ ํ ์ ์  u
                if u.visited == false  // u๊ฐ ์์ง ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด
                    Q.append(u)
                    u.visited = true


### 2. ํน์ง ๐ธ

- ํ๋ฅผ ์ฌ์ฉํด ๊ตฌํ๋๋ค.
- sparse graph ์ ๊ฒฝ์ฐ ์ธ์ ๋ฆฌ์คํธ๊ฐ ํจ์จ์ ์ด๋ค.

### 3. ์๊ฐ ๋ณต์ก๋ โฐ

- ์ธ์ ๋ฆฌ์คํธ : O(n+e)
- ์ธ์ ํ๋ ฌ : O(n^2)

### 4. ์ฝ๋ ๐งโ๐ป

- ํ์ด์ฌ
    ```python
    ##########
    # 1. ํ #
    ##########
    from collections import deque

    def bfs_deque(graph, root):
        visited = []
        queue = deque([root]) 
        
        while queue:
            node = queue.popleft()
    
            if node not in visited:  # node๊ฐ ์์ง ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด
                visited.append(node)  # ๋ฐฉ๋ฌธํ๊ณ 
                queue.extend(graph[node])  # node์ ์์ ๋ธ๋๋ค์ ์ถ๊ฐ
                    
        return visited
    ```
