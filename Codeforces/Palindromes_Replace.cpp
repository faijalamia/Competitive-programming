/*
https://codeforces.com/group/MWSDmqGsZm/contest/223206/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n / 2; ++i){
        if (s[i] == '?'){
            s[i] = s[n - 1 - i];
        }
        if (s[n - 1 - i] == '?'){
            s[n - 1 - i] = s[i];
        }
    }
    for (int i = 0; i < n; ++i){
        if (s[i] == '?'){
            s[i] = 'a';
        }
    }
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (s1 == s){
        cout << s;
    }
    else{
        cout << -1;
    }
    return 0;
}