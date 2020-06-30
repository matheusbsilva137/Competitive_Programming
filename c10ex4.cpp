#include<bits/stdc++.h>
using namespace std;
char a[30][30][30];
int mrk[30][30][30];
int bestTime = -1;
int l, r, c;

void dfs(int k, int i, int j, int time){
    if(a[k][i][j] == 'E'){
        if (time < bestTime || bestTime == -1) bestTime = time;
    }else{
        mrk[k][i][j] = time;
        if (k > 0 && a[k-1][i][j] != '#' && (mrk[k-1][i][j] > time + 1 || mrk[k-1][i][j] == -1)) dfs(k-1, i, j, time+1);
        if (k < l - 1 && a[k+1][i][j] != '#' && (mrk[k+1][i][j] > time + 1 || mrk[k+1][i][j] == -1)) dfs(k+1, i, j, time+1);
        if (i > 0 && a[k][i-1][j] != '#' && (mrk[k][i-1][j] > time + 1 || mrk[k][i-1][j] == -1)) dfs(k, i-1, j, time+1);
        if (i < r - 1 && a[k][i+1][j] != '#' && (mrk[k][i+1][j] > time + 1 || mrk[k][i+1][j] == -1)) dfs(k, i+1, j, time+1);
        if (j > 0 && a[k][i][j-1] != '#' && (mrk[k][i][j-1] > time + 1 || mrk[k][i][j-1] == -1)) dfs(k, i, j-1, time+1);
        if (j < c - 1 && a[k][i][j+1] != '#' && (mrk[k][i][j+1] > time + 1 || mrk[k][i][j+1] == -1)) dfs(k, i, j+1, time+1);
    }
}

int main(){
    int i, j, k;
    int kIni, iIni, jIni;
    char ch;

    cin >> l >> r >> c;
    while (l != 0 && r != 0 && c != 0){
        bestTime = -1;
        for (k = 0; k < l; k++){
            for(i = 0; i < r; i++){
                for(j = 0; j < c; j++){
                    cin >> ch;
                    mrk[k][i][j] = -1;
                    a[k][i][j] = ch;
                    if (ch == 'S'){
                        kIni = k;
                        jIni = j;
                        iIni = i;
                    }
                }
            }
        }

        dfs(kIni, iIni, jIni, 0);
        if (bestTime != -1) cout << "Escaped in " << bestTime << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
        cin >> l >> r >> c;
    }
    return 0;
}