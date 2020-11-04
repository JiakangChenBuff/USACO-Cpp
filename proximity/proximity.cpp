#include <iostream>
#include <set>

#define MAX 50000

int N, K, id[MAX], ans = 0;
std::multiset<int> s;

int main() {

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> id[i];
    }

    for (int i = 0; i <= K; i++) {
        if (s.count(id[i])) {
            ans = std::max(ans, id[i]);
        }
        s.insert(id[i]);
    }

    for (int i = K + 1; i < N; i++) {
        s.erase(s.find(id[i - K - 1]));
        if (s.count(id[i])) {
            ans = std::max(ans, id[i]);
        }
        s.insert(id[i]);
    }

    std::cout << ans << "\n";

    return 0;

}