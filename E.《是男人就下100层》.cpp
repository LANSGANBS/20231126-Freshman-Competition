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
            { // 已经有要走的板子，而且不是同一个
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
            { // 第n层，最底层 没有必走或者这个就是必走就设为那个值
                dp[n][i] = arr[n][i];
            }
            else
            { // 否则设为-1表示不可行
                dp[n][i] = -1;
            }
            dp[i][0] = -1; // 边缘设为不可行
            dp[i][i + 1] = -1;
        }
        // int change_col[15][15]={0};//每个位置往下应该怎么走，做个记录
        for (int row = n - 1; row >= 1; row--)
        { // 逐行回去
            for (int col = 1; col <= row; col++)
            { // 每个位置，往下面看
                if (must_arrive[row] == -1 || must_arrive[row] == col)
                { // 必走的或者该层没有必走的
                    int best_score = -1;
                    for (int i = -1; i <= 1; i++)
                    {
                        if (dp[row + 1][col + i] > best_score)
                        {
                            // change_col[row][col]=i;
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

/*
3
10 5
1
4 5
7 8 6
3 5 2 4
2 5 6 3 7
5 6 3 7 8 5
1 2 3 5 8 6 4
4 8 9 6 5 8 9 6
1 2 5 9 8 9 9 9 1
1 3 4 5 6 7 8 1 5 2
1 1
2 1
4 3
6 4
7 3

10 4
1
4 5


*/

/*
3
10 5
1
4 5
7 8 6
3 5 2 4
2 5 6 3 7
5 6 3 7 8 5
1 2 3 5 8 6 4
4 8 9 6 5 8 9 6
1 2 5 9 8 9 9 9 1
1 3 4 5 6 7 8 1 5 2
1 1
2 1
4 3
6 4
7 3


10 4
1
4 5
7 8 6
3 5 2 4
2 5 6 3 7
5 6 3 7 8 5
1 2 3 5 8 6 4
4 8 9 6 5 8 9 6
1 2 5 9 8 9 9 9 1
1 3 4 5 6 7 8 1 5 2
2 1
2 1
7 5
2 1


10 0
1
4 5
7 8 6
3 5 2 4
2 5 6 3 7
5 6 3 7 8 5
1 2 3 5 8 6 4
4 8 9 6 5 8 9 6
1 2 5 9 8 9 9 9 1
1 3 4 5 6 7 8 1 5 2

*/