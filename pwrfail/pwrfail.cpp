#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

#define MAX 1005
#define INF 10000000

struct pole {
public:
    int index;
    double distance;

    pole(int i, double d) {
        index = i;
        distance = d;
    }
};

double e = 0.00000001;

struct cmp {
    bool operator()(pole a, pole b) const {
        return a.distance - b.distance > e;
    }
};

int N, W, pos[MAX][2];
double M, adj[MAX][MAX], dis[MAX];
priority_queue<pole, vector<pole>, cmp> q;
bool vis[MAX];

int main()
{

    cin >> N >> W >> M;

    for (int i = 0; i < N; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
            if (adj[i][j] - M > e) {
                adj[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < W; i++) {
        int p,q;
        cin >> p >> q;
        adj[p - 1][q - 1] = 0;
        adj[q - 1][p - 1] = 0;
    }

    for (int i = 1; i < N; i++) {
        dis[i] = INF;
    }

    q.emplace(pole(0, 0));
    while (!q.empty()) {
        pole curr = q.top();
        q.pop();
        if (vis[curr.index]) {
            continue;
        }
        vis[curr.index] = true;
        for (int i = 0; i < N; i++) {
            if (!(abs(adj[curr.index][i] - INF) < e)) {
                if (!vis[i] && dis[i] > curr.distance + adj[curr.index][i]) {
                    dis[i] = curr.distance + adj[curr.index][i];
                    q.emplace(pole(i, dis[i]));
                }
            }
        }
    }

    if (abs(dis[N - 1] - INF) < e) {
        cout << -1 << "\n";
    } else {
        cout << (int) (1000 * dis[N - 1]) << "\n";
    }

    return 0;
}
