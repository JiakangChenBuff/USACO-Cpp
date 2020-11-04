#include <iostream>

#define N 100

struct UnionFind {

    int par[N];
    int rnk[N];

    UnionFind(int a) {
        for (int i = 1; i <= 5; i++) {
            par[i] = i;
            rnk[i] = 1;
        }
    }

    int Find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = Find(par[x]);
    }

    void Union(int x, int y) {
        int a = Find(x);
        int b = Find(y);
        if (rnk[a] == rnk[b]) {
            par[a] = b;
            rnk[b]++;
        } else if (rnk[a] > rnk[b]) {
            par[b] = a;
        } else {
            par[a] = b;
        }
    }

};

int main()
{

    UnionFind u(5);

    u.Union(1, 2);
    u.Union(2, 5);
    u.Union(3, 5);

    std::cout << std::boolalpha << (u.Find(1) == u.Find(3)) << "\n";
    std::cout << std::boolalpha << (u.Find(3) == u.Find(5)) << "\n";
    std::cout << std::boolalpha << (u.Find(5) == u.Find(1)) << "\n";
    std::cout << std::boolalpha << (u.Find(4) == u.Find(4)) << "\n";
    std::cout << std::boolalpha << (u.Find(1) == u.Find(4)) << "\n";
    std::cout << std::boolalpha << (u.Find(2) == u.Find(4)) << "\n";

    return 0;
}
