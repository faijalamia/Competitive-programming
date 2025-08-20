#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cout << "Enter the row number of 1st matrix: ";
  int n1; cin >> n1;
  cout << "Enter the column number of 1st matrix:";
  int m1; cin >> m1;
  cout << "Enter the elements:\n";
  int a[n1][m1];
  for (int i = 0; i < n1; ++i){
    for (int j = 0; j < m1; ++j){
      cin >> a[i][j];
    }
  }

  cout << "Enter the row number of 2nd matrix: ";
  int n2; cin >> n2;
  cout << "Enter the column number of 2nd matrix:";
  int m2; cin >> m2;
  int b[n2][m2];
  cout << "Enter the elements:\n";
  for (int i = 0; i < n2; ++i){
    for (int j = 0; j < m2; ++j){
      cin >> b[i][j];
    }
  }
  vector<vector<int>>c(n1, vector<int>(m2, 0));
  for (int i = 0; i < n1; ++i){
    for (int j = 0; j < m2; ++j){
      for (int k = 0; k < m1; ++k){
        c[i][j] += (a[i][k] * b[k][j]);
      }
    }
  }
  for (int i = 0; i < n1; ++i){
    for (int j = 0; j < m2; ++j){
      cout << c[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}