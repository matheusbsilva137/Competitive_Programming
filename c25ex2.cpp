#include<bits/stdc++.h>
using namespace std;
deque<long long int> c1, c2;
vector<long long int> cods;

int main(){
    int n, k1, k2, c, f = 0;
    long long int cod = 0;
    bool loop = false;

    cin >> n >> k1;
    for (int i = 0; i < k1; i++){
        cin >> c;
        c1.push_back(c);
    }

    cin >> k2;
    for (int i = 0; i < k2; i++){
        cin >> c;
        c2.push_back(c);
    }

    while(!c1.empty() && !c2.empty() && !loop){
        bool stA = false, stB = false;
        cod = 0;
        for (int i = 0; i < c1.size(); i++) cod = stoll(to_string(cod) + to_string(c1.at(i)));
        if (find(cods.begin(), cods.end(), cod) == cods.end()) cods.push_back(cod);
        else stA = true;

        cod = 0;
        for (int i = 0; i < c2.size(); i++) cod = stoll(to_string(cod) + to_string(c2.at(i)));
        if (find(cods.begin(), cods.end(), cod) == cods.end()) cods.push_back(cod);
        else stB = true;

        if (stA && stB) loop = true;

        f++;
        int a = c1.front(), b = c2.front();
        c1.pop_front();
        c2.pop_front();
        if (a > b){
            c1.push_back(b);
            c1.push_back(a);
        }else{
            c2.push_back(a);
            c2.push_back(b);
        }
    }
    if (loop) cout << -1 << endl;
    else cout << f << " " << ((c1.empty()) ? "2" : "1") << endl;
    return 0;
}