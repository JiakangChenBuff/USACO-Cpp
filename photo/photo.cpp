#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

#define MAX 20008

int N, A[MAX];
std::unordered_map<int, std::vector<int> > m;

bool cmp(int a, int b) {
    auto x = m.at(a);
    auto y = m.at(b);

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (x[i] < y[i]) {
            cnt++;
        }
    }
    return cnt >= 3;
}

int main()
{

    std::cin >> N;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < N; i++) {
            int id; std::cin >> id;
            if (k == 0) {
                A[i] = id;
                m.insert(std::make_pair<int&, std::vector<int> > (id, std::vector<int> {i}));
            } else {
                std::vector<int> &x = m.at(id);
                x.push_back(i);
            }
        }
    }

    std::sort(A, A + N, cmp);

    for (int i = 0; i < N; i++) {
        std::cout << A[i] << "\n";
    }

    return 0;
}
