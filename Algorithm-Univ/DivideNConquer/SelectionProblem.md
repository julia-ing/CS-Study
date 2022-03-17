## 선택 문제
---

### 1. 개념 🌱

n개의 숫자들 중 k번째로 작은 숫자를 찾는 문제. 분할 정복 알고리즘 & 랜덤 알고리즘. 

<과정 및 알고리즘>

![image](https://user-images.githubusercontent.com/77239220/158807775-ab0fd8ec-4b74-4eb4-a856-1fca8881b867.png)


    Small group과 Large group 으로 분할 후 알아야 할 것은 각 그룹의 크기(숫자의 개수). -> k번째 작은 숫자가 어느 그룹에 있는지 알 수 있음. -> 그 그룹에서 몇 번째로 작은 숫자를 찾아야하는지 알게 됨.

    Small 그룹에 k번째 작은 숫자가 속한 경우 : k번째
    Large 그룹에 속한 경우 : (k - S - 1)번째

    Selection(A, left, right, k)
    1. 피봇을 랜덤하게 선택하고, 피봇과 A[left]의 자리를 바꾼 후, 피봇과 배열의 각 원소를 비교하여 피봇보다 작은 숫자는 A[left] ~ A[p - 1]로 옮기고 피봇보다 큰 숫자는 A[p+1] ~ A[right]로 옮기며 피봇은 A[p]에 놓는다.
    2. S = (p - 1) - left + 1  // S = Small group의 크기
    3. if (k <= S) Selection(A, left, p-1, k)  // Small group에서 찾기
    4. else if ( k = S + 1) return A[p]  //피봇 = k번째 숫자
    5. else Selection(A, p + 1, right, k - S - 1)  // Large group에서 찾기

    
### 2. 특징 🌸

- 2개로 분할하고 이 중 1개는 고려할 필요 없으며, 일정하지 않은 크기로 감소한다.
- 단순한 알고리즘들보다 시간 복잡도가 낮아 효율적이다. 

    *(최소 숫자 k번 찾는 경우 : O(kn) / 정렬 후 k번째 찾는 경우 : O(nlogn))* 

- 피봇이 입력을 극도로 치우치게 분할하면 알고리즘의 time cost 가 높아진다. 
- 이진 탐색과의 공통점은 부분 문제들을 취합하는 과정이 따로 없다는 것이고, 차이점은 부분 문제의 크기가 이진 탐색은 1/2로 감소하는 반면 선택 문제는 일정하지 않게 감소한다는 점이다.
- 데이터 분석을 위한 중앙값을 찾는 데에 활용된다.


### 3. 시간 복잡도 ⏰

> good / bad 분할 :

    분할된 두 그룹 중 하나의 크기가 입력 크기의 3/4 이상으로 분할되면 bad 분할. 반대면 good 분할. 

    -> good 분할이 되는 피봇을 선택할 확률과 bad 분할이 되는 피봇을 선택할 확률은 각각 **1/2로 동일**.

    -> 피봇을 랜덤하게 정했을 때 good 분할이 될 확률이 50% 이므로 평균 **2회 연속**해서 랜덤하게 피봇을 정하면 good 분할을 할 수 있음.

    -> good 분할만 연속하여 이루어졌을 때만의 시간 복잡도를 구하여, 그 값에 2를 곱하면 평균 시간 복잡도를 얻을 수 있음.

> **시간 복잡도 구하는 과정**

    1. 1번째 분할
        입력의 크기가 n일 때 두 그룹을 분할하는 데 걸리는 시간은 O(n)이다. 분할 후 큰 부분의 최대 크기는 (3n - 1)/4 인데, 편의상 (3/4)n 이라고 생각한다.
    
    2. 2번째 분할
        큰 부분의 입력 크기가 3n/4이고, 분할 시간은 O(3n/4)이다. 분할 후 큰 부분의 최대 크기는 (3/4)^2*n이다.

    3. 이를 반복하면 시간 복잡도는 다음과 같다.
        (n + (3/4)*n + (3/4)^2*n + ... + (3/4)^i*n) ≤ 2n = O(n)
        
    4. 여기에 2를 곱한 평균 경우 시간 복잡도는 O(n)

### 4. 코드 🧑‍💻

- C언어
    ```c
    int findKth(int list[], int left, int right, int k) {
        int p = partition(list, left, right);
        int S = (p - 1) - left + 1;

        if(k <= S)  // Small group
            return findKth(list, left, p - 1, k);
        else if(k == S + 1)  // 원소 찾은 경우
            return list[p];
        else  // Large group
            return findKth(list, p + 1, right, k - S - 1);
    }

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
    ```

- 파이썬
    ```python
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
            low +=1
            high -=1

        arr[left], arr[high] = arr[high], arr[left]
        return high

    def selection(arr, left, right, k):
        p = partition(arr, left, right)
        S = (p - 1) - left + 1
        if k <= S:
            return selection(arr, left, p - 1, k)
        elif k == S + 1:
            return arr[p]
        else:
            return selection(arr, p + 1, right, k - p - 1)
    ```