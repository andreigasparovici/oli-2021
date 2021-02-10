#include <bits/stdc++.h>
using namespace std;

const int NMAX = 5001;
const int MOD = 666013;

int N;
const int g = 0, r = 1;

int num_sol, sol[NMAX];

void bkt(int k) {
    if (k == N + 1) {
        //for (int i = 1; i <= N; i++)
        //    cout << (sol[i] == g ? 'G' : 'R') << " ";
        //cout << endl;

        num_sol = (1LL * num_sol + 1) % MOD;
        return;
    }

    if (k > N + 1) return;

    // Try green
    sol[k] = g;
    bkt(k + 1);

    // Try red
    if (k == 1 || sol[k - 1] == g) {
        sol[k] = sol[k + 1] = sol[k + 2] = r;
        for (int h = 3; k + h <= N + 1; h++) {
            bkt(k + h);
            sol[k + h] = r;
        }
    }
}

int main() {
    freopen("lego.in", "r", stdin);
    //freopen("lego.out", "w", stdout);

    scanf("%d", &N);

    bkt(1);

    printf("%d\n", num_sol);
}
