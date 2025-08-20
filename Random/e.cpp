#include <bits/stdc++.h>
#define int long long
using namespace std;
// Calculate Result
int calc(deque<int> num, deque<char> op){
    int cur = 0, res = 0;
    char prv = '#', sign = '+';
    int sz = (int)num.size() + (int)op.size();
    bool ok = true;
    while (sz--){
        if (ok){
            ok ^= true;
            int bk = num.front();
            num.pop_front();
            if (prv == '#') cur = bk;
            else if (prv == '*') cur *= bk;
            else if (prv == '/') cur /= bk;
        }
        else{
            ok ^= true;
            char bk = op.front();
            op.pop_front();
            if (bk == '+' || bk == '-'){
                if (sign == '+') res += cur;
                else res -= cur;
                sign = bk;
                prv = '#';
                continue;
            }
            prv = bk;
        }
    }
    if (sign == '+') res += cur;
    else res -= cur;
    return res;
}
int Result(string s){
    deque<int> num;
    deque<char> op;
    for (auto& i : s){
        if (i == ')'){
            deque<int> tn;
            deque<char> to;
            while (1){
                tn.push_front(num.back());
                num.pop_back();
                char bk = op.back();
                op.pop_back();
                if (bk == '(') break;
                to.push_front(bk);
            }
            num.push_back(calc(tn, to));
            continue;
        }
        if (isdigit(i)) num.push_back(i - '0');
        else op.push_back(i);
    }
    return calc(num, op);
}

int32_t main(void){
    // input
    cout << "\nEnter the arithmetic expression:" << endl;
    string s;
    getline(cin >> ws, s);
    // remove whitespaces
    string store;
    for (auto& i : s) if (!isspace(i)) store.push_back(i);
    s = store;
    // precedence table
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
    // first part
    s = "$" + s + "$";
    map<char, int> mp;
    string sym = "+-*/^x()$";
    for (int i = 0; i < (int)sym.size(); ++i) mp[sym[i]] = i;
    while (1){
        if (s == "$$") break;
        string t, p;
        p.push_back('$');
        for (int i = 1; i < (int)s.size(); ++i){
            int c1 = ((isdigit(s[i - 1])) ? (5) : (mp[s[i - 1]]));
            int c2 = ((isdigit(s[i])) ? (5) : (mp[s[i]]));
            p.push_back(pre[c1][c2]);
            p.push_back(s[i]);
        }
        cout << p << endl;
        int psz = (int)p.size();
        for (int i = 0; i < psz; ++i){
            if (p[i] == '$'){
                t.push_back('$');
                continue;
            }
            if (p[i] == '>' || p[i] == '<' || p[i] == '=') continue;
            if (p[i] == '(' && i + 1 < psz && p[i + 1] == '=') continue;
            if (p[i] == ')' && i - 1 >= 0 && p[i - 1] == '=') continue;
            if (i - 1 >= 0 && i + 1 < psz){
                if (p[i - 1] == '<' && p[i + 1] == '>') continue;
            }
            t.push_back(p[i]);
        }
        s = t;
    }
    cout << "Value is: " << Result(store) << endl;
    return 0;
}
