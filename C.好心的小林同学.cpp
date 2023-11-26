#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
#define ll long long
#define int ll

void solve()
{
    int a, b;
    cin >> a >> b;
    int a10 = 10, b10 = 10;
    while (a10 <= a)
    {
        a10 *= 10;
    }
    while (b10 <= b)
    {
        b10 *= 10;
    }
    if (a10 != b10)
    {
        while (a10 < b10)
        {
            a10 *= 10;
            a *= 10;
        }
        while (b10 < a10)
        {
            b10 *= 10;
            b *= 10;
        }
    }
    cout << a + b << endl;
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}