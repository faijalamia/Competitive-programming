#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << "Enter an arithmetic expression:\n";
    string s;
    getline(cin >> ws, s);
    string temp;
    int n = s.size();
    for (int i = 0; i < n; ++i){
        if (s[i] != ' '){
            temp.push_back(s[i]);
        }
    }
    s = temp;
    n = s.size();

    s = "$" + s + "S";
    map<char, int>mp;
    string sym = "+-*/^x()$";
    for (int i = 0; i < sym.size(); ++i){
        mp[sym[i]] = i;
    }
    for (auto [x, y] : mp){
        cout << x << ' ' << y << '\n';
    }

    vector<string> pre = {
        ">><<<<<>>",
        ">><<<<<>>",
        ">>>><<<>>",
        ">>>><<<>>",
        ">>>><<<>>",
        ">>>>>00>>",
        "<<<<<<<=0",
        ">>>>>00>>",
        "<<<<<<<00"
    };

    for (int ii = 0; ii <= 1; ++ii){
        if (s == "$$") break;
        string t, p;
        p.push_back('$');
        int c1 = -1, c2 = -1;
        for (int i = 1; i < s.size(); ++i){
            if (isdigit(s[i - 1])){
                c1 = 5;
            }
            else{
                c1 = mp[s[i - 1]];
            }
            if (isdigit(s[i])){
                c2 = 5;
            }
            else{
                c2 = mp[s[i]];
            }
            cout << "c1 = " << c1 << " " << "c2 = " << c2 << '\n';
            cout << "pre = " << pre[c1][c2] << '\n';
            p.push_back(pre[c1][c2]);
            p.push_back(s[i]);
        }
        cout << p << '\n';
        int psz = p.size();
        for (int i = 0; i < psz; ++i){
            if (p[i] == '$'){
                continue;
            }
            if (p[i] == '>' || p[i] == '<' || p[i] == '=') continue;
            if (p[i] == '(' && i + 1 < psz && p[i + 1] == '=')
                continue;
            if (p[i] == ')' && i - 1 > 0 && p[i - 1] == '=')
                continue;
            if (i - 1 > 0 && i + 1 < psz){
                if (p[i - 1] == '<' && p[i + 1] == '>')
                    continue;
            }
            t.push_back(p[i]);
        }
        s == t;
    }
    return 0;
}