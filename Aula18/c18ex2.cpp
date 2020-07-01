#include<bits/stdc++.h>
using namespace std;
bool t[8][8];

void movimentoCavalo(int i, int j){
    t[i][j] = true;
    if (i - 2 >= 0){
        if (j - 1 >= 0) t[i-2][j-1] = true;
        if (j + 1 < 8) t[i-2][j+1] = true;
    }
    if (i + 2 < 8){
        if (j - 1 >= 0) t[i+2][j-1] = true;
        if (j + 1 < 8) t[i+2][j+1] = true;
    }
    if (j - 2 >= 0){
        if (i - 1 >= 0) t[i-1][j-2] = true;
        if (i + 1 < 8) t[i+1][j-2] = true;
    }
    if (j + 2 < 8){
        if (i - 1 >= 0) t[i-1][j+2] = true;
        if (i + 1 < 8) t[i+1][j+2] = true;
    }
}

int main(){
    int ans = 0, p;
    char c;

    cin >> c >> p;
    for(int i = 0; i < 8; i++) t[c - 'a'][i] = true;
    for (int i = 0; i < 8; i++) t[i][p-1] = true;
    movimentoCavalo(c - 'a', p-1);

    cin >> c >> p;
    movimentoCavalo(c - 'a', p-1);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (t[i][j] == false) ans++;

    cout << ans << endl;
    return 0;
}