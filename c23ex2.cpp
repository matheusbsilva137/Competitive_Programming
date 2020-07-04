#include<bits/stdc++.h>
using namespace std;

int nChars[105]; //nChars[i] é a quantidade de senhas de tamanho i

int main(){
    int n, k, waitTime, sumPas = 0;
    string s;

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> s;
        nChars[s.size()]++;
    }

    cin >> s;
    for (int i = 0; i < s.size(); i++){
        sumPas += nChars[i];
    }

    cout << sumPas + (sumPas/k)*5 + 1 << " " << sumPas + nChars[s.size()] + ((sumPas + nChars[s.size()] - 1)/k)*5 << endl;
    return 0;
}