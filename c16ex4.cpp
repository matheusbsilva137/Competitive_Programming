#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, i, j, trocas;
    int d, maxD = 1;
    string s;
    char letra = 'a';

    cin >> n >> k;
    cin >> s;

    while (letra <= 'b'){
        trocas = k;
        i = 0; j = 1;
        while (i < n && j < n && i < j){
            if (s.at(i) != letra && trocas > 0) trocas--;
            else if (trocas == 0 && s.at(i) != letra) {
                while (i < n && j < n && s.at(i) == letra){
                    i++;
                    j++;
                }
                if (i < n && j < n) {
                    i++;
                    trocas++;
                }
            }

            while (j < n && (s.at(j) == letra || trocas > 0)){
                if (s.at(j) != letra) trocas--;
                j++;
            }

            if (j == n && s.at(j-1) != letra) j--;
            d = j - i;

            if (d > maxD) maxD = d;
            i++;
        }
        letra++;
    }

    cout << maxD << endl;
    return 0;
}