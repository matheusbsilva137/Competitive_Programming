#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, n, i;
    int x, y;
    vector<pair<int, int>> v;

    cin >> s >> n;
    for (i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v. begin(), v.end());
    for (i = 0; i < n && s > v.at(i).first; s+= v.at(i).second, i++);

    if (i == n) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
};