#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 100008

struct cmp1 {
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

bool cmp2(std::vector<int> a, std::vector<int> b) {
    return a[0] > b[0];
}


int N, B, ans[MAX], prev[MAX], next[MAX], maxDis = 1;
std::vector< std::vector<int> > boots(MAX, std::vector<int>(3));
std::priority_queue< std::pair <int, int>, std::vector < std::pair <int, int> >, cmp1 > snow;

int main()
{
    std::cin >> N >> B;

    prev[0] = -1;
    next[0] = 1;
    for (int i = 1; i < N - 1; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    prev[N - 1] = N - 2;
    next[N - 1] = -1;

    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        snow.emplace(std::make_pair(x, i));
    }

    for (int i = 0; i < B; i++) {
        std::cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }

    std::sort(boots.begin(), boots.begin() + B, cmp2);

    for (int i = 0; i < B; i++) {
        while (snow.top().first > boots[i][0]) {
            maxDis = std::max(maxDis, next[snow.top().second] - prev[snow.top().second]);
            next[prev[snow.top().second]] = next[snow.top().second];
            prev[next[snow.top().second]] = prev[snow.top().second];
            snow.pop();
        }
        ans[boots[i][2]] = (boots[i][1] >= maxDis) ? 1 : 0;
    }

    for (int i = 0; i < B; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
