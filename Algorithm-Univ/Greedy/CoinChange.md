## 동전 거스름돈 문제
---

### 1. 개념 🌱

동전 거스름돈 문제의 최소 동전 수를 찾는 그리디 알고리즘.

남은 액수를 초과하지 않는 조건 하에 욕심내어 가장 큰 액면의 동전을 취한다.

<과정 및 알고리즘>

    CoinChange(W)
    1. change=W, n500=n100=n50=n10=n1=0
    2. while (change >= 500)
        change = change-500, n500++
    3. while (change >= 100)
        change = change-100, n100++
    4. while (change >= 50)
        change = change-50, n50++
    5. while (change >= 10)
        change = change-10, n10++
    6. while (change >= 1)
        change = change-1, n1++
    7. return (n500+n100+n50+n10+n1) // 총 동전 수 리턴

### 2. 특징 🌸

- 남아있는 거스름돈에 대해 가장 높은 액면의 동전을 거스른다.
- 500원 동전을 처리하는 동안 100원~1원 동전을 몇 개씩 거스를 것인지에 대해서는 전혀 신경쓰지 않는다.

- **항상 최적의 답을 주지는 못한다!!**

### 3. 시간 복잡도 ⏰
- O(동전의 종류 개수)

### 4. 코드 🧑‍💻

- C언어
    ```c
    void min_coin() {
        int N = 1260;
        int cnt = 0;

        int coin_types[5] = {500,100,50,10,1};

        for (int i = 0; i < N; i++) {
            cnt += N / coin_types[i];
            N %= coin_types[i];
        }
        printf("%d", cnt);
    }
    ```

- 파이썬
    ```python
    n = 1260 
    count = 0

    coin_types = [500,100,50,10,1] 

    for coin in coin_types:
        count += n // coin
        n %= coin
        
    print(count)
    ```