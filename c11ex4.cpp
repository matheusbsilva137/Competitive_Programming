#include<bits/stdc++.h>
using namespace std;
#define NORTE 0
#define SUL 1
#define LESTE 2
#define OESTE 3

bool found = false;
int mrkVir[1000][1000];
int n, m;
char c[1000][1000];
int dir[4][2] = { -1, 0,
                   1, 0,
                   0, 1,
                   0, -1};

bool dentroDaCidade(int i, int j){
    return (i < n && i >= 0 && j < m && j >= 0);
}

void dfs(int i, int j, int quantVir, int sentido){
    if (!found && quantVir <= 2  && dentroDaCidade(i, j) && c[i][j] != '*'){
        mrkVir[i][j] = quantVir + 1;
        if (c[i][j] == 'T') found = true;
        else{
            if (sentido == NORTE) {
                if (dentroDaCidade(i-1, j) && (mrkVir[i-1][j] == 0 || mrkVir[i-1][j] >= quantVir + 1)) dfs(i + dir[NORTE][0], j + dir[NORTE][1], quantVir, NORTE);
                if (dentroDaCidade(i+1, j) && (mrkVir[i+1][j] == 0 || mrkVir[i+1][j] >= quantVir + 2)) dfs(i + dir[SUL][0], j + dir[SUL][1], quantVir + 1, SUL);
                if (dentroDaCidade(i, j+1) && (mrkVir[i][j+1] == 0 || mrkVir[i][j+1] >= quantVir + 2)) dfs(i + dir[LESTE][0], j + dir[LESTE][1], quantVir + 1, LESTE);
                if (dentroDaCidade(i, j-1) && (mrkVir[i][j-1] == 0 || mrkVir[i][j-1] >= quantVir + 2)) dfs(i + dir[OESTE][0], j + dir[OESTE][1], quantVir + 1, OESTE);
            }else if (sentido == SUL){
                if (dentroDaCidade(i+1, j) && (mrkVir[i+1][j] == 0 || mrkVir[i+1][j] >= quantVir + 1)) dfs(i + dir[SUL][0], j + dir[SUL][1], quantVir, SUL);
                if (dentroDaCidade(i-1, j) && (mrkVir[i-1][j] == 0 || mrkVir[i-1][j] >= quantVir + 2)) dfs(i + dir[NORTE][0], j + dir[NORTE][1], quantVir + 1, NORTE);
                if (dentroDaCidade(i, j+1) && (mrkVir[i][j+1] == 0 || mrkVir[i][j+1] >= quantVir + 2)) dfs(i + dir[LESTE][0], j + dir[LESTE][1], quantVir + 1, LESTE);
                if (dentroDaCidade(i, j-1) && (mrkVir[i][j-1] == 0 || mrkVir[i][j-1] >= quantVir + 2)) dfs(i + dir[OESTE][0], j + dir[OESTE][1], quantVir + 1, OESTE);
            }else if (sentido == LESTE){
                if (dentroDaCidade(i, j+1) && (mrkVir[i][j+1] == 0 || mrkVir[i][j+1] >= quantVir + 1)) dfs(i + dir[LESTE][0], j + dir[LESTE][1], quantVir, LESTE);
                if (dentroDaCidade(i-1, j) && (mrkVir[i-1][j] == 0 || mrkVir[i-1][j] >= quantVir + 2)) dfs(i + dir[NORTE][0], j + dir[NORTE][1], quantVir + 1, NORTE);
                if (dentroDaCidade(i+1, j) && (mrkVir[i+1][j] == 0 || mrkVir[i+1][j] >= quantVir + 2)) dfs(i + dir[SUL][0], j + dir[SUL][1], quantVir + 1, SUL);
                if (dentroDaCidade(i, j-1) && (mrkVir[i][j-1] == 0 || mrkVir[i][j-1] >= quantVir + 2)) dfs(i + dir[OESTE][0], j + dir[OESTE][1], quantVir + 1, OESTE);
            }else{
                if (dentroDaCidade(i, j-1) && (mrkVir[i][j-1] == 0 || mrkVir[i][j-1] >= quantVir + 1)) dfs(i + dir[OESTE][0], j + dir[OESTE][1], quantVir, OESTE);
                if (dentroDaCidade(i-1, j) && (mrkVir[i-1][j] == 0 || mrkVir[i-1][j] >= quantVir + 2)) dfs(i + dir[NORTE][0], j + dir[NORTE][1], quantVir + 1, NORTE);
                if (dentroDaCidade(i+1, j) && (mrkVir[i+1][j] == 0 || mrkVir[i+1][j] >= quantVir + 2)) dfs(i + dir[SUL][0], j + dir[SUL][1], quantVir + 1, SUL);
                if (dentroDaCidade(i, j+1) && (mrkVir[i][j+1] == 0 || mrkVir[i][j+1] >= quantVir + 2)) dfs(i + dir[LESTE][0], j + dir[LESTE][1], quantVir + 1, LESTE);
            }
        }
    }
}

int main(){
    int i, j;
    int Si, Sj;
    int Ti, Tj;
    
    cin >> n >> m;
    for (i = 0; i < n; i ++){
        for(j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'S'){
                Si = i;
                Sj = j;
            }else if (c[i][j] == 'T'){
                Ti = i;
                Tj = j;
            }
        }
    }

    if ( (Ti + 1 < n && c[Ti+1][Tj] != '*') || (Ti - 1 >= 0 && c[Ti-1][Tj] != '*') || (Tj + 1 < m && c[Ti][Tj+1] != '*') || (Tj - 1 >= 0 && c[Ti][Tj-1] != '*')){
        dfs(Si + dir[NORTE][0], Sj + dir[NORTE][1], 0, NORTE);
        dfs(Si + dir[SUL][0], Sj + dir[SUL][1], 0, SUL);
        dfs(Si + dir[LESTE][0], Sj + dir[LESTE][1], 0, LESTE);
        dfs(Si + dir[OESTE][0], Sj + dir[OESTE][1], 0, OESTE);
        
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}