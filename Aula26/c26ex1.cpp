#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> c, v;
    int a, i;
    bool found = false, foundSeg = false;

    for (i = 0; i < 4; i++){
        cin >> a;
        c.push_back(a);
    }
    sort(c.begin(), c.end());

    for (i = 0; i < 4 && !found; i++){
        for (int j = 0; j < 4; j++)
            if (j != i) v.push_back(c[j]);
        
        if (v[2] < v[1] + v[0] && v[1] < v[2] + v[0] && v[0] < v[1] + v[2]){
            cout << "TRIANGLE" << endl;
            found = true;
        }else if (v[2] == v[1] + v[0] && v[1] < v[2] + v[0] && v[0] < v[1] + v[2]) foundSeg = true;

        v.clear();
    }

    if (i == 4 && !foundSeg && !found) cout << "IMPOSSIBLE" << endl;
    else if (!found && foundSeg) cout << "SEGMENT" << endl;
    return 0;
}