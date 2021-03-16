#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int N;
int K;
int S[50][50];
int breeds[50000];

int main()
{

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> breeds[i];
        breeds[i]--;
    }
    for (int i = 0; i < K; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < K; j++)
        {
            string tmp(1, line[j]);
            S[i][j] = stoi(tmp);
        }
    }

    vector<pair<int, int>> adj[N * K + 1];
    adj[N * K] = vector<pair<int, int>>{};
    for (int i = 0; i < N * K; i++)
    {
        adj[i] = vector<pair<int, int>>{};
        int x = i % N;
        int b = i / N;
        if (x != 0)
        {
            adj[i].push_back({i - 1, 1});
        }
        if (x != N - 1)
        {
            adj[i].push_back({i + 1, 1});
        }
        if (S[b][breeds[x]] == 1)
        {
            if (x != N - 1)
            {
                adj[i].push_back({N * breeds[x] + x, 0});
            }
            else
            {
                adj[i].push_back({N * K, 0});
            }
        }
    }

    deque<pair<int, int>> q; // pair of (index in dis, dis)
    int dis[N * K + 1];
    for (int i = 0; i <= N * K; i++)
    {
        dis[i] = -1;
    }
    dis[N * breeds[0]] = 0;
    q.push_back({N * breeds[0], 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop_front();
        for (auto e : adj[cur.f])
        {
            if (dis[e.f] == -1 || cur.s + e.s < dis[e.f])
            {
                dis[e.f] = cur.s + e.s;
                if (e.s == 0)
                {
                    q.push_front({e.f, cur.s});
                }
                else
                {
                    q.push_back({e.f, cur.s + 1});
                }
            }
        }
    }

    cout << dis[N * K] << endl;

    return 0;
}