#include <bits/stdc++.h>
using namespace std;
//#define int long long
int32_t main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    for(int i = 0; i<n; ++i){
        cin>>v[i];
    }
   // sort(v.begin(),v.end());
    long long l = 1,r = 1e18,m;
    long long ans = -1;
    while(l<=r){
        m = l+(r-l)/2;
        long long p = 0;
        for(int i = 0; i<n; ++i){
            p+=(m/v[i]);
            if(p>=t){
                break;
            }
        }
        if(p>=t){
            r = m-1;
            ans = m;
        }
        else{
            l = m+1;
        }
    }
    cout<<ans<<'\n';
  return 0;
}