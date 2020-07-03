#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> p;
    string s;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        int j;
        for (j = 0; j < s.size() ; j++){
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') p.push(s[j]);
            else if (s[j] == ')' && !p.empty() && p.top() == '(') p.pop();
            else if (s[j] == ']' && !p.empty() && p.top() == '[') p.pop();
            else if (s[j] == '}' && !p.empty() && p.top() == '{') p.pop();
            else{
                cout << "NO" << endl;
                j = s.size();
            }
        }
        if (p.empty() && j == s.size()) cout << "YES" << endl;
        while (!p.empty()) p.pop(); 
    }

    return 0;
}