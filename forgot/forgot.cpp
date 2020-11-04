#include <iostream>
#include <string>
#include <cmath>

#define MAX 1000

int L, NW;
std::string words[MAX], dp[MAX+1], rem;

int main() {

    std::cin >> L >> NW;

    std::cin >> rem;

    for (int i = 1; i <= L; i++) {
        dp[i] = "{{{{{{{{{{{{{{{{{{{{";
    }

    for (int i = 0; i < NW; i++) {
        std::cin >> words[i];
    }

    for (int i = 1; i <= L; i++) {

        for (int j = 0; j < NW; j++) {

            int size = words[j].size();

            if (i - size >= 0 && dp[i - size] != "?") {

                bool matches = true;
                
                for (int k = i - size; k < i; k++) {

                    if (rem[k] != '?' && rem[k] != words[j][k + size - i]) {
                        matches = false;
                        break;
                    }

                }

                if (matches) {

                    dp[i] = std::min(dp[i], dp[i - size] + words[j]);

                }

            }

        }

    }

    std::cout << dp[L] << "\n";

    return 0;
}