#include <bits/stdc++.h>

#define MAX 100010

int N, in[MAX], out[MAX], l, r;

int main()
{

    std::cin >> N; l = 2; r = N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; std::cin >> a >> b;
        out[a]++; in[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (out[i] >= 2) {
            r = i; break;
        }
    }
    for (int i = N; i > 0; i--) {
        if (in[i] >= 2) {
            l = i; break;
        }
    }

    for (int i = l; i <= r; i++) {
        std::cout << i << "\n";
    }

    return 0;
}
