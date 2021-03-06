## 다익스트라 알고리즘
---

### 1. 개념 🌱

어느 한 출발점에서 또 다른 도착점까지의 최단 경로를 찾는 알고리즘

**주어진 출발점에서 시작하여 출발점으로부터 최단 거리가 확정되지 않은 점들 중 출발점으로부터 가장 가까운 점을 추가하고 그 점의 최단 거리를 확정짓는 방식**

<img width="306" alt="스크린샷 2022-04-06 오후 10 36 15" src="https://user-images.githubusercontent.com/77239220/161987316-177c1f38-687f-4849-bdd7-3c2ad55cf723.png">

<과정 및 알고리즘>


    ShortestPath(G, s)
    1. 배열 D(출발점 s로부터 점들까지 각각의 최단 거리를 저장할 배열)를 무한으로 초기화, D[s] = 0
    2. while (s로부터의 최단 거리가 확정되지 않은 점이 존재하면) {
            현재까지 최단 거리가 확정되지 않은 각 점 v에 대해 최소의 D[v]의 값을 가진 점 vMin을 선택하고 s로부터 점 vMin까지의 최단 거리 D[vMin] 확정

            s로부터 현재보다 짧은 거리로 점 vMin을 통해 우회 가능한 각 점 w에 대해 D[w] 갱신  // 간선 완화
        }
    3. return D


### 2. 특징 🌸

- 프림 알고리즘과 공통점 : 한 정점에서 출발한다.
- 차이점 : 프림은 다익스트라와 달리 두 노드 사이가 최단거리가 아닐 수도 있고 무방향 그래프에만 적용되는 반면, 다익스트라는 유향 그래프에도 적용 가능하다.

<img width="805" alt="스크린샷 2022-04-06 오후 10 47 27" src="https://user-images.githubusercontent.com/77239220/161989536-ea029ce1-4c67-484b-8e03-d2b18b2193d7.png">

### 3. 시간 복잡도 ⏰

- while 반복문이 (n-1)회 시행되는데, 1회마다 vMin을 찾는 데에 O(n), vMin에 연결된 점의 수가 최대 (n-1)개 이므로 D[w] 갱신에 O(n)

-> (n-1) * (O(n)+ O(n)) = **O(n^2)**

<참고> - 프림 알고리즘처럼, 배열이 아닌 최소 힙(Binary Heap) 구조를 사용하여 vMin 을 찾으면 O(elogn) 이고 이때 e는 간선의 수를 의미한다.

### 4. 코드 🧑‍💻

- C언어

    [컴알 4-3 Dijkstra.c](https://github.com/julia-ing/CS-Study/blob/main/Algorithm-Univ/Greedy/ShortestPath/Dijkstra.c) - 데이터구조 수업 코드

- 파이썬
    
    [백준 다익스트라 문제집](https://www.acmicpc.net/workbook/view/1711) 참고 -> 푼 이후 코드 업로드 예정
