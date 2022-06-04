## 힙 정렬
---

### 1. 개념 🌱

최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 정렬 알고리즘. (힙 조건을 만족하는 완전 이진 트리)

<과정 및 알고리즘>

1. 정렬할 입력으로 최대 힙을 만든다.
2. 힙 루트에 가장 큰 수가 있으므로 루트와 힙의 가장 마지막 노드를 교환한다. 즉 가장 큰 수를 배열의 맨 뒤로 옮긴 것.
3. 힙 크기를 1개 줄인다.
4. 루트에 새로 저장된 숫자로 인해 위배된 힙 조건을 해결하여 힙 조건을 만족시킨다.
5. 위 과정 반복

<img width="780" alt="스크린샷 2022-06-05 오전 3 30 06" src="https://user-images.githubusercontent.com/77239220/172020939-d9b09b68-2e90-426f-b432-848daa165a9d.png">
<img width="777" alt="스크린샷 2022-06-05 오전 3 30 19" src="https://user-images.githubusercontent.com/77239220/172020945-b48af5b7-3f00-42ee-b8a4-3629befab02f.png">



    입력: 크기가 n인 배열 A
    출력: 정렬된 배열 A

    HeapSort(A)
    1. A의 숫자에 대해 최대 힙을 만든다.
    2. heapSize = n
    for i = 1 to n-1
        A[1] <-> A[heapSize]  // 루트와 마지막 노드 교화
        heapSize = heapSize - 1
        DownHeap()
    return A


### 2. 특징 🌸

- 최선, 최악, 평균 시간 복잡도가 O(nlogn)으로 동일
- 안정성 X
- 제자리 정렬 
- 큰 입력에 대해 DownHeap()을 수행할 때 자식을 찾아야 하므로 너무 많은 캐시 미스로 인해 페이지 부재를 야기시킴
- 힙 정렬이 가장 유용한 경우는 전체 자료를 정렬하는 것이 아니라 가장 큰 값 몇개만 필요할 때!!


### 3. 시간 복잡도 ⏰
- 힙을 만드는 데이 O(n)
- for 루프 (n-1)반, 루프 내부는 O(1)
- DownHeap : O(logn)

-> 최종 O(n) + (n-1) * O(logn) = **O(nlogn)**

### 4. 코드 🧑‍💻

- C언어
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #define N 100

    typedef struct {
        int heap[N];
        int heapSize;
    }HeapType;

    void init(HeapType* H) {
        H->heapSize = 0;
    }

    void upHeap(HeapType* H) {
        int i = H-> heapSize;
        int key = H->heap[i];
        
        while((i != 1) && (key > H->heap[i/2])) {
            H->heap[i] = H->heap[i/2];  // 부모와 교환
            i /= 2;
        }
        H->heap[i] = key;
    }

    void insertItem(HeapType* H, int key) {
        H->heapSize++;
        H->heap[H->heapSize] = key;
        upHeap(H);
    }

    void downHeap(HeapType* H) {
        int item = H->heap[1];
        int parent = 1, child = 2;  // 왼쪽 자식부터
        
        while(child <= H->heapSize) {
            // 형제노드가 있고, 형제노드가 자신보다 크면
            if((child < H->heapSize) && (H->heap[child+1] > H->heap[child]))
                child++; // 2->3, 오른쪽 자식이 됨
                
            if(item >= H->heap[child])
                break;
            
            H->heap[parent] = H->heap[child];
            parent = child;
            child *= 2;
        }
        H->heap[parent] = item;
    }

    void heapSort(HeapType* H) {
        int n = H->heapSize;
        
        for(int i = 1; i < n; i++) {
            int item = H->heap[1];  // 루트 기억
            H->heap[1] = H->heap[H->heapSize];  // 루트와 마지막을 교환
            H->heap[H->heapSize] = item;
            H->heapSize--;
            downHeap(H);
            
            printf("Step %d : ", i);
            for(int i = 1; i < n; i++) 
                printf("(%d) ", H->heap[i]);
            printf("\n");
        }
        
    }

    void printHeap(HeapType* H) {
        for(int i = 1; i <= H->heapSize; i++) 
            printf("(%d) ", H->heap[i]);
        printf("\n");
    }

    int main()
    {
        HeapType H;
        init(&H);
        
        insertItem(&H, 90); insertItem(&H, 60); insertItem(&H, 80);
        insertItem(&H, 50); insertItem(&H, 30); insertItem(&H, 70);
        insertItem(&H, 10); insertItem(&H, 20); insertItem(&H, 40);
        printHeap(&H); getchar();
        
        insertItem(&H, 80);
        printHeap(&H);
        
        heapSort(&H);
        
        return 0;
    }

    ```

- 파이썬
    ```python

    #########################
    # heapq 모듈 - 기본 최소 힙 # 
    #########################

    heap = [5, 3, 4, 2, 1]
    heapq.heapify(heap)
    print(heap) # [1, 2, 4, 5, 3]


    # 최대 힙 구현 방법
    num = [5, 3, 4, 2, 1]
    heap = []

    for n in num:
        heapq.heappush(heap, (-n, n))  # (우선순위, 값)

    while heap:
        print(heapq.heappop(heap)[1])


    #############
    # 힙 정렬 구현 #
    #############

    array = [1, 10, 5, 8, 7, 6, 4, 3, 2, 9]

    # 1. 상향식: 특정 노드를 기준으로 위로 올라감
    def heap_sort(array):
        n = len(array)
        # heap 구성
        for i in range(n):
            c = i
            while c != 0:
                r = (c-1)//2
                if (array[r] < array[c]):
                    array[r], array[c] = array[c], array[r]
                c = r
                print(array)
        # 크기를 줄여가면서 heap 구성
        for j in range(n-1, -1, -1):
            array[0] , array[j] = array[j], array[0]
            r = 0
            c = 1
            while c<j:
                c = 2*r +1
                # 자식 중 더 큰 값 찾기
                if (c<j-1) and (array[c] < array[c+1]):
                    c += 1
                # 루트보다 자식이 크다면 교환
                if (c<j) and (array[r] < array[c]):
                    array[r], array[c] = array[c], array[r]
                r=c
                print(array)
        print(array)
    heap_sort(array)

    # 출처 - https://seanpark11.tistory.com/68

    ```

