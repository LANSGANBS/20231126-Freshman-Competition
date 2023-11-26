#include <bits/stdc++.h>
using namespace std;
long long T;
long long n, k;
long long arr[200005];
vector<int> edge[200005];
int visited[200005];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        queue<int> que;
        visited[1] = 1;
        que.push(1);
        while (!que.empty())
        {
            int t = que.front();
            que.pop();
            int mark = 0;
            for (int i = 0; i < edge[t].size(); i++)
            {
                int subnode = edge[t][i];
                if (visited[subnode])
                {
                    continue;
                }
                else
                {
                    visited[subnode] = 1;
                    que.push(subnode);
                    // cout<<"visiting: "<<subnode<<endl;
                    if (arr[t] == arr[subnode] + k || arr[t] == arr[subnode] - k)
                    {
                        mark += 1;
                    }
                    // cout<<" is node? "<<mark<<endl;
                }
            }
            ans += mark;
        }
        cout << ans << endl;
    }
}

/*
2
6 3
1 2
1 3
2 4
2 5
1 6
1 1 4 5 1 4
1 114514
1919810
*/