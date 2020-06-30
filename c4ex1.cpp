#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, j, i = 0;
    string t, sub = "";
    bool found = false;

    cin >> n >> k;
    cin >> t;

    for (j = 1; j < n && !found; j++){
        if(t.substr(0, n-j) == t.substr(j, n - 1)){
            found = true;
            sub = t.substr(n - j, j);
        }
    }

    if (!found) sub = t;

    while (k > 1) {
        t += sub;
        k--;
    }
    cout << t << endl;

    return 0;
}