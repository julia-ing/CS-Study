## 크루스칼 알고리즘
---

### 1. 개념 🌱

가장 적은 비용으로 모든 노드를 연결시키는(MST를 만들기 위한) 알고리즘

**가중치가 가장 작은 간선 순서대로 + 사이클을 만들지 않을 때에만 추가시킨다.**

<과정 및 알고리즘>

<img width="633" alt="스크린샷 2022-04-02 오전 1 46 17" src="https://user-images.githubusercontent.com/77239220/161306936-e0a5f993-284a-4976-92bb-ea39e9a618ec.png">

    KruskalMST(G)
    1. 가중치의 오름차순으로 간선들을 정렬한다. 정렬된 간선 리스트 = L
    2. T를 초기화
    3. while (T의 간선 수 < n-1)
    4.     L[0] 즉 가장 가중치가 작은 간선 e를 가져오고 e를 L에서 제거
    5.     if (간선 e가 T에 추가됨으로 사이클을 만들지 않으면)
    6.         e를 T에 추가
    7.     else
    8.         e를 버린다.
    9. return T  // T는 최소 신장 트리

5 ~ 8 과정을 union find 라고 한다. 


### 2. 특징 🌸

- 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(Sparse Graph)의 경우 Prim보다 Kruskal 알고리즘이 적합하다.

### 3. 시간 복잡도 ⏰

- 1 : 간선 정렬 O(eloge)
- 2 : T 초기화 O(1)
- 3 ~ 8 : while 루프 최대 e번 (간선 수) 수행 / 루프 내에서 사이클 검사 O(1)

-> 최종 **O(eloge)**

### 4. 코드 🧑‍💻

- C언어

    [컴알 4-2 Kruskal.c](https://github.com/julia-ing/CS-Study/blob/main/Algorithm-Univ/Greedy/MST/Kruskal.c)

- 파이썬
    
    [백준 크루스칼 문제집](https://www.acmicpc.net/workbook/view/1899) 참고 -> 푼 이후 코드 업로드 예정
