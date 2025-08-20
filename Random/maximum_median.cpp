#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0; i<n; ++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l = v[n/2],r = 1e18,ans = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        int re = 0;
        for(int i = n/2; i<n; ++i){
            if(mid>v[i]){
                re+=(mid-v[i]);
            }
            if(re>k){
                break;
            }
        }
        if(re<=k){
            ans = mid;
            l = mid+1;    
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<'\n';

  return 0;
}