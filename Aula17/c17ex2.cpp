#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n, x, a;
    long long int cWealthy, extraWealth;
    vector<int> p;

    for (cin >> t; t > 0; t--){
        cin >> n >> x;

        cWealthy = 0;
        extraWealth = 0;
        for (int i = 0; i < n; i++){
            cin >> a;
            if (a >= x){
                cWealthy++;
                extraWealth += a - x;
            }else p.push_back(x - a);
        }

        sort(p.begin(), p.end());
        for(int i = 0; i < p.size() && extraWealth > 0 && extraWealth >= p.at(i); i++){
            extraWealth -= p.at(i);
            cWealthy++;
        }
        cout << cWealthy << endl;
        p.clear();
    }
    return 0;
}