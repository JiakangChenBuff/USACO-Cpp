#include <iostream>
#include <set>
#include <cmath>

#define MAX 10010

int N, M, arr[MAX][3], ans;
std::multiset<int> in, out;
std::multiset<int>::iterator in_it, out_it;

int main()
{

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> arr[i][0];
    }

    for (int i = 0; i < M; i++) {
        int s, e; std::cin >> s >> e;
        arr[s][2]++; arr[e][1]++;
    }

    for (int i = 1; i <= N; i++) {

        if (arr[i][1] - arr[i][2] > 0) {

            for (int j = 0; j < arr[i][1] - arr[i][2]; j++) {
                in.insert(arr[i][0]);
            }

        } else if (arr[i][1] - arr[i][2] < 0) {

            for (int j = 0; j < arr[i][2] - arr[i][1]; j++) {
                out.insert(arr[i][0]);
            }

        }

    }

    in_it = in.begin(); out_it = out.begin();
    while (in_it != in.end()) {
        ans += std::abs(*in_it - *out_it);
        in_it++; out_it++;
    }

    std::cout << ans << "\n";

    return 0;
}
