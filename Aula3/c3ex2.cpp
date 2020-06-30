#include<bits/stdc++.h>
using namespace std;

struct twoGram{
    string tg;
    int ocur = 0;
};

int main(){
    int n, i, j = 0, size = -1, maxOcur = 0;
    string s, tgAtual;
    twoGram* tgs = new twoGram[99];

    cin >> n;
    cin >> s;

    for (i = 0; i <= n - 2; i++){
        j = size;
        tgAtual = s.substr(i, 2);
        while (j >= 0 && tgAtual.compare(tgs[j].tg) != 0) j--;
        if (j >= 0) tgs[j].ocur += 1;
        else{
            tgs[++size].tg = tgAtual;
            tgs[size].ocur = 1;
        }
    }

    for(j = 0; j <= size; j++){
        if (tgs[j].ocur >= maxOcur) {
            tgAtual = tgs[j].tg;
            maxOcur = tgs[j].ocur;
        }
    } 

    cout << tgAtual << endl;

    return 0;
}