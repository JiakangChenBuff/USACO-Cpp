#include <iostream>
#include <stack>

#define MAXN 50000

int N, W, y[MAXN], ans = 0;
std::stack<int> s;

int main() {

    std::cin >> N >> W;
    for (int i = 0; i < N; i++) {
        std::cin >> ans >> y[i];
    }
    ans = 0;
    s.push(0);
    for (int i = 0; i < N; i++) {
        while(s.top() > y[i]) {
            s.pop();
        }
        if (s.top() != y[i]) {
            s.push(y[i]);
            ans++;
        }
    }
    std::cout << ans << '\n';

    return 0;

}