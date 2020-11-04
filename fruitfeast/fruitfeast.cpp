#include <iostream>

using namespace std;

#define MAX 5000005

int T, A, B;
bool dp[MAX][2];

int main()
{

    cin >> T >> A >> B;
    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 1; i <= T; i++) {
        if (i - A >= 0) {
            dp[i][0] = dp[i][0] || dp[i - A][0];
        }
        if (i - B >= 0) {
            dp[i][0] = dp[i][0] || dp[i - B][0];
        }
    }
    for (int i = 1; i <= T; i++) {
        if (i - A >= 0) {
            dp[i][1] = dp[i][1] || dp[i - A][1];
        }
        if (i - B >= 0) {
            dp[i][1] = dp[i][1] || dp[i - B][1];
        }
        if (2 * i <= T) {
            dp[i][1] = dp[i][1] || dp[2 * i][0];
        }
        if (2 * i + 1 <= T) {
            dp[i][1] = dp[i][1] || dp[2 * i + 1][0];
        }
    }

    for (int i = T; i >= 0; i--) {
        if (dp[i][0] || dp[i][1]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
