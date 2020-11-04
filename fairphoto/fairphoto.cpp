#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

#define MAX 100003

int N, ps[MAX], pos[MAX], ans = 0;
std::map<int, int> first;

bool compare(int i, int j) {
    return std::abs(i) < std::abs(j);
}

int main() {

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; char t; std::cin >> x >> t; x++;
        pos[i] = x * (t == 'W' ? 1 : -1);
    }
    std::sort(pos + 1, pos + N + 1, compare);

    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + ((pos[i] > 0) ? 1 : -1);
    }

    for (int i = 1; i <= N; i++) {
        pos[i] = std::abs(pos[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (ps[i] >= 0 && i % 2 == 0) {
            ans = std::max(ans, pos[i] - pos[1]);            
        } else if (ps[i] >= 0) {
            ans = std::max(ans, pos[i] - pos[2]);
        } else if (ps[i] < 0 && first.count(ps[i])) {
            ans = std::max(ans, pos[i] - pos[first[ps[i]] + 1]);
        } else {
            first[ps[i]] = i;
        }
    }

    std::cout << ans << "\n";

    return 0;

}