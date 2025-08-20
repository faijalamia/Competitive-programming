#include <bits/stdc++.h>
using namespace std;
//#define int long long
//https://codeforces.com/contest/1915/problem/F
//https://codeforces.com/problemset/problem/1837/B
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long 
int32_t main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<int,int>>vp(n);
    for(int i=0; i<n; ++i){
      int x,y;
      cin>>x>>y;
      vp[i]={x,y};
    }
    sort(vp.begin(),vp.end());
    ordered_set s;
    for(int i=0; i<n; ++i){
      s.insert(vp[i].second);
    }
    int cnt=0;
    for(int i=0; i<n; ++i){
      cnt+=s.order_of_key(vp[i].second);
      s.erase(vp[i].second);
    }
    cout<<cnt<<'\n';
  }
  return 0;
}