#include<bits/stdc++.h>
using namespace std;
set<string>keywords = { "int","float","double","long","string","char","for","if","else","while","case","switch","default","main" };
set<char>operators = { '>','<','=','+','-','*','/','^','&','|' };
set<char>symbols = { '(',')','{','}','[',']',';',',' };

bool is_symbol(char& s){
    if (symbols.find(s) != symbols.end()){
        return true;
    }
    else{
        return false;
    }
}
bool is_operator(char& s){
    if (operators.find(s) != operators.end()){
        return true;
    }
    else{
        return false;
    }
}
bool is_all_digit(string& s){
    int n = s.size();
    for (int i = 0; i < n; ++i){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}
int main(){
    cout << "Enter the expression of lexical analysis\n";
    string s;
    getline(cin, s);
    int n = s.size();
    set<string>operatorList, keywordList, identifierList, constantList;
    set<char>symbolList;
    string token = "";
    for (int i = 0; i < n; ++i){
        if (!isalnum(s[i])){
            if (is_symbol(s[i])){
                symbolList.insert(s[i]);
            }
            else if (is_operator(s[i])){
                if (i + 1 < n && is_operator(s[i + 1])){
                    string s1 = string(1, s[i]) + string(1, s[i + 1]);
                    operatorList.insert(s1);
                    i++;
                }
                else{
                    operatorList.insert(string(1, s[i]));
                }
            }
            if (token.size() > 0){
                if (keywords.find(token) != keywords.end()){
                    keywordList.insert(token);
                    token = "";
                }
                else{
                    if (is_all_digit(token)){
                        constantList.insert(token);
                        token = "";
                    }
                    else{
                        identifierList.insert(token);
                        token = "";
                    }
                }
            }
        }
        else{
            token += s[i];
        }
    }
    for (auto i : identifierList){
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : keywordList){
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : constantList){
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : symbolList){
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : operatorList){
        cout << i << ' ';
    }
}