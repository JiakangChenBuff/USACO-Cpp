#include <bits/stdc++.h>

using namespace std;

int adj[26][26];
bool seen[26];
vector<char> letters;
string str;

int main()
{

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (!seen[str[i] - 97])
        {
            seen[str[i] - 97] = true;
            letters.push_back(str[i]);
        }
        if (i != str.length() - 1)
        {
            adj[str[i] - 97][str[i + 1] - 97]++;
        }
    }

    int n = letters.size();
    int dp[1 << n];
    dp[0] = 1;
    for (int i = 1; i < 1 << n; i++)
    {
        dp[i] = str.length();
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                int tmp = dp[i ^ (1 << j)];
                for (int k = 0; k < n; k++)
                {
                    if ((i & (1 << k)) != 0)
                    {
                        tmp += adj[letters[k] - 97][letters[j] - 97];
                    }
                }
                dp[i] = min(dp[i], tmp);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}