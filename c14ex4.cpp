#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, i, a, b;
    cin >> n >> m;
    vector<int> ans;
    pair<int, int> maxPair;

    vector<pair<int, int>> funcLib[m];

    for (i = 0; i < n; i++){
        cin >> a >> b;
        funcLib[a-1].push_back(make_pair(i+1, b);
    }

    i = 0;
    while (i < m && i > 0){
        ans.push_back(*max_element(funcLib[i].begin(), funcLib[i].end()));
    }

    if (i == m){
        cout << "YES" << endl;
        for (i = 0; i < ans.size(); i++) cout << ans.at(i) << " ";
        cout << endl;
    }else cout << "NO" << endl;

    return 0;
}