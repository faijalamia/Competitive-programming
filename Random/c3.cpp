#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int>v, ans;
    for (int i = 0; i < n; ++i){
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    stack<int>x1, x2;
    if (v.size() % 2 == 0){
      for (int i = 0; i < n; ++i){
        if (i < n / 2){
          x1.push()
        }
      }
    }
  }
  return 0;
}