#include<bits/stdc++.h>
using namespace std;
#define ESQ 0
#define DIR 1

void imprimirCaminho(pair<int, int> a, pair<int, int> cur, pair<int, int> pai, pair<int, int> sum, bool dir){    
    if (a.first == cur.first && a.second == cur.second) return;
    else if (((double)a.first/(double)a.second) >  ((double)cur.first/(double)cur.second)){
        cout << "R";
        if (dir == DIR){
            pai = cur;
            cur.first += sum.first;
            cur.second += sum.second;
            imprimirCaminho(a, cur, pai, sum, dir);
        }else{
            sum = pai;
            pair<int, int> aux = cur;
            cur.first += pai.first;
            cur.second += pai.second;
            pai = aux;
            imprimirCaminho(a, cur, pai, sum, DIR);
        }
    }else{
        cout << "L";
        if (dir == ESQ) {
            pai = cur;
            cur.first += sum.first;
            cur.second += sum.second;
            imprimirCaminho(a, cur, pai, sum, dir);
        }else{
            sum = pai;
            pair<int, int> aux = cur;
            cur.first += pai.first;
            cur.second += pai.second;
            pai = aux;
            imprimirCaminho(a, cur, pai, sum, ESQ);
        }
    }
}

int main(){
    int m, n;

    cin >> m >> n;
    while (m != 1 || n != 1){
        if ((double)m/(double)n > 1) imprimirCaminho(make_pair(m, n), make_pair(1,1), make_pair(1,1), make_pair(1,0), DIR);
        else imprimirCaminho(make_pair(m, n), make_pair(1,1), make_pair(1,1), make_pair(0,1), ESQ);
        cout << endl;
        cin >> m >> n;
    }
    return 0;
}