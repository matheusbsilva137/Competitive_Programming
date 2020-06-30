#include<bits/stdc++.h>
using namespace std;

bool comparaLargura(string &a, string &b){
    return (a.size() < b.size());
}

bool isSubstring(string a, string b){
    int n = a.size(), m = b.size(), i;

    for(i = 0; i <= m - n; i++)
        if (b.substr(i, n) == a) return true;
    return false;
}

int main(){
    int n, i;
    cin >> n;
    string *s = new string[n];

    for (i = 0; i < n; i++) cin >> s[i];
    sort(s, s+n, comparaLargura);
    for (i = 1; i < n && isSubstring(s[i-1], s[i]); i++);
    
    if (i == n){
        cout << "YES" << endl;
        for (i = 0; i < n; i++) cout << s[i] << endl;
    }else cout << "NO" << endl;
    
}