#include <bits/stdc++.h>
using namespace std;
long long T;               // 测试样例数量
long long n, m;            // 金字塔的层数和每层必须选择的位置的数量
long long arr[15][15];     // 金字塔
long long must_arrive[15]; // 每层必须走的位置

int main()
{
    cin >> T;   // 测试样例数量
    while (T--) // 多组输入
    {
        cin >> n >> m;               // 金字塔的层数和每层必须选择的位置的数量
        for (int i = 1; i <= n; i++) // 输入金字塔
        {
            for (int j = 1; j <= i; j++) // 输入金字塔
            {
                cin >> arr[i][j]; // 输入金字塔
            }
            must_arrive[i] = -1; // 初始化每层必须走的位置
        }
        int mark = 0;                // 标记是否有冲突
        for (int i = 1; i <= m; i++) // 输入每层必须走的位置
        {
            int k, v;                                        // k表示层数，v表示位置
            cin >> k >> v;                                   // 输入必须走的位置
            if (must_arrive[k] != -1 && must_arrive[k] != v) // 已经有要走的板子，而且不是同一个
            {
                mark = 1; // 标记冲突
            }
            must_arrive[k] = v; // 记录必须走的位置
        }
        if (mark == 1) // 如果有冲突，那么就不可行
        {
            cout << -1 << endl; // 输出-1
            continue;           // 跳过这个测试样例
        }
        long long dp[15][15] = {0};  // dp[i][j]表示从第i层的第j个位置走到最底层的最大值
        for (int i = 1; i <= n; i++) // 初始化最底层的最大值
        {
            if (must_arrive[n] == -1 || must_arrive[n] == i) // 第n层，最底层 没有必走或者这个就是必走就设为那个值
            {
                dp[n][i] = arr[n][i]; // 最底层的最大值就是自己
            }
            else // 否则就是不可行
            {
                dp[n][i] = -1; // 否则设为-1表示不可行
            }
            dp[i][0] = -1;     // 边缘设为不可行
            dp[i][i + 1] = -1; // 边缘设为不可行
        }
        // int change_col[15][15]={0};//每个位置往下应该怎么走，做个记录
        for (int row = n - 1; row >= 1; row--) // 逐行回去
        {
            for (int col = 1; col <= row; col++) // 每个位置，往下面看
            {
                if (must_arrive[row] == -1 || must_arrive[row] == col) // 必走的或者该层没有必走的
                {
                    int best_score = -1;          // 最大值
                    for (int i = -1; i <= 1; i++) // 往下面看，只能看三个位置
                    {
                        if (dp[row + 1][col + i] > best_score) // 找最大值
                        {
                            // change_col[row][col]=i;
                            best_score = dp[row + 1][col + i]; // 更新最大值
                        }
                    }
                    if (best_score == -1) // 如果最大值是-1，说明没有可行的，那么这个位置也不可行
                    {
                        dp[row][col] = -1; // 设为-1
                    }
                    else // 否则就是有可行的
                    {
                        dp[row][col] = best_score + arr[row][col]; // 否则就是最大值加上这个位置的值
                    }
                }
                else // 该层有必走的
                {
                    dp[row][col] = -1; // 否则就是不可行
                }
            }
        }
        cout << dp[1][1] << endl; // 输出最大值
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