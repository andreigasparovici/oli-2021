#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5001;
const int MOD = 666013;

int N, dp[NMAX][2];

int main() {
    freopen("lego.in", "r", stdin);
    freopen("lego.out", "w", stdout);

    scanf("%d", &N);

    const int g = 0, r = 1;

    dp[0][g] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i][g] = (1LL * dp[i - 1][g] + dp[i - 1][r]) % MOD;

        for (int j = 3; j <= i; j++)
            dp[i][r] = (1LL * dp[i][r] + dp[i - j][g]) % MOD;
    }

    printf("%d\n", (dp[N][r] + dp[N][g]) % MOD);
}
