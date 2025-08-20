#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<string>keywords = { "include","using","namespace","define","int","long","float","string","char","double","bool","if","else","else if","else","main","while","for","case","switch","cout","default","return" };
int main(){
    cout << "Select any option:\n";
    cout << "1. To check identifier\n";
    cout << "2. To check keyword\n";
    cout << "3. To check comment\n";
    int op;
    cin >> op;
    if (op == 1){
        cout << "Please Enter any string:\n";
        string s;
        cin >> s;
        int n = s.size();
        if (keywords.find(s) != keywords.end()){
            cout << "This is not a valid identifier\n";
        }
        else{
            bool ok = true;
            for (int i = 0; i < n; ++i){
                if (i == 0 && isalpha(s[i])){
                    continue;
                }
                else if (isalnum(s[i])){
                    continue;
                }
                else{
                    ok = false;
                    break;
                }
            }
            if (ok){
                cout << "This is a valid identifier\n";
            }
            else{
                cout << "This is not a valid identifier\n";
            }
        }
    }
    else if (op == 2){
        cout << "Please enter a string:\n";
        string s;
        cin >> s;
        if (keywords.find(s) != keywords.end()){
            cout << "This is a valid keyword\n";
        }
        else{
            cout << "This is not a valid keyword";
        }
    }
    else{
        cout << "Please enter a string:\n";
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] == '/' && s[1] == '/'){
            cout << "This is a valid comment\n";
        }
        else if (s[0] == '/' && s[1] == '*' && s[n - 1] == '/' && s[n - 2] == '*'){
            cout << "This is a valid comment\n";
        }
        else{
            cout << "This is not a valid comment\n";
        }
    }
    return 0;
}