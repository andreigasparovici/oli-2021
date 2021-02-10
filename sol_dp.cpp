#include <bits/stdc++.h>
using namespace std;

const int NMAX = 3001;
const int MOD = 666013;

int N, dp[NMAX][2];

int main() {
    freopen("lego.in", "r", stdin);
    freopen("lego.out", "w", stdout);

    scanf("%d", &N);

    const int g = 0, r = 1;

    dp[1][r] = dp[1][g] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][r] = dp[i - 1][g];

        dp[i][g] = dp[i - 1][g];
        for (int j = 3; j <= min(i, N); j++)
            dp[i][g] = (1LL * dp[i][g] + dp[i - j][r]) % MOD;
    }

    printf("%d\n", (dp[N][r] + dp[N][g] - 1) % MOD);
}
