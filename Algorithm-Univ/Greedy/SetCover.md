## 집합 커버 문제
---

### 1. 개념 🌱

집합 F에서 선택하는 집합들의 수를 최소화하는 문제

- given.. n개의 원소를 가진 집합 U, U의 부분집합들을 원소로 하는 집합 F -> then.. F의 원소들인 집합들 중 어떤 집합들을 선택해 합집합하면 U와 같게 되는지 찾기

- 최적해를 찾으려면 F의 모든 조합을 1개씩 합집합해가며 U가 되는지 확인해야 하는데 이때 최대 (2^n - 1)개를 검사해야 함. -> 최적해에 근접한 **근사해** 찾기

<과정 및 알고리즘>

    SetCover
    1. C = {}
    2. while U != {}
            U의 원소를 가장 많이 가진 집합 Si를 F에서 선택
            U = U - Si
            Si를 F에서 제거하고 C에는 추가
    3. return C

### 2. 시간 복잡도 ⏰
- while 반복문 최대 n회

<루프 1회 수행 시 >

    - 남아있는 Si들과 U를 각각 비교 : O(n^2)
    - U에서 Si 제거 : O(n)
    - Si를 F에서 제거하고 C에는 추가 : O(1)

-> 최종: n * O(n^2) = **O(n^3)**

### 3. 코드 🧑‍💻

- C언어

    ```C
    Cities = set([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

    Schools = {}
    Schools[1] = set([1, 2, 3, 8])  # 해시테이블 
    Schools[2] = set([1, 2, 3, 4, 8])
    Schools[3] = set([1, 2, 3, 4])
    Schools[4] = set([2, 3, 4, 5, 7, 8])
    Schools[5] = set([4, 5, 6, 7])
    Schools[6] = set([5, 6, 7, 9, 10])
    Schools[7] = set([4, 5, 6, 7])
    Schools[8] = set([1, 2, 4, 8])
    Schools[9] = set([6, 9])
    Schools[10] = set([6, 10])

    # print(Schools)  # {1: {8, 1, 2, 3}, 2: {1, 2, 3, 4, 8}, ... }

    finalCities = set()

    while Cities:
        bestCity = None
        schoolCovered = set()
        
        for schoolNum, cities in Schools.items():
            covered = Cities & cities  # & : 교집합 연산
            if len(covered) > len(schoolCovered):  # 가장 많이 커버하는 부분집합 찾기
                bestCity = schoolNum
                schoolCovered = covered
        
        Cities -= schoolCovered  # 차집합
        
        finalCities.add(bestCity)  # 최종 답안에 추가
        
    print(finalCities)
    ```