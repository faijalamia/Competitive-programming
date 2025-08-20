#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int ans = 0;
        for (int i = 0; i <= n; ++i){
            int cal = i * a + (n - i) * b + max(c, d) * i * (n - i);
            ans = max(ans, cal);
        }
        cout << ans << '\n';
    }
    return 0;
}