#include <stdio.h>
#define MOD 12345

int count_sequences(int n) {
    if (n == 1) return 2;
    if (n == 2) return 4; 

    int dp[n + 1];

    dp[0] = 1; 
    dp[1] = 2;
    dp[2] = 4; 

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    printf("Введіть довжину послідовності n (1 < n < 10000): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Довжина послідовності повинна бути в межах від 2 до 9999\n");
        return 1;
    }

    int result = count_sequences(n);
    printf("Кількість послідовностей довжиною %d, де не зустрічаються три одиниці підряд: %d\n", n, result);

    return 0;
}