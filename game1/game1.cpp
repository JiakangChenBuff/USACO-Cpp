#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 105

int N, dp[MAX][MAX], sum[MAX][MAX], arr[MAX];

int main()
{

    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> arr[i];

    }

    for (int i = 0; i < N; i++) {

        for (int j = i; j < N; j++) {

            for (int k = i; k <= j; k++) {

                sum[i][j] += arr[k];

            }

        }

    }

    for (int j = 0; j < N; j++) {

        int tmp = j;

        for (int i = 0; i < N; i++) {

            if (j == 0) {

                dp[i][tmp] = arr[i];

            } else {

                dp[i][tmp] = max(sum[i][tmp] - dp[i][tmp - 1], sum[i][tmp] - dp[i + 1][tmp]);

            }

            tmp++;

        }

    }

    cout << dp[0][N - 1] << " " << sum[0][N - 1] - dp[0][N - 1] << "\n";

    return 0;
}
