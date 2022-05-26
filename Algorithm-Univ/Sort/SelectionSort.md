## 선택 정렬
---

### 1. 개념 🌱

입력 배열 전체에서 **최솟값을 선택**해 배열의 0번 원소와 자리를 바꾸고, 다음 pass에서는 0번 원소를 제외한 나머지 원소에서 최솟값을 선택하며 반복하는 정렬 방식.
마지막에는 2개의 원소 중 작은 것을 선택해 자리를 바꾼다.

<과정 및 알고리즘>



![스크린샷 2022-05-26 오후 11 40 58](https://user-images.githubusercontent.com/77239220/170511356-3c2308a6-655d-4e2f-aab3-1f3d3c9b6fa7.png)


    SelectionSort(A)
    for i = 0 to n-2
        min = i
        for j = i+1 to n-1
            if A[j] < A[min]
                min = j
            A[i] 와 A[min]을 교환
    return A

### 2. 특징 🌸

- 장점 : 자료 이동 횟수가 미리 결정됨
- 단점 : 안정성을 만족하지 않음 (값이 같은 레코드가 있는 경우에 상대적인 위치가 변경될 수 있다.)

### 3. 시간 복잡도 ⏰
- i=0일 때 내부 루프는 (n-1)번, i=1이면 (n-2)번 수행.. 
    
    -> for루프의 총 횟수 n(n-1)/2

- 루프 내부에서 조건문이 참일 경우 교환하는 시간 O(1)
- 최종 O(n^2) * O(1) = **O(n^2)**

### 4. 코드 🧑‍💻

- C언어
    ```c
    void selectionSort(int A[]) {
        int min, temp;
        
        printf("Before Sort : ");
        for(int j = 0; j < N; j++)
            printf("%d ", A[j]);
        printf("\n<<<<<<<<<< Selection Sorting... >>>>>>>>>>\n");
        
        for(int i = 0; i <= N-2; i++) {  // 마지막 숫자는 자동 정렬: (N-1)번 반복
            min = i;
            
            for(int j = i+1; j <= N-1; j++)  // 최솟값 탐색
                if(A[j] < A[min])
                    min = j;
            SWAP(A[i], A[min], temp);

            printf(" %d pass >> ", i+1);
            for(int j = 0; j < N; j++)
                printf("%d ", A[j]);
            printf("\n");
        }
    }

    void selectionSort2(int A[]) {  // 큰 값부터 고정 - 역방향 정렬
        int max, temp;
        
        printf("Before Sort : ");
        for(int j = 0; j < N; j++)
            printf("%d ", A[j]);
        printf("\n<<<<<<<<<< Selection Sorting... >>>>>>>>>>\n");
        
        for(int i = 0; i <= N-2; i++) {
            max = 0;
            
            for(int j = 1; j <= N-1-i; j++)
                if(A[j] > A[max])
                    max = j;
            SWAP(A[N-1-i], A[max], temp);

            printf(" %d pass >> ", i+1);
            for(int j = 0; j < N; j++)
                printf("%d ", A[j]);
            printf("\n");
        }
    }

    ```

- 파이썬
    ```python
    def selection_sort(arr):
        for i in range(len(arr) - 1):
            min = i
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[min]:
                    min = j
            arr[i], arr[min] = arr[min], arr[i]
    ```