## 버블 정렬
---

### 1. 개념 🌱

서로 **인접한 두 원소**를 검사하여 정렬하는 알고리즘.
인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환한다.

<과정 및 알고리즘>

1 pass 가 지나면 가장 큰 자료가 맨 뒤로 이동 후 고정됨 -> 2번째 pass 에서는 맨 끝 자료가 정렬에서 제외됨 -> 2 pass 이후, 끝에서 두 번째 자료까지는 정렬에서 제외됨 

:  정렬을 1회전 수행할 때마다 정렬에서 제외되는 데이터가 하나씩 늘어난다.

![스크린샷 2022-05-26 오후 11 25 47](https://user-images.githubusercontent.com/77239220/170508126-070043a9-4f82-4943-a732-7ca62d2f16b7.png)

    BubbleSort(A)
    for pass = 1 to n-1
        for i = 1 to n-pass
            if (A[i-1] > A[i])
                A[i-1]와 A[i] 교환
    return A

### 2. 특징 🌸

- 장점 : 매우 간단한 구현 방식
- 단점
    - 하나의 요소가 가장 왼쪽에서 가장 오른쪽으로 이동하기 위해서는 배열 내 다른 모든 요소들과 교환되어야 함
    - 특정 요소가 최종 정렬 위치에 이미 있음에도 교환되는 일이 발생할 수 있음
    
- 일반적으로 교환 작업(SWAP)이 이동보다 더 복잡하기 때문에 버블 정렬은 단순성에도 불구하고 거의 쓰이지 않는다 :(

### 3. 시간 복잡도 ⏰
- pass = 1이면 (n-1)번 비교, 2면 (n-2)번 비교 ..
    
    -> 총 비교 횟수 n(n-1)/2

- 루프 내부에서 조건문이 참일 경우 교환하는 시간 O(1)
- 최종 O(n^2) * O(1) = **O(n^2)**

### 4. 코드 🧑‍💻

- C언어
    ```c
    void bubbleSort(int A[]) {
        int temp;
        
        printf("Before Sort : ");
        for(int j = 0; j < N; j++)
            printf("%d ", A[j]);
        printf("\n<<<<<<<<<< Bubble Sorting... >>>>>>>>>>\n");
        
        for(int pass = 1; pass <= N-1; pass++) {
            int flag = FALSE;
            
            for(int i = 1; i <= N-pass; i++)
                if(A[i-1] > A[i]) {
                    SWAP(A[i-1], A[i], temp);
                    flag = TRUE;
                }
            
            if(flag == FALSE)
                break;

            printf(" %d pass >> ", pass);
            for(int j = 0; j < N; j++)
                printf("%d ", A[j]);
            printf("\n");
        }
        
    }
    ```

- 파이썬
    ```python
    def bubble_sort(arr):
        for i in range(len(arr) - 1, 0, -1):
            flag = False
            for j in range(i):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    flag = True
            if not flag:
                break
    ```