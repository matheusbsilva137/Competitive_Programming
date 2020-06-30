#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> s;
    int t, n, i, trk;

    for (cin >> t; t > 0; t--){
        i = 1;
        cin >> n;
        while (n > 0){
            cin >> trk;
            if (trk == i) i++;
            else if (s.empty() || s.back() > trk) s.push_back(trk);
            else {
                while (!s.empty() && s.back() == i){
                    s.pop_back();
                    i++;
                }
                s.push_back(trk);
            }
            n--;
        }

        while (!s.empty() && s.back() == i){
            s.pop_back();
            i++;
        }

        if (s.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
        s.clear();
    }
    return 0;
}