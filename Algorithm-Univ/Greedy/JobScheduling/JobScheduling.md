## 작업 스케줄링
---

### 1. 개념 🌱

작업의 수행 시간이 중복되지 않도록 모든 작업을 가장 적은 수의 기계에 배정하는 문제

1. 빠른 시작시간 작업 우선 배정
2. 빠른 종료시간 작업 우선 배정
3. 짧은 작업 우선 배정
4. 긴 작업 우선 배정

-> 1번 제외하고 나머지는 항상 최적해를 찾지 못함

<과정 및 알고리즘>

    JobScheduling
    1. 시작 시간으로 정렬한 작업 리스트 L
    2. while L != []
            L에서 가장 이른 시작 시간 작업 ti를 가져옴
            if ti를 수행할 기계가 있으면
                배정
            else
                새 기계에 ti 배정
            ti를 L에서 제거
    3. return 각 기계에 배정된 작업 순서

### 2. 시간 복잡도 ⏰
- 정렬 시간 O(nlogn)
- while 반복문 n번 
- 루프 안에서 수행 가능한 기계 찾아 배정하는 데 O(m), m은 사용된 기계의 수

-> 최종 : O(nlong) + O(mn)

### 3. 코드 🧑‍💻

- [구간 스케줄링 (가장 이른 종료 시간)](https://github.com/julia-ing/CS-Study/blob/main/Algorithm-Univ/Greedy/JobScheduling/IntervalScheduling.py)

- [구간 분할 (가장 이른 시작 시간)](https://github.com/julia-ing/CS-Study/blob/main/Algorithm-Univ/Greedy/JobScheduling/IntervalDivision.py)