#include <bits/stdc++.h>
using namespace std;
long long T;
long long n, m;
long long arr[15][15];
long long must_arrive[15];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> arr[i][j];
            }
            must_arrive[i] = -1;
        }
        int mark = 0;
        for (int i = 1; i <= m; i++)
        {
            int k, v;
            cin >> k >> v;
            if (must_arrive[k] != -1 && must_arrive[k] != v)
            {
                mark = 1;
            }
            must_arrive[k] = v;
        }
        if (mark == 1)
        {
            cout << -1 << endl;
            continue;
        }
        long long dp[15][15] = {0};
        for (int i = 1; i <= n; i++)
        {
            if (must_arrive[n] == -1 || must_arrive[n] == i)
            {
                dp[n][i] = arr[n][i];
            }
            else
            {
                dp[n][i] = -1;
            }
            dp[i][0] = -1;
            dp[i][i + 1] = -1;
        }
        for (int row = n - 1; row >= 1; row--)
        {
            for (int col = 1; col <= row; col++)
            {
                if (must_arrive[row] == -1 || must_arrive[row] == col)
                {
                    int best_score = -1;
                    for (int i = -1; i <= 1; i++)
                    {
                        if (dp[row + 1][col + i] > best_score)
                        {
                            best_score = dp[row + 1][col + i];
                        }
                    }
                    if (best_score == -1)
                    {
                        dp[row][col] = -1;
                    }
                    else
                    {
                        dp[row][col] = best_score + arr[row][col];
                    }
                }
                else
                {
                    dp[row][col] = -1;
                }
            }
        }
        cout << dp[1][1] << endl;
    }
}