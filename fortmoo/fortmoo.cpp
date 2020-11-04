#include <iostream>
#include <cmath>

#define MAX 205

int N, M, ans = 0, grid[MAX][MAX], ps[MAX][MAX];

int main() {

    std::cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 0; c < M; c++) {
            char a; std::cin >> a;
            if (a == 'X') grid[r][c] = 1;
        }
    }

    for (int c = 0; c < M; c++) {
        for (int r = 1; r <= N; r++) {
            ps[r][c] = ps[r - 1][c] + grid[r][c];
        }
    }

    for (int up = 1; up <= N; up++) {
        for (int low = up; low <= N; low++) {

            for (int c = 0; c < M; c++) {

                if (!(ps[low][c] - ps[up - 1][c])) {

                    int right = c;
                    while (right < M && !grid[up][right] && !grid[low][right]) {

                        if (!(ps[low][right] - ps[up - 1][right])) {
                            ans = std::max(ans, (low - up + 1) * (right - c + 1));
                        }

                        right++;

                    }
                    c = right;

                }

            }

        }
    }

    std::cout << ans << "\n";

    return 0;

}