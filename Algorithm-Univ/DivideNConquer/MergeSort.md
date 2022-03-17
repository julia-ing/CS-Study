## 합병 정렬
---

### 1. 개념 🌱

2개의 부분 문제로 분할, 부분 문제의 크기가 1/2로 감소하는 분할 정복 알고리즘. 외부 정렬의 기본이 되는 정렬 방식이다. 

<과정 및 알고리즘>

![스크린샷 2022-03-16 오후 3 40 59](https://user-images.githubusercontent.com/77239220/158531513-c1269a3d-5efe-45b4-a6c5-2cd152fbaf46.png)

    1. n개의 숫자들을 n/2개씩 2개의 부분 문제로 분할한다.
    2. 각 부분 리스트를 재귀적으로 합병 정렬한다.
    3. 2개의 정렬된 부분을 합병하여 정렬한다. (정복)

    MergeSort(A, p, q)
    if (p < q) {  // 배열의 원소가 2개 이상이면 
        k = floor((p+q)/2)  // 중간 원소의 인덱스를 구함
        MergeSort(A, p, k)  // 앞부분 재귀 호출
        MergeSort(A, k+1, q)  // 뒷부분 재귀 호출
        Merge(A[p]~A[k], A[k+1]~A[q])  // 합병
    }

### 2. 특징 🌸

- 안정적 정렬 : 입력 데이터, 초기 분산 순서의 영향을 덜 받는다. 
- 연결 리스트로 구현 시 링크의 인덱스만 변하고 데이터의 이동은 거의 없기 때문에 이 경우 퀵 정렬보다도 효율적이다.
- 배열로 구현 시 임시 배열, 즉 추가 공간이 필요하며 레코드 크기가 크면 이동이 많아져 time cost 가 높아진다. 
- 공간 복잡도 : O(n)

### 3. 시간 복잡도 ⏰
- 분할: 배열의 중간 인덱스 계산과 2회의 순환 호출 -> O(1)
- 합병: **O(nlogn)**
    
    - 층별 비교 횟수 : O(n) 
        
        각 층에서 모든 숫자가 합병 과정에 참여하며 합병은 입력 크기에 비례함

    - 층수의 계산 : O(logn)

        n을 계속해서 1/2로 나누다가 1이 되면 분할을 중단함. 이때 분할 횟수가 k번이라면 2^k = n -> k = log2 n

### 4. 코드 🧑‍💻

- C언어
    ```c
    void merge(int list[], int sorted[], int left, int mid, int right) {
        int i, j, k;  // k는 머지된 새로운 리스트의 인덱스
        i = left, j = mid + 1, k = left;

        while(i <= mid && j<= right) {
            if(list[i] <= list[j])
                sorted[k++] = list[i++];
            else
                sorted[k++] = list[j++];
        }
        
        if(i > mid)  // 앞쪽 리스트에 더 이상 원소가 없으면
            while(j <= right)  // 뒤쪽 리스트에 남은 원소를 모두 복사
                sorted[k++] = list[j++];
        else  // 뒤쪽 리스트에 더 이상 원소가 없으면
            while(i <= mid)  // 앞쪽 리스트에 남은 원소를 모두 복사
                sorted[k++] = list[i++];
        
        for(i=left; i<=right; i++)  // 정렬된 리스트를 원래의 배열에 대입
            list[i] = sorted[i];
    }

    void mergeSort(int list[], int sorted[], int left, int right) {
        int mid;
        if(left < right) {
            mid = (left + right) / 2
            mergeSort(list, sorted, left, mid);
            mergeSort(list, sorted, mid+1, right);
            merge(list, sorted, left, mid, right);
        }
    }
    ```

- 파이썬
    ```python
    #################
    # 직관적인 코드 버전 #
    #################

    def mergeSort(list):
        if len(list) <= 1:
            return list

        mid = len(list) // 2
        left = mergeSort(list[:mid])
        right = mergeSort(list[mid:])
        merged = merge(left, right)
        return merged


    def merge(list1, list2):
        merged = []
        while len(list1) > 0 and len(list2) > 0:  # 두 리스트 모두 남은 원소가 존재하는 동안
            if list1[0] <= list2[0]:  # 비교
                merged.append(list1.pop(0))
            else:
                merged.append(list2.pop(0))

        if len(list1) > 0:  # 앞쪽 리스트에 원소가 남아있다면 모두 복사
            merged += list1
        if len(list2) > 0:
            merged += list2

        return merged

    ##################
    # 최적화된 코드 버전 #
    ##################

    # (위처럼 새로운 배열 "merged"을 매번 생성해서 리턴하지 않고, 인덱스 접근을 이용해 배열을 안에서 업데이트시키는 방식)

    def merge_sort(list):
        def sort(left, right):
            if right - left <= 1:
                return
            mid = (left + right) // 2
            sort(left, mid)
            sort(mid, right)
            merge(left, mid, right)

        def merge(left, mid, right):
            tmp = []
            i, j = left, mid

            while i < mid and j < right:
                if list[i] < list[j]:
                    tmp.append(list[i])
                    i += 1
                else:
                    tmp.append(list[j])
                    j += 1

            while i < mid:
                tmp.append(list[i])
                i += 1
            while j < right:
                tmp.append(list[j])
                j += 1

            for k in range(left, right):
                list[k] = tmp[k - left]

        return sort(0, len(list))
    ```