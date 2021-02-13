#include <bits/stdc++.h>
using namespace std;

const int NMAX = 7001;
const int MOD = 666013;

int N;
int dp[NMAX];

int main() {
    freopen("zid.in", "r", stdin);
    freopen("zid.out", "w", stdout);

    scanf("%d", &N);

    dp[0] = 1;

    for (int i = 1; i <= N+1; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= i - 4; j++)
            dp[i] = (dp[i] + dp[j]) % MOD;
    }

    printf("%d\n", dp[N + 1]);
}
