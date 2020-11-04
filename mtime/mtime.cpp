#include <iostream>
#include <utility>
#include <algorithm>

#define ii std::pair<int, int>
#define f first
#define s second
#define MAXN 1000

int N;
ii jobs[MAXN], a[MAXN];

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> jobs[i].s >> jobs[i].f;
    }
    std::sort(jobs, jobs + N);
    
    a[0] = std::make_pair(jobs[0].f - jobs[0].s, jobs[0].f);
    for (int i = 1; i < N; i++) {
        if (a[i - 1].s + jobs[i].s <= jobs[i].f) {
            a[i].f = a[i - 1].f;
            a[i].s = a[i - 1].s + jobs[i].s;
        } else {
            a[i].f = a[i - 1].f - (a[i - 1].s + jobs[i].s - jobs[i].f);
            a[i].s = jobs[i].f;
        }
    }
    std::cout << ((a[N - 1].f < 0) ? -1 : a[N - 1].f) << "\n";

    return 0;

}