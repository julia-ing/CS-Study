## 프림 알고리즘
---

### 1. 개념 🌱

임의의 점 하나를 선택한 후, (n-1) 개의 간선을 하나씩 추가시켜 트리를 생성

**추가되는 간선은 현재까지 만들어진 트리에 연결할 때 '욕심내어' 항상 최소 가중치로 연결되는 간선**

<img width="480" alt="스크린샷 2022-04-06 오후 7 11 32" src="https://user-images.githubusercontent.com/77239220/161952455-a86cd5c2-3b2a-48c0-ad06-72376812ca3e.png">

[사진 출처](https://velog.io/@ming/Prim%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

<과정 및 알고리즘>


    PrimMST(G)
    1. 가중치 그래프 G에서 임의의 점 p를 시작점으로 선택, D[p] = 0
    2. for (점 p가 아닌 각 점에 대해) {  // 배열 D 초기화
            if (간선 (p, v)가 그래프에 있으면)
                D[v] = 간선 (p, v)의 가중치
            else D[v] = 1000000 // 무한
        } 
    3. T = {p}  // 초기에 트리 T는 점 p만을 가짐
    4. while (T에 있는 점의 수 < n) {
            T에 속하지 않은 각 점 v에 대해 D[v]가 최소인 점 vMin과 연결된 간선 (u, vMin)을 T에 추가. u는 T에 속한 점이고 점 vMin도 T에 추가.
            for (T에 속하지 않은 각 점 w에 대해) {
                if (간선 (vMin, w)의 가중치 < D[w])
                    D[w] = 간선 (vMin, w)의 가중치  // 갱신
            }
        }
    5. return T


### 2. 특징 🌸

- 처음부터 끝까지 **트리를 계속 유지**한다.
- 항상 T 밖에 있는 점을 추가하기 때문에 **사이클이 만들어지지 않는다.**

### 3. 시간 복잡도 ⏰

- while 반복문이 (n-1)회 시행되는데, 1회마다 vMin을 찾는 데에 O(n)

-> (n-1) * O(n) = **O(n^2)**

<참고> - 배열이 아닌 최소 힙(Binary Heap) 구조를 사용하여 vMin 을 찾으면 O(elogn) 이고 이때 e는 간선의 수를 의미한다.

### 4. 코드 🧑‍💻

- C언어

    [컴알 4-2 Prim.c](https://github.com/julia-ing/CS-Study/blob/main/Algorithm-Univ/Greedy/MST/Prim.c)

- 파이썬
    
    [백준 크루스칼 문제집 - 프림으로 풀어보기](https://www.acmicpc.net/workbook/view/1899) 참고 -> 푼 이후 코드 업로드 예정
