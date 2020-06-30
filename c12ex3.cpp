#include<bits/stdc++.h>
using namespace std;

int qPretoLin[50];
int qPretoCol[50];

int main(){
    long long int qSets;
    int i, j, n, m;
    bool b;
    cin >> n >> m;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++) {
            cin >> b;
            qPretoLin[i] += b;
            qPretoCol[j] += b;
        }
    }

    qSets += n * m;
    for(i = 0; i < n; i++){
        if (qPretoLin[i] > 1) qSets += pow(2, qPretoLin[i]) - qPretoLin[i] - 1;
        if (m - qPretoLin[i] > 1) qSets += pow(2, m - qPretoLin[i]) - (m - qPretoLin[i]) - 1;
    }

    for(i = 0; i < m; i++){
        if (qPretoCol[i] > 1) qSets += pow(2, qPretoCol[i]) - qPretoCol[i] - 1;
        if (n - qPretoCol[i] > 1) qSets += pow(2, n - qPretoCol[i]) - (n - qPretoCol[i]) - 1;
    }

    cout << qSets << endl;

    return 0;
}