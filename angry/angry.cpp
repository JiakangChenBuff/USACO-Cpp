#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 50000
#define INF 2000000000

int N, pos[MAX], dpL[MAX], dpR[MAX];
double ans = INF;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> pos[i];

    std::sort(pos, pos + N);
    
    for (int i = 0; i < N - 1; i++) {

        int j = i + 1;
        if (pos[j] - pos[i] + 1 >= dpL[i] + 1)
            dpL[j] = pos[j] - pos[i] + 1;
        else {

            while (j < N && pos[j] - pos[i] + 1 <= dpL[i] + 1) {
                dpL[j] = dpL[i] + 1;
                j++;
            }
            if (j >= N)
                break;
            i = j - 2;

        }

    }

    for (int i = N - 1; i > 0; i--) {

        int j = i - 1;
        if (pos[i] - pos[j] + 1 >= dpR[i] + 1)
            dpR[j] = pos[i] - pos[j] + 1;
        else {

            while (j >= 0 && pos[i] - pos[j] + 1 <= dpR[i] + 1) {
                dpR[j] = dpR[i] + 1;
                j--;
            }
            if (j < 0)
                break;
            i = j + 2;

        }

    }

    int i = 0, j = N - 1;
    while (i < j) {
        ans = std::min(ans, std::max( { (double) dpL[i], (double) dpR[j], (pos[j] - pos[i]) / 2.0 } ));
        if (dpL[i + 1] < dpR[j - 1]) {
            i++;
        } else {
            j--;
        }
    }

    std::printf("%.1f\n", ans);

    return 0;

}