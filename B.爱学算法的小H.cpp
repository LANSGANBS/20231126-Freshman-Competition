#include <bits/stdc++.h>
using namespace std;
long long n, W;
long long T;

bool func(long long hard2count[], int day, int already)
{ // day天把hard2count都干完，且第一天已经学了already可不可行
    if (day == 0)
    { // 没时间了，检查是否学完
        for (int i = 1; i <= 10; i++)
        {
            if (hard2count[i] > 0)
                return false;
        }
        return true;
    }
    int mark = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (hard2count[i] > 0 && already + hard2count[i] <= W)
        { // 这一难度可以今天学完，试着学一下
            int t = hard2count[i];
            hard2count[i] = 0; // 学了设为0
            if (func(hard2count, day, already + t))
            { // 剩下的也能学完
                return true;
            }
            hard2count[i] = t; // 不行改回去
            mark = 1;
        }
    }
    if (mark == 0)
    { // 剩下的今天都学不了，那就新一天
        return func(hard2count, day - 1, 0);
    }
    else
    { // 如果今天能多学点都学不完肯定false了
        return false;
    }
}

int main()
{

    cin >> T;
    while (T--)
    {
        cin >> n >> W;
        long long hard2count[15] = {0}, total_sum = 0;
        for (long long i = 0; i < n; i++)
        {
            long long t;
            cin >> t;
            hard2count[t] += 1;
        }
        for (int i = 0; i <= 10; i++)
        {
            total_sum += hard2count[i];
        }
        long long day = total_sum / W + 1;
        long long ans = 10;
        ;
        while (day <= 10)
        {
            if (func(hard2count, day, 0))
            {
                ans = day;
                break;
            }
            day += 1;
        }
        cout << ans << endl;
    }
}

/*
1
5 4
1 2 1 2 1

*/