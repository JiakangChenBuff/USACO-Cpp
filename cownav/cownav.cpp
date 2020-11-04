#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

#define MAX 20
#define INF 500

int N, barn[MAX][MAX], dp[MAX][MAX][4][MAX][MAX][4], dir[4][2] {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}, ans = INF;
std::queue< std::vector<int> > q;

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N && !barn[r][c];
}

int main() {

    std::cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char a; std::cin >> a;
            if (a == 'H')
                barn[r][c] = 1;
        }
    }

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < N; l++)
                    for (int m = 0; m < N; m++)
                        for (int n = 0; n < 4; n++)
                            dp[i][j][k][l][m][n] = INF;

    dp[N - 1][0][1][N - 1][0][2] = 0;
    q.push(std::vector<int> {N - 1, 0, 1, N - 1, 0, 2});

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        int nr1, nc1, nd1, nr2, nc2, nd2;
        
        nr1 = curr[0] + dir[curr[2]][0];
        nc1 = curr[1] + dir[curr[2]][1];
        nd1 = curr[2];
        if (!isValid(nr1, nc1)) {
            nr1 = curr[0];
            nc1 = curr[1];
        }
        if (curr[0] == 0 && curr[1] == N - 1) {
            nr1 = curr[0];
            nc1 = curr[1];
        }
        nr2 = curr[3] + dir[curr[5]][0];
        nc2 = curr[4] + dir[curr[5]][1];
        nd2 = curr[5];
        if (!isValid(nr2, nc2)) {
            nr2 = curr[3];
            nc2 = curr[4];
        }
        if (curr[3] == 0 && curr[4] == N - 1) {
            nr2 = curr[3];
            nc2 = curr[4];
        }
        if (dp[nr1][nc1][nd1][nr2][nc2][nd2] == INF) {
            dp[nr1][nc1][nd1][nr2][nc2][nd2] = dp[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]][curr[5]] + 1;
            q.push(std::vector<int> {nr1, nc1, nd1, nr2, nc2, nd2});
        }

        nr1 = curr[0];
        nc1 = curr[1];
        nd1 = (curr[2] - 1 >= 0) ? curr[2] - 1 : 3;
        nr2 = curr[3];
        nc2 = curr[4];
        nd2 = (curr[5] - 1 >= 0) ? curr[5] - 1 : 3;
        if (dp[nr1][nc1][nd1][nr2][nc2][nd2] == INF) {
            dp[nr1][nc1][nd1][nr2][nc2][nd2] = dp[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]][curr[5]] + 1;
            q.push(std::vector<int> {nr1, nc1, nd1, nr2, nc2, nd2});
        }

        nd1 = (curr[2] + 1) % 4;
        nd2 = (curr[5] + 1) % 4;
        if (dp[nr1][nc1][nd1][nr2][nc2][nd2] == INF) {
            dp[nr1][nc1][nd1][nr2][nc2][nd2] = dp[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]][curr[5]] + 1;
            q.push(std::vector<int> {nr1, nc1, nd1, nr2, nc2, nd2});
        }

    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans = std::min(ans, dp[0][N - 1][i][0][N - 1][j]);
        }
    }

    std::cout << ans << "\n";

    return 0;

}