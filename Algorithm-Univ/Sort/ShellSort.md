## 쉘 정렬
---

### 1. 개념 🌱

삽입 정렬이나 버블 정렬에서는 기껏해야 이웃하는 원소의 자리바꿈 -> 쉘 정렬은 삽입 정렬을 이용해 빠르게 이동시키는 정렬 알고리즘

<과정 및 알고리즘>

1. 정렬해야 할 리스트를 gap에 따라 분류해 여러 개의 부분 리스트 생성
2. 삽입 정렬을 이용헤 각 부분 리스트 정렬
3. 모든 부분 리스트가 정렬되면 다시 전체 리스트를 더 적은 개수의 부분 리스트로 만든 후 알고리즘을 반복
4. 부분 리스트의 개수가 1이 될 때까지 위 과정 반복

<img width="692" alt="스크린샷 2022-06-04 오전 4 18 59" src="https://user-images.githubusercontent.com/77239220/171934192-3e6f5f38-c914-4df9-8507-3007a2d86bd3.png">
<img width="637" alt="스크린샷 2022-06-04 오전 4 19 17" src="https://user-images.githubusercontent.com/77239220/171934265-d7720b98-6fba-4570-ae4b-bb131c066cc7.png">



    입력: 크기가 n인 배열 A
    출력: 정렬된 배열 A

    ShellSort(A)
    for each gap h = [h0 > h1 > ... > hk > 1]
        for i = h to n-1
            CurrentElement = A[i]
            j = i
            while(j >= h) and (A[j-h] > CurrentElement)
                A[j] = A[j-h]
                j = j-h
            A[j] = CurrentElement
    return A


### 2. 특징 🌸

- 마지막에는 반드시 간격을 1로 놓고 수행해야 함 - 다른 그룹에 속해 서로 비교되지 않은 숫자가 있을 수 있기 때문. -> 모든 원소를 1개의 그룹으로 여기는 것, 삽입 정렬 자체

- 장점 : 입력 크기가 매우 크지 않은 경우 매우 좋은 성능을 보임
- 임베디드 시스템에서 주도 사용 (간격에 따른 그룹별 정렬 방식)

### 3. 시간 복잡도 ⏰
- 사용하는 간격에 따라 분석해야 함
    - 최악의 경우: 히바드의 간격 2^k - 1 => O(n^1.5)
    - 지금까지 알려진 가장 좋은 성능을 보인 간격: 1, 4, 10, 23, 57, 132, 301, 701, 1750
    - 가장 좋은 간격을 알아내야 하는 것이 선행되어야 하기 때문에 쉘 정렬의 시간 복잡도는 아직 풀리지 않은 문제

### 4. 코드 🧑‍💻

- C언어
    ```c
    void shellSort(int A[]) {
        int currentElement;
        
        printf("Before Sort : ");
        for(int j = 0; j < N; j++)
            printf("%d ", A[j]);
        printf("\n<<<<<<<<<< Shell Sorting... >>>>>>>>>>\n");
        
        for(int h = 5; h >= 1; h -= 2) {  // h = gap
            for(int i = h; i <= N-1; i++) {
                currentElement = A[i];
                int j = i;
                
                while(j >= h && A[j-h] > currentElement) {
                    A[j] = A[j-h];
                    j -= h;
                }
                A[j] = currentElement;
            }

            printf(" Gap %d >> ", h);
            for(int j = 0; j < N; j++)
                printf("%d ", A[j]);
            printf("\n");
        }
    }


    ```

- 파이썬
    ```python
    def shell_sort(A):
        N = len(arr)
        h = N // 2
        while h > 0:
            for i in range(h, N):
                temp = A[i]
                j = i - h
                while j >= 0 and A[j] > temp:
                    A[j + h] = A[j]
                    j -= h
                A[j + h] = temp
            h //= 2
     
        print(A)
    ```

