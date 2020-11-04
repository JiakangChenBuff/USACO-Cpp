#include <bits/stdc++.h>

using namespace std;

ifstream fin("billboard.in");
ofstream fout("billboard.out");

int arr[12];

int main()
{

    fin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8] >> arr[9] >> arr[10] >> arr[11];

    int area = (arr[2] - arr[0]) * (arr[3] - arr[1]) + (arr[6] - arr[4]) * (arr[7] - arr[5]);

    if (min(arr[2], arr[10]) - max(arr[0], arr[8]) >= 0 && (min(arr[3], arr[11]) - max(arr[1], arr[9]) >= 0)) {

        area -= (min(arr[2], arr[10]) - max(arr[0], arr[8])) * (min(arr[3], arr[11]) - max(arr[1], arr[9]));

    }

    if ((min(arr[6], arr[10]) - max(arr[4], arr[8])) >= 0 && (min(arr[7], arr[11]) - max(arr[5], arr[9]) >= 0)) {

        area -= (min(arr[6], arr[10]) - max(arr[4], arr[8])) * (min(arr[7], arr[11]) - max(arr[5], arr[9]));

    }

    fout << area << "\n";

    return 0;
}
