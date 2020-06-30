#include<bits/stdc++.h>
using namespace std;

int main(){
    string t, sl;
    int i, j = 0, tam, slTam, end;
    bool solucao = true, contemLetras = false;

    cin >> t;
    tam = t.size();

    for (i = tam - 1; i >= tam/2 && t[i] != 'a'; i--) sl = t[i] + sl;
    end = i + 1;
    slTam = sl.size();

    for(i = 0; i < end && end <= tam && slTam > 0 && j < slTam; i++){
        if(t[i] != 'a'){
            if(t[i] == sl[j]){
                j++;
            }else{
                i--;
                end++;
                sl.erase(sl.begin());
                slTam--;
            }
        }else solucao = false;
        if(i + 1 == end && j < slTam){
            end++;
            sl.erase(sl.begin());
            slTam--;
        }
    }

    while (i < end && t[i] == 'a') i++;

    if(slTam <= 0) {
        for(i = 0; i < tam; i++)
            if(t[i] != 'a') contemLetras = true;
        if(contemLetras){
            cout << ":(" << endl;
            return 0;
        }
    }
    if( (end < tam || solucao) && j == slTam && i == end) cout << t.substr(0, end) << endl;
    else cout << ":(" << endl;

    return 0;
}