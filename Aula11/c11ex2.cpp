#include<bits/stdc++.h>
#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000
using namespace std;

struct circulo {
    int x, y, r;
};

int main(){
    int q, x, y, r, i;
    char op;
    bool found = false;
    circulo c;
    vector<circulo> v;

    for(cin >> q; q > 0; q--){
        found = false;
        cin >> op >> x >> y >> r;

        if (op == 'A'){
            if (x <= MAX_WIDTH && y <= MAX_HEIGHT){
                for(i = 0; i < v.size() && !found; i++){
                    if (sqrt( pow(v.at(i).x - x, 2) + pow(v.at(i).y - y, 2) ) < v.at(i).r + r ){
                        //os pratos (círculos) se intersectam
                        cout << "No" << endl;
                        found = true;
                    }
                }
                if (!found){
                    c.x = x;
                    c.y = y;
                    c.r = r;
                    v.push_back(c);
                    cout << "Ok" << endl;
                }
            }else cout << "No" << endl;
        }else{
            for(i = 0; i < v.size() && !found; i++){
                if (v.at(i).x == x && v.at(i).y == y && v.at(i).r == r) {
                    v.erase(v.begin() + i);
                    found = true;
                }
            }
            if (found) cout << "Ok" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}