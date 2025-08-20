#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  string s;
  cin>>s;
  vector<string>ans;
  int n = s.size();
  string s1 = "";
  int cnt = 0;
  for(int i = 0; i<n; ++i){
    if(s[i]=='L'){
      cnt--;
      s1+='L';
    }
    else if(s[i]=='R'){
      cnt++;
      s1+='R';
    }
    if(s1.size()!=0 && cnt==0){
      ans.push_back(s1);
      s1 = "";
    }
  }
  cout<<ans.size()<<'\n';
  for(string i: ans){
    cout<<i<<'\n';
  }
  return 0;
}