#include <iostream>
#include <queue>

#define MAX 100005
#define ll long long

ll N, arr[MAX], find[2 * MAX], start, ans = 0;
std::queue<ll> q;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        find[i] = std::max((ll) 0, find[i - 1] + arr[i - 1] - 1);
    }
    for (int i = N; i < 2 * N; i++) {
        find[i] = std::max((ll) 0, find[i - 1] + arr[(i - 1) % N] - 1);
        if (!find[i]) {
            start = i - N;
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < arr[(i + start) % N]; j++) {
            q.push(i);
        }
        ans = ans +  (i - q.front()) * (i - q.front());
        q.pop();
    }

    std::cout << ans;

    return 0;

}