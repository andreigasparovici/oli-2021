#include <bits/stdc++.h>
using namespace std;

const int NMAX = 7001;
const int MOD = 666013;
const int g = 0, r = 1;

int N;
int num_sol, sol[NMAX];

void bkt(int k) {
    if (k == N + 1) {
        num_sol = (num_sol + 1) % MOD;
        return;
    }

    if (k > N + 1) return;

    sol[k] = g;
    bkt(k + 1);

    if (k == 1 || sol[k - 1] == g) {
        sol[k] = sol[k + 1] = sol[k + 2] = r;
        for (int h = 3; k + h <= N + 1; h++) {
            bkt(k + h);
            sol[k + h] = r;
        }
    }
}

int main() {
    freopen("zid.in", "r", stdin);
    freopen("zid.out", "w", stdout);

    scanf("%d", &N);

    bkt(1);

    printf("%d\n", num_sol);
}
