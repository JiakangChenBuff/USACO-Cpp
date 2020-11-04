#include <bits/stdc++.h>

using namespace std;

#define MAX 100008

int N, arr[MAX], cnt, interval[MAX][2], ans;
bool vis[MAX], can = true;
vector<int> painting;
stack<int> s;

int main()
{

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    painting.push_back(arr[0]);
    if (painting.back() != 0) {
        painting.insert(painting.begin(), 0);
    }
    for (int i = 1; i < N; i++) {
        if (arr[i] != painting.back()) {
            painting.push_back(arr[i]);
        }
    }
    if (painting.back() != 0) {
        painting.push_back(0);
    }

    for (int i = 0; i < (int) painting.size(); i++) {
        if (vis[painting[i]]) {
            interval[painting[i]][1] = i;
        } else {
            interval[painting[i]][0] = i;
            interval[painting[i]][1] = i;
            vis[painting[i]] = true;
        }
    }

    for (int i = 0; i < (int) painting.size(); i++) {
        if (i == interval[painting[i]][0]) {
            if (s.size() == 0 || interval[painting[i]][1] < s.top()) {
                s.push(interval[painting[i]][1]);
            } else {
                can = false;
                break;
            }
        }
        if (i == interval[painting[i]][1]) {
            s.pop();
        }
    }

    if (can) {
        for (int i = 0; i < (int) painting.size(); i++) {
            if (i == interval[painting[i]][0]) {
                cnt++;
                ans = max(ans, cnt);
            }
            if (i == interval[painting[i]][1]) {
                cnt--;
            }
        }

        cout << ans - 1 << "\n";

    } else {
        cout << -1 << "\n";
    }

    return 0;
}
