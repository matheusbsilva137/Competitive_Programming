#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, k, n1, n2, maxSize = 1, pot2 = 1, numero, maxPot;
    bool busca1, busca2;
    vector<int>::iterator it, it2;

    cin >> n;
    vector<int> x;
    for(i = 0; i < n; i++) {
        cin >> numero;
        x.push_back(numero);
    }

    sort(x.begin(), x.end());
    maxPot = ceil(log2(abs(x.back() - x.front())));
    for(i = 0; i < n - 1; i++, pot2 = 1){
        for (j = 0; j <= maxPot; j++, pot2 *= 2){
            busca1 = false;
            busca2 = false;

            if (binary_search(x.begin(), x.end(), x.at(i) + pot2)) busca1 = true;
            if (binary_search(x.begin(), x.end(), x.at(i) - pot2)) busca2 = true;

            if (busca1 && busca2){
                cout << "3" << endl << x.at(i) << " " << x.at(i) + pot2 << " " << x.at(i) - pot2 << endl;
                return 0;
            }else if ( (busca1 || busca2) && maxSize == 1){                
                maxSize = 2;
                n1 = x.at(i);
                if (busca1) n2 = x.at(i) + pot2;
                else n2 = x.at(i) - pot2;
            }
        }
    }
    
    if (maxSize == 2) cout << maxSize << endl << n1 << " " << n2 << endl;
    else cout << "1" << endl << x.at(0) << endl;
    return 0;
}
