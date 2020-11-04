#include <bits/stdc++.h>

struct State {

    int cost, r, c, smell;

    State(int w, int x, int y, int z) {
        cost = w; r = x; c = y; smell = z;
    }

    bool operator>(const State other) const {

        return cost > other.cost;

    }

};

#define MAX 1005
#define INF 1000000

int N, M, maze[MAX][MAX], dis[MAX][MAX][2], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, ans;
std::priority_queue<State, std::vector<State>, std::greater<State> > q;

bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int main()
{

    std::cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            std::cin >> maze[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            dis[r][c][0] = dis[r][c][1] = INF;
        }
    }

    q.push(State(0, 0, 0, 0));
    while (!q.empty()) {

        State curr = q.top(); q.pop();
        if (dis[curr.r][curr.c][curr.smell] <= curr.cost) continue;
        dis[curr.r][curr.c][curr.smell] = curr.cost;

        for (int i = 0; i < 4; i++) {
            int newr = curr.r + dr[i], newc = curr.c + dc[i];
            if (valid(newr, newc)) {

                if (maze[newr][newc] == 1 && dis[newr][newc][curr.smell] > dis[curr.r][curr.c][curr.smell] + 1) {
                    q.push(State(dis[curr.r][curr.c][curr.smell] + 1, newr, newc, curr.smell));
                }
                else if (maze[newr][newc] == 2 && dis[newr][newc][1] > dis[curr.r][curr.c][curr.smell] + 1) {
                    q.push(State(dis[curr.r][curr.c][curr.smell] + 1, newr, newc, 1));
                }
                else if (maze[newr][newc] == 3 && curr.smell == 1 && dis[newr][newc][1] > dis[curr.r][curr.c][1] + 1) {
                    q.push(State(dis[curr.r][curr.c][1] + 1, newr, newc, 1));
                }
                else if (maze[newr][newc] == 4) {
                    int cnt = 1;
                    while (maze[newr][newc] == 4 && valid(newr + dr[i], newc + dc[i]) && maze[newr + dr[i]][newc + dc[i]] && maze[newr + dr[i]][newc + dc[i]] != 3) {
                        cnt++;
                        newr += dr[i];
                        newc += dc[i];
                    }
                    int smell = (maze[newr][newc] == 2) ? 1 : 0;
                    if (dis[newr][newc][smell] > dis[curr.r][curr.c][curr.smell] + cnt) {
                        q.push(State(dis[curr.r][curr.c][curr.smell] + cnt, newr, newc, smell));
                    }
                }

            }
        }

    }

    ans = std::min(dis[N - 1][M - 1][0], dis[N - 1][M - 1][1]);
    std::cout << ((ans == INF) ? -1 : ans) << "\n";

    return 0;
}
