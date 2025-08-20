#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ok = 0;
  for (int i = 2; i <= n * n; ++i){
    if (n % i == 0){
      ok = -1;
      break;
    }
  }
  if (ok) cout << n << " is a prime number\n";
  else cout << n << " is not a prime number\n";
  return 0;
}