## 동적 계획 알고리즘
---

### 1. 개념

입력 크기가 작은 부분 문제들을 해결한 후 그 해들을 이용하여 보다 큰 크기의 부분 문제들을 해결함으로써 최종적으로 원래 주어진 문제를 해결하는 알고리즘

### 2. 특징
- 상향식 접근법 : 가장 하위의 해답을 구해 저장하고 이를 이용해 상위 문제들 해결

- **Memoization** 기법 사용

- 부분 문제는 중복되어 재활용됨

- DP vs 분할정복

    - 공통점: 문제를 쪼개 가장 작은 단위로 분할

    - 차이점: dp는 부분 문제가 중복돼서 상위 문제 해결에 이용되는 반면 / 분할정복에서는 부분 문제가 중복되지 않는다.

### 3. 정리

> DP의 사용 조건

    1) Overlapping Subproblems(겹치는 부분 문제)
    2) Optimal Substructure(최적 부분 구조)

> 구현 방식
    
    1) DP로 풀 수 있는 문제인지 확인
    2) 문제의 변수 파악
    3) 변수 간 관계식 발견 (점화식)
    4) 메모 (memoization or tabulation)
    5) 기저 상태 파악
    6) 구현

### 4. 코드 예시

-  피보나치

```python
# 1. 재귀 O(2^n)
def fib_recur(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

# 2. DP O(n)
def fib_dp(n):
    memo = [0 for i in range(n+1)]
    memo[0] = 0
    memo[1] = 1

    for i in range(2, n+1):
        memo[i] = memo[i-1] + memo[i-2]
    return memo[n]

# 3. 반복문 O(n)
def fib_loop(n):
    a = 0
    b = 1
    sum = 0
    
    for i in range(2, n+1):
        sum = a+b
        a = b
        b = sum
    return sum
```
