## 퀵 정렬
---

### 1. 개념 🌱

2개의 부분 문제로 분할, 각 부분 문제의 크기가 일정하지 않은 분할 정복 알고리즘. 정복 후 분할하는 형식이며 평균적으로 가장 빠르다.

<과정 및 알고리즘>

![image](https://user-images.githubusercontent.com/77239220/158541873-f0d517ba-5a24-45e2-81b3-31732de4127f.png)


    1. 리스트 안에서 피봇(pivot)을 선택한다. (참고: 피봇은 분할된 왼편이나 오른편에 속하지 않음)
    2. 피봇을 기준으로 피봇보다 작은 원소들은 왼쪽으로 옮기고 피봇보다 큰 원소들은 오른쪽으로 옮긴다.
    3. 피봇을 제외한 왼쪽 리스트와 오른쪽 리스트를 재귀적으로 정렬한다.

    QuickSort(A, left, right)
    if (left < right) {  
        p = partition(A, left, right)  // 1, 2번 과정
        QuickSort(A, left, p-1)  // 피봇보다 작은 그룹
        QuickSort(A, p+1, right)  // 피봇보다 큰 그룹
    }


### 2. 특징 🌸

- 불안정 정렬
- 속도가 빠르며 추가 메모리 공간을 필요로 하지 않는다.
- 입력의 크기가 매우 클 경우 퀵 정렬의 성능을 더 향상시키는 방법은 **삽입 정렬**을 동시에 적용하는 것이다. (퀵 정렬을 순환 호출하는 과정이 있기 때문에 입력의 크기가 작을 때는 삽입 정렬보다 효율적이지만은 않음 -> 부분 문제의 크기가 작아지면 더 이상 분할, 즉 재귀 호출을 멈추고 삽입 정렬을 적용)
- 이미 정렬된 리스트의 경우나 피봇이 가장 작은/큰 숫자로 선택되는 경우 불균형 분할로 time cost가 높아진다. 
    
    -> 퀵 정렬의 성능은 **피봇 선택**이 좌우함!!

    > 피봇 선정 방법
    
    1. Median-of-Three : left, mid, right 의 중앙값으로 선정 
    2. Median-of-Medians : 리스트를 3등분한 후 각 부분에서 left, mid, right 중 중앙값을 찾고 다시 세 중앙값들 중 중앙값으로 선정

### 3. 시간 복잡도 ⏰
- 최선 (거의 균등한 리스트로 분할) : **O(nlogn)**
    
    - 패스 수 : logn
    - 각 패스 안에서의 비교횟수 : O(n)
    - -> 총 비교 횟수 : O(nlogn)
    - 총 이동 횟수는 무시 가능

- 최악 (극도로 불균등한 리스트로 분할) : O(n^2)

    - 패스 수 : n
    - 각 패스 안에서의 비교횟수 : O(n)
    - -> 총 비교 횟수 : O(n^2)
    - 총 이동 횟수는 무시 가능

- 평균 : O(nlogn)

### 4. 코드 🧑‍💻

- C언어
    ```c
    #define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

    int partition(int list[], int left, int right) {
        int pivot, temp, low, high;
        
        pivot = list[left];
        low = left; high = right + 1;
        
        do {
            do
                low++;
            while (list[low] < pivot);  // left 다음부터 증가하며 pivot값 이상인 원소 찾기
            
            do  
                high--;
            while (list[high] > pivot);  // right 부터 줄여가며 pivot 이하인 원소 찾기
            
            if(low < high)
                SWAP(list[low], list[high], temp);  // 두 요소를 바꿈
        
        } while (low < high);  // low와 high가 교차할 때까지 반복
        
        SWAP(list[left], list[high], temp);  // pivot을 중앙으로
        return high;  // 피봇 위치 반환
    }

    void quickSort(int list[], int left, int right) {
        if(left < right)
        {
            int p = partition(list, left, right);
            quickSort(list, left, p - 1);
            quickSort(list, p + 1, right);
        }
    }

    /***********************
    * 참고: Median-of-Three *
    ***********************/
    int medianOfThree(int list[], int left, int right) {
        int mid = (left + right) / 2;

        if(list[right] < list[left])
            Swap(list, left, right);
        if(list[mid] < list[left])
            Swap(list, mid, left);
        if(list[right] < list[mid])
            Swap(list, mid, right);
            
        return mid;
    }

    void Swap(list, left, right) {
        temp = list[left]
        list[left] = list[right]
        list[right] = temp  
    }
    ```

- 파이썬
    ```python
    def sort(arr, low, high):
        if high <= low:
            return

        mid = partition(arr, low, high)
        sort(arr, low, mid - 1)
        sort(arr, mid + 1, high)


    from random import randint

    def partition(arr, left, right):
        pivot = randint(left, right)
        if pivot != left:  # 피봇을 가장 왼쪽으로
            arr[pivot], arr[left] = arr[left], arr[pivot]

        low = left + 1
        high = right
        while True:  # do-while 구문을 True로 구현할 수 있음
            while low < right and arr[low] < arr[left]:
                low += 1
            while high > left and arr[high] > arr[left]:
                high -= 1
            if low >= high:
                break
            arr[low], arr[high] = arr[high], arr[low]
            low += 1
            high -= 1

        arr[left], arr[high] = arr[high], arr[left]
        return high
    ```