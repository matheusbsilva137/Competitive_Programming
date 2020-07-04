#include<bits/stdc++.h>
using namespace std;
vector<int> mrk;
vector<pair<int,int>> adj;
int n, m;

int dfs(int i, int j, int iteracao){
    if (mrk.at(m*i + j) == 0){
        mrk.at(m*i + j) = iteracao;
        return dfs(adj.at(m*i + j).first, adj.at(m * i + j).second, iteracao);
    }else return (m*i + j);
}

int main(){
    int i, j, min = 0, it = 1, no;
    string s;

    cin >> n >> m;
    if (n == 1 && m == 1){
        cout << "1" << endl;
        return 0;
    }

    for (i = 0; i < n; i++){
        cin >> s;
        for (j = 0; j < m; j++){
            mrk.push_back(0);
            if (s[j] == 'S') adj.push_back(make_pair(i+1, j));
            else if (s[j] == 'N') adj.push_back(make_pair(i-1, j));
            else if (s[j] == 'E') adj.push_back(make_pair(i, j+1));
            else adj.push_back(make_pair(i, j-1));
        }
    }

    for (i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(mrk.at(i*m + j) == 0){
                min++;
                no = dfs(i, j, it);
                if (mrk.at(no) != it) min--;
                it++;
            }
        }
    }
    
    cout << min << endl;
    return 0;
}