#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long arr[105][105];
int vis[105][105];
long long x, y;
long long T;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool dfs(int x, int y, int power)
{ // x,y那里能不能出去
    vis[x][y] = 1;
    if (x == 1 || x == n || y == 1 || y == m)
    { // 在边缘就能走出去了
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (!vis[nx][ny] && power >= arr[nx][ny])
        {
            if (dfs(nx, ny, power))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    cin >> T;
    while (T--)
    {
        cin >> n >> m >> x >> y;
        long long max_aij = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                vis[i][j] = 0;
                if (arr[i][j] > max_aij)
                    max_aij = arr[i][j];
            }
        }
        int left = 0, right = max_aij;
        if (dfs(x, y, 0))
            right = 0; // 以防left也能行
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (mid == left)
            { // right==left+1,ans=right
                break;
            }
            if (dfs(x, y, mid))
            { // mid can do it,then find smaller mid
                right = mid;
            }
            else
            { // mid can't do it
                left = mid;
            }
        }
        cout << right << endl;
    }
}

/*
1
5 5 3 4
9 5 6 2 3
9 9 5 9 3
5 6 2 0 10
10 2 3 5 6
9 0 12 2 4

*/