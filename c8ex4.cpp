#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

vector<int> blockedDoors;
vector<int>::iterator it;
int keys[MAX], mark[MAX], doors[MAX];
vector<int> adj[MAX];
int n;
bool ans;

void dfs(int no){
    int i;
    mark[no] = 1;
    
    if ( doors[no] == 1 ){
        //Tem uma porta que não consigo abrir (ainda) nesta sala
        blockedDoors.push_back(no);
    }else if (no == n - 1){
        //Cheguei no fim do labirinto
        ans = true;
    }else{
        if (keys[no] != -1){
            //Tem uma chave na sala
            doors[keys[no]] = 0;
            it = find(blockedDoors.begin(), blockedDoors.end(), keys[no]);
            if ( it != blockedDoors.end()){
                i = *it;
                *it = -1;
                dfs(i);
                keys[no] = -1;
            }else{
                keys[no] = -1;
            }
        }

        for (int v : adj[no]){
            if (mark[v] != 1) dfs(v);
        }
    }

}

int main(){
    int m = 0, k = 0, i, a, b, dest;

    cin >> n >> k >> m;
    while(n != -1 && m != -1 && k != -1){
        ans = false;
        memset(keys, -1, n*sizeof(*keys));
        memset(doors, 0, n*sizeof(*doors));
        memset(mark, 0, n*sizeof(*mark));

        for (i = 0; i < k; i++){
            cin >> a >> b;
            keys[a-1] = b - 1;
            doors[b-1] = 1;
        }

        for(i = 0; i < m; i++){
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        dfs(0);
        if (ans) cout << "Y" << endl;
        else cout << "N" << endl;

        blockedDoors.clear();
        for (i = 0; i < n; i++) adj[i].clear();
        cin >> n >> k >> m;
    }
    return 0;
}