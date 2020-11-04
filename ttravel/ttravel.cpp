#include <iostream>

#define MAX 80010

int N, val[MAX], parent[MAX], ptr[MAX];

int main()
{

    std::cin >> N;

    val[0] = -1;
    parent[0] = -1;
    ptr[0] = 0;

    for (int i = 1; i <= N; i++) {
        char c; int k; std::cin >> c;

        if (c == 'a') {
            std::cin >> k;
            val[i] = k;
            parent[i] = ptr[i - 1];
            ptr[i] = i;
        } else if (c == 's') {
            ptr[i] = parent[i - 1];
            val[i] = val[ptr[i]];
            parent[i] = parent[ptr[i]];
        } else {
            std::cin >> k;
            val[i] = val[k - 1];
            parent[i] = parent[k - 1];
            ptr[i] = ptr[k - 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << val[i] << "\n";
    }

    return 0;
}
