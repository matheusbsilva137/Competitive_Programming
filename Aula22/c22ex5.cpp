#include<bits/stdc++.h>
using namespace std;
char tab[8][8];

bool dentTab(int i, int j){
    return (i >= 0 && i <= 7 && j >= 0 && j<= 7);
}
//identifica se a peça na posição i,j pode ser capturada por um lowercase do tipo dado
bool moveP(int i, int j){
    return ((dentTab(i+1, j+1) && tab[i+1][j+1] == 'p') || (dentTab(i+1, j-1) && tab[i+1][j-1] == 'p'));
}

bool moveK(int i, int j){
    return ((dentTab(i+1, j+1) && tab[i+1][j+1] == 'k') || (dentTab(i+1, j-1) && tab[i+1][j-1] == 'k') || (dentTab(i+1, j) && tab[i+1][j] == 'k')
         || (dentTab(i-1, j+1) && tab[i-1][j+1] == 'k') || (dentTab(i-1, j-1) && tab[i-1][j-1] == 'k') || (dentTab(i-1, j) && tab[i-1][j] == 'k')
         || (dentTab(i, j+1) && tab[i][j+1] == 'k') || (dentTab(i, j-1) && tab[i][j-1] == 'k'));
}

bool moveC(int i, int j){
    return ((dentTab(i-2, j+1) && tab[i-2][j+1] == 'c') || (dentTab(i-2, j-1) && tab[i-2][j-1] == 'c') 
     ||(dentTab(i-1, j+2) && tab[i-1][j+2] == 'c') || (dentTab(i-1, j-2) && tab[i-1][j-2] == 'c') 
     ||(dentTab(i+2, j+1) && tab[i+2][j+1] == 'c') || (dentTab(i+2, j-1) && tab[i+2][j-1] == 'c') 
     ||(dentTab(i+1, j+2) && tab[i+1][j+2] == 'c') || (dentTab(i+1, j-2) && tab[i+1][j-2] == 'c'));
}

bool moveT(int i, int j, char c){
    int b;
    for (b = j+1; b < 8 && tab[i][b] == '.'; b++);
    if (b < 8 && tab[i][b] == c) return true;

    for (b = j-1; b >= 0 && tab[i][b] == '.'; b--);
    if (b >= 0 && tab[i][b] == c) return true;

    for (b = i+1; b < 8 && tab[b][j] == '.'; b++);
    if (b < 8 && tab[b][j] == c) return true;

    for (b = i-1; b >= 0 && tab[b][j] == '.'; b--);
    if (b >= 0 && tab[b][j] == c) return true;

    return false;
}

bool moveB(int i, int j, char c){
    int a, b;
    for (a = i+1, b = j+1; a < 8 && b < 8 && tab[a][b] == '.'; a++, b++);
    if (a < 8 && b < 8 && tab[a][b] == c) return true;

    for (a = i-1, b = j-1; a >= 0 && b >= 0 && tab[a][b] == '.'; a--, b--);
    if (a >= 0 && b >= 0 && tab[a][b] == c) return true;

    for (a = i-1, b = j+1; a >= 0 && b < 8 &&  tab[a][b] == '.'; a--, b++);
    if (a >= 0 && b < 8 && tab[a][b] == c) return true;

    for (a = i+1, b = j-1; a < 8 && b >= 0 && tab[a][b] == '.'; a++, b--);
    if (a < 8 && b >= 0 && tab[a][b] == c) return true;

    return false;
}

bool moveR(int i, int j){
    return (moveB(i, j, 'r') || moveT(i, j, 'r'));
}

int main(){
    bool hasP = false, hasC = false, hasT = false, hasB = false, hasR = false, hasK = false, ans = false;
    char row, col;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> tab[i][j];
            if (tab[i][j] == 'p') hasP = true;
            else if (tab[i][j] == 'c') hasC = true;
            else if (tab[i][j] == 't') hasT = true;
            else if (tab[i][j] == 'b') hasB = true;
            else if (tab[i][j] == 'r') hasR = true;
            else if (tab[i][j] == 'k') hasK = true;
        }
    }

    cin >> col >> row;
    if(hasP) ans = moveP(abs(row-'8'), col-'a');
    if (!ans && hasC) ans = moveC(abs(row-'8'), col-'a');
    if (!ans && hasT) ans = moveT(abs(row-'8'), col-'a', 't');
    if (!ans && hasB) ans = moveB(abs(row-'8'), col-'a', 'b');
    if (!ans && hasR) ans = moveR(abs(row-'8'), col-'a');
    if (!ans && hasK) ans = moveK(abs(row-'8'), col-'a');

    if (ans) cout << "Sim" << endl;
    else cout << "Nao" << endl;
    return 0;
}