#include <iostream>
#include <queue>
#include <vector>

#define MAX 50

int R, C, sr, sc, field[MAX][MAX], vis[MAX][MAX][2], dis[MAX][MAX][2], x = -1, maxr, minr = -1, dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
std::queue< std::vector<int> > q;

bool valid(int a, int b) {
    return a >= 0 && a < R && b >= 0 && b < C && !field[a][b];
}

int main() {

    std::cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char a; std::cin >> a;
            if (a == '*') {
                sr = r; sc = c;
            } else if (a == 'X') {
                field[r][c] = 1;
                if (x == -1) {
                    x = c;
                }
            }
        }
    }
    for (int r = 0; r < R; r++) {
        if (field[r][x]) {
            maxr = r;
            if (minr == -1) {
                minr = r;
            }
        }
    }

    q.push(std::vector<int> {sr, sc, 0});
    vis[sr][sc][0] = 1;

    if (sc >= x) {
        
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int nr = curr[0] + dr[i], nc = curr[1] + dc[i];
                if (valid(nr, nc) && !curr[2] && nc >= x && !vis[nr][nc][0]) {
                    dis[nr][nc][0] = dis[curr[0]][curr[1]][0] + 1;
                    vis[nr][nc][0] = 1;
                    q.push(std::vector<int> {nr, nc, 0});
                } else if (valid(nr, nc) && !curr[2] && curr[0] < minr && nc < x && !vis[nr][nc][1]) {
                    dis[nr][nc][1] = dis[curr[0]][curr[1]][0] + 1;
                    vis[nr][nc][1] = 1;
                    q.push(std::vector<int> {nr, nc, 1});
                } else if (valid(nr, nc) && curr[2] && (nc < x || (nr > maxr && nc >= x) || (curr[1] >= x && nc >= x)) && !vis[nr][nc][1]) {
                    dis[nr][nc][1] = dis[curr[0]][curr[1]][1] + 1;
                    vis[nr][nc][1] = 1;
                    q.push(std::vector<int> {nr, nc, 1});
                }
            }
        }

    } else {

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int nr = curr[0] + dr[i], nc = curr[1] + dc[i];
                if (valid(nr, nc) && !curr[2] && nc < x && !vis[nr][nc][0]) {
                    dis[nr][nc][0] = dis[curr[0]][curr[1]][0] + 1;
                    vis[nr][nc][0] = 1;
                    q.push(std::vector<int> {nr, nc, 0});
                } else if (valid(nr, nc) && !curr[2] && nr < minr && nc >= x && !vis[nr][nc][1]) {
                    dis[nr][nc][1] = dis[curr[0]][curr[1]][0] + 1;
                    vis[nr][nc][1] = 1;
                    q.push(std::vector<int> {nr, nc, 1});
                } else if (valid(nr, nc) && curr[2] && (nc >= x || (curr[0] > maxr && nc < x) || (curr[1] < x && nc < x)) && !vis[nr][nc][1]) {
                    dis[nr][nc][1] = dis[curr[0]][curr[1]][1] + 1;
                    vis[nr][nc][1] = 1;
                    q.push(std::vector<int> {nr, nc, 1});
                }
            }
        }

    }

    std::cout << dis[sr][sc][1] << "\n";

    return 0;
}