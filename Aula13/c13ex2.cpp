#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num, i, scoreS = 0, scoreD = 0;
    bool turnS = true;
    list<int> v;

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> num;
        v.push_back(num);
    }

    while (v.size() > 0){
        if (turnS){
            if (v.back() > v.front()){
                scoreS += v.back();
                v.pop_back();
            }else{
                scoreS += v.front();
                v.pop_front();
            }
            turnS = false;
        }else{
            if (v.back() > v.front()){
                scoreD += v.back();
                v.pop_back();
            }else{
                scoreD += v.front();
                v.pop_front();
            }
            turnS = true;
        }
    }

    cout << scoreS << " " << scoreD << endl;
    return 0;
}