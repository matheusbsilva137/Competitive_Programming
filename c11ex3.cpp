#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, num, meo = 0;
    vector<int> v, vSorted;;
    bool ord = true;
    
    while(cin >> n){
        meo = 0;
        for (i = 0; i < n; i ++){
            cin >> num;
            v.push_back(num);
            vSorted.push_back(num);
            if (ord && i > 0 && v.at(i - 1) > num) ord = false;
        }

        if (ord) cout << "Minimum exchange operations : " << meo << endl;
        else{
            sort(vSorted.begin(), vSorted.end());
            for (i = 0; i < vSorted.size(); i++){
                for(j = 0; j < v.size(); j++){
                    if (vSorted.at(i) == v.at(j)) {
                        meo += j;
                        v.erase(v.begin() + j);
                    }
                }
            }
            cout << "Minimum exchange operations : " << meo << endl;
        }
    }
    return 0;
}