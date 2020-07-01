#include<bits/stdc++.h>
using namespace std;
int d[100];

int main(){
    int n, di, a, b, s = 0;

    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> di;
        d[i] = s + di;
        s += di;
    }
    cin >> a >> b;
    
    cout << d[b-1] - d[a-1] << endl;
    return 0;
}