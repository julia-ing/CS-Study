## 삽입 정렬
---

### 1. 개념 🌱

배열을 **정렬된 부분과 정렬되지 않은 부분으로 나누고**, 정렬 안 된 부분의 가장 왼쪽 원소를 정렬된 부분의 **적절한 위치에 삽입**하는 정렬 방식

<과정 및 알고리즘>

정렬 안 된 부분의 숫자 하나가 정렬된 부분에 삽입됨으로써, 정렬된 부분의 원소 수는 1 증가하고 동시에 안 된 부분의 원소 수는 1 감소

반복하면 마지막에는 정렬 안 된 부분에 아무 원소도 남지 않고 입력이 정렬된다. 

![스크린샷 2022-05-26 오후 11 58 44](https://user-images.githubusercontent.com/77239220/170515262-be159a1e-f2c0-456c-83dc-982ed2c982b5.png)


    InsertionSort(A)
    for i = 1 to n-1
        current = A[i]
        j = i-1
        while(j >= 0) and (A[j] > current)
            A[j+1] = A[j]
        A[j+1] = current
    return A

### 2. 특징 🌸

- 장점
    - 안정한 정렬 방법
    - 레코드의 수가 적을 경우 다른 복잡한 정렬 방법보다 유리할 수 있음 -> 따라서 퀵정렬 합병정렬에서 입력 크기가 작아지면 순환 호출을 중단하고 삽입 정렬을 사용
    - **대부분의 레코드가 이미 정렬되어 있는 경우**에 매우 효율적 -> 이때는 시간복잡도가 O(n)
- 단점
    - 비교적 많은 이동
    - 레코드 수가 많고 레코드 크기가 클 경우 비효율적

### 3. 시간 복잡도 ⏰
- i = 1이면 while 루프 1번 수행, i=2면 최대 2번, 마지막에 최대 (n-1)번 수행
    
    -> 루프 내부가 수행되는 횟수 n(n-1)/2

- 루프 내부 교환 시간 O(1)
- 최종 O(n^2) * O(1) = **O(n^2)**

### 4. 코드 🧑‍💻

- C언어
    ```c
    void insertionSort(int A[]) {
        int currentElement;
        
        printf("Before Sort : ");
        for(int j = 0; j < N; j++)
            printf("%d ", A[j]);
        printf("\n<<<<<<<<<< Insertion Sorting... >>>>>>>>>>\n");
        
        for(int i = 1; i <= N-1; i++) {
            currentElement = A[i];
            int j = i-1;
            
            while(j >= 0 && A[j] > currentElement) {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = currentElement;

            printf(" %d pass >> ", i);
            for(int j = 0; j < N; j++)
                printf("%d ", A[j]);
            printf("\n");
        }
    }

    ```

- 파이썬
    ```python
    def insertion_sort(arr):
        for i in range(1, len(arr)):
            j = i
            while j > 0 and arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]
                j -= 1
    ```

-> 삽입 정렬은 쉘 정렬의 아이디어가 됨
