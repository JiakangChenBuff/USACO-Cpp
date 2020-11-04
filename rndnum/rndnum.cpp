#include <iostream>
#include <vector>

int S, F, c[32][32];

long long count(int num) {

    std::vector<int> bnum;
    while (num > 0) {
        bnum.insert(bnum.begin(), num % 2);
        num /= 2;
    }
    int size = bnum.size();

    long long total = 0;

    for (int i = 1; i <= size - 2; i++) {
        for (int j = i; j >= i / 2 + 1; j--) {
            total += c[i][j];
        }
    }

    int o = 1, z = 0;

    for (int j = 1; j < size; j++) {

        if (bnum[j]) {

            z++;
            for (int k = size - j - 1; k >= (size + 1) / 2 - z && k >= 0; k--) {
                total += c[size - j - 1][k];
            }
            z--; o++;

        } else {
            z++;
        }
        
    }

    if (z >= o) {
        total++;
    }

    return total;

}

int main() {

    std::cin >> S >> F;
    c[0][0] = 1;
    for (int i = 1; i < 32; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    if (S == 1) {
        std::cout << count(F) << "\n";
    } else {
        std::cout << (count(F) - count(S - 1)) << "\n";
    }

    return 0;

}