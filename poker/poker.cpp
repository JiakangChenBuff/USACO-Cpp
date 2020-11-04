#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100005

int N, arr[MAX];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long sum = arr[0] + arr[N - 1];
    for (int i = 1; i < N; i++) {
        sum += abs(arr[i] - arr[i - 1]);
    }
    cout << sum / 2;
    return 0;
}
