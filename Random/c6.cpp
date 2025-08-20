#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if (n >= k)
        {
            k--;
            while (n > 1)
            {
                n -= k;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}