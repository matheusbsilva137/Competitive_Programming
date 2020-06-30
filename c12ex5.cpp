#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int qT = 0;
bool trocou;
string s, t, res;

void troca(){
    for (j = i + 1; j < n && !trocou; j++){
        if (s.at(j) != t.at(i) && t.at(j) != s.at(j)){
            swap(s.at(j), t.at(i));
            qT++;
            res +=  to_string(j+1)+ " " + to_string(i+1) + "\n";
            trocou = true;
        }
    }
}

int main(){
    int n, i, j, qA = 0, qB = 0;
    char c;

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> c;
        if (c == 'a') qA++;
        else qB++;
        s += c;
    }

    for (i = 0; i < n; i++){
        cin >> c;
        if (c == 'a') qA++;
        else qB++;
        t += c;
    }
    
    if (qA%2 != 0 || qB%2 != 0) cout << "-1" << endl;
    else{
        for (i = 0; i < n; i++){
            trocou = false;
            if (s.at(i) != t.at(i)){
                troca();

                if (!trocou){
                    res += to_string(i+1) + " " + to_string(i+1) + "\n";
                    swap(s.at(i), t.at(i));
                    qT++;
                    troca();
                }
            }
        }

        cout << qT << endl;
        cout << res;
    }

    return 0;
}