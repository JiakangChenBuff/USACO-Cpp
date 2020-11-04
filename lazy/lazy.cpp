#include <iostream>
#include <cmath>

#define MAX 400

int N, K, arr[MAX][MAX], rot[2 * MAX][2 * MAX], ps[2 * MAX][2 * MAX], o[2 * MAX][2 * MAX], ans = 0;

int main() {

    std::cin >> N >> K;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            std::cin >> arr[r][c];
            rot[N + (r - c)][std::abs(r - c) + 2 * std::min(r, c) + 1] = arr[r][c];;
            o[N + (r - c)][std::abs(r - c) + 2 * std::min(r, c) + 1] = 1;
        }
    }

    for (int r = 1; r < 2 * N; r++) {
        for (int c = 1; c < 2 * N; c++) {
            ps[r][c] = rot[r][c] + ps[r - 1][c] + ps[r][c - 1] - ps[r - 1][c - 1];
        }
    }

    for (int r = 1; r < 2 * N; r++) {
        for (int c = 1; c < 2 * N; c++) {
            if (o[r][c]) {

                int tlr = (r - K >= 1) ? r - K : 1;
                int tlc = (c - K >= 1) ? c - K : 1;
                int brr = (r + K < 2 * N) ? r + K : (2 * N - 1);
                int brc = (c + K < 2 * N) ? c + K : (2 * N - 1);
                ans = std::max(ans, ps[brr][brc] - ps[tlr - 1][brc] - ps[brr][tlc - 1] + ps[tlr - 1][tlc - 1]);

            }
        }
    }

    std::cout << ans << "\n";

    return 0;

}