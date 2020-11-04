#include <iostream>

#define MAX 2501

int N, comb[MAX][MAX];

int main() {

    std::cin >> N;

    for (int i = 0; i < MAX; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for (int i = 2; i < MAX; i++) {
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }    
    }

    std::cout << (comb[N - 1][3] - 4 * comb[N - ((N - 1) / 2) - 1][3]) << "\n";

    return 0;

}