#include<bits/stdc++.h>
using namespace std;
#define MAX 500

int main(){
    int r, c, i, j, contProt = 0;
    char m[MAX][MAX];
    string s;
    
    cin >> r >> c;
    for (i = 0; i < r; i++){
        cin >> s;
        for (j = 0; j < c; j++) m[i][j] = s.at(j);
    }

    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            if (m[i][j] == 'S'){
                if ((i >= 1 && m[i-1][j] == 'W') || (j + 1 < c && m[i][j+1] == 'W') || (j >= 1 && m[i][j-1] == 'W') || (i + 1 < r && m[i+1][j] == 'W') ){
                    cout << "No" << endl;
                    return 0;
                }
                if (i - 1 >= 0 && m[i-1][j] == '.') m[i-1][j] = 'D';
                if (i + 1 < r && m[i+1][j] == '.') m[i+1][j] = 'D';
                if (j - 1 >= 0 && m[i][j-1] == '.') m[i][j-1] = 'D';
                if (j + 1 < c && m[i][j+1] == '.') m[i][j+1] = 'D';
            }
        }
    }

    cout << "Yes" << endl;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            cout << m[i][j];
        }
        cout << endl;
    }

}