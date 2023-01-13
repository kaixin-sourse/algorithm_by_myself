#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, phi[N], prims[N];
bool st[N];
//求1~n中所有数的欧拉函数 时间O(n);
void get_eulers(int n)
{
    phi[1] = 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        if (!st[i])
        {
            prims[j++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; prims[j] <= n / i; j++)
        {
            st[prims[j] * i] = true;
            if (i % prims[j] == 0)
            {
                phi[prims[j] * i] = phi[i] * prims[j];
                break;
            }
            phi[prims[j] * i] = phi[i] * (prims[j] - 1);
        }
    }
}
//求单个数的欧拉函数 时间O(根号n)
int get_euler(int n)
{
    int res = n;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}
int main()
{
    cin >> n;
    get_eulers(n);
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += phi[i];
    }
    //正确是12
    // cout << get_euler(21) << endl;
    cout << res << endl;
    return 0;
}