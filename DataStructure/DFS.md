## DFS
---

### 1. ๊ฐ๋ ๐ฑ

Depth First Search : ๊ทธ๋ํ ์๋ฃ์์ ๋ฐ์ดํฐ๋ฅผ ํ์ํ  ๋ ์์์ ์๋๋ก ์ฐพ๋ ๋ฐฉ์. ํ ๋ฐฉํฅ์ผ๋ก ๊ฐ ์ ์์ ๋๊น์ง ๊ฐ๋ค๊ฐ ๋ ์ด์ ๊ฐ ์ ์๊ฒ ๋๋ฉด ๊ฐ์ฅ ๊ฐ๊น์ด ๊ฐ๋ฆผ๊ธธ๋ก ๋์์ ๋ค๋ฅธ ๋ฐฉํฅ์ผ๋ก ๋ค์ ํ์ํ๋ค. 

<๊ณผ์  ๋ฐ ์๊ณ ๋ฆฌ์ฆ>

![แแณแแณแแตแซแแฃแบ 2022-03-16 แแฉแแฎ 9 03 06](https://user-images.githubusercontent.com/77239220/158585818-d7337ed2-ceb9-4479-adf7-c512d36b3930.png)

    1. ์ฌ๊ท
    DFS(G, v)
        v.visited = true  // v๋ฅผ ๋ฐฉ๋ฌธ๋์๋ค๊ณ  ํ์
        for each u โ G.Adj[v]  // v์ ์ธ์ ํ ์ ์  u
            if u.visited == false  // u๊ฐ ์์ง ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด
                DFS(G, u)  // u์์๋ถํฐ ๋ค์ DFS ์์

    2. ์คํ
    DFS(G, v)
        S.init()  // ์คํ ์์ฑ
        S.push(v) 
            while (not is_empty(S)) do
                v = S.pop()
                if (v๊ฐ ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด)
                    v๋ฅผ ๋ฐฉ๋ฌธ๋์๋ค๊ณ  ํ์
                    for all u โ (v์ ์ธ์ ํ ์ ์ ) do
                        if (u๊ฐ ์์ง ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด)
                            S.push(u)


### 2. ํน์ง ๐ธ

- ํ์ฌ ๊ฒฝ๋ก์ ๋ธ๋๋ค๋ง ๊ธฐ์ตํ๋ฉด ๋๊ธฐ ๋๋ฌธ์ ์ ์ฅ ๊ณต๊ฐ์ ๋น๊ต์  ์ ๊ฒ ํ์๋ก ํ๋ค.
- ํด๊ฐ ์๋ ๊ฒฝ์ฐ์ ๋น ์ง ์ ์๋ค..
- ํด๋ฅผ ๊ตฌํ๋ฉด ํ์์ด ์ข๋ฃ๋๊ธฐ ๋๋ฌธ์ ๊ตฌํ ํด๊ฐ ์ต๋จ ๊ฒฝ๋ก(์ต์ ํด)๊ฐ ์๋ ์ ์๋ค. 

### 3. ์๊ฐ ๋ณต์ก๋ โฐ

- ์ธ์ ๋ฆฌ์คํธ : O(n+e)
- ์ธ์ ํ๋ ฌ : O(n^2)

### 4. ์ฝ๋ ๐งโ๐ป

- ํ์ด์ฌ
    ```python
    ##########
    # 1. ์ฌ๊ท #
    ##########
    def dfs_recursive(graph, start, visited = []):
        visited.append(start)
    
        for node in graph[start]:
            if node not in visited:
                dfs_recursive(graph, node, visited)
        return visited

    ##########
    # 2. ์คํ #
    ##########
    from collections import deque

    def dfs_deque(graph, start_node):
        visited = []
        need_visited = deque()  # deque์ด list๋ณด๋ค ์ฑ๋ฅ์ด ์ข์
        
        need_visited.append(start_node)
        
        while need_visited:
            node = need_visited.popleft()
    
            if node not in visited:  # node๊ฐ ์์ง ๋ฐฉ๋ฌธ๋์ง ์์์ผ๋ฉด
                visited.append(node)  # ๋ฐฉ๋ฌธํ๊ณ 
                need_visited.extend(reversed(graph[node]))  # node์ ์์ ๋ธ๋๋ค์ ์ถ๊ฐ
                    
        return visited
    ```
