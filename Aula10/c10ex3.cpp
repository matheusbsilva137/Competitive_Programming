#include<bits/stdc++.h>
using namespace std;
vector<int> g[16];
bool nums[48];

int main(){
    int n, m, a, b, i, j, k, prox = 1;
    bool inseriu;
    for (i = 0; i < 48; i++) nums[i] = false;

    cin >> n >> m;

    for (i = 0; i < m; i++){
        cin >> a >> b;
        inseriu = false;

        for (j = 0; j < 16 && g[j].size() > 0 && !inseriu; j++){
            if (find(g[j].begin(), g[j].end(), a) != g[j].end()) {
                if (find(g[j].begin(), g[j].end(), b) == g[j].end()){
                    g[j].push_back(b);
                    nums[b-1] = true;
                    inseriu = true;
                }else inseriu = true;
            }else if (find(g[j].begin(), g[j].end(), b) != g[j].end()) {
                if (find(g[j].begin(), g[j].end(), a) == g[j].end()){
                    g[j].push_back(a);
                    nums[a-1] = true;
                    inseriu = true;
                }else inseriu = true;
            }

            if (inseriu && g[j].size() > 3){
                cout << -1 << endl;
                return 0;
            }
        }

        if (!inseriu){
            for (j = 0; j < 16 && g[j].size() > 0; j++);
            nums[a-1] = true;
            nums[b-1] = true;
            g[j].push_back(a);
            g[j].push_back(b);
        }
    }

    for (j = 0; j < 16; j++){
        while(prox <= n && nums[prox-1]) prox++;
        while (prox <= n && g[j].size() < 3){
            g[j].push_back(prox);
            nums[prox-1] = true;
            while(prox <= n && nums[prox-1]) prox++;
        }
        if (g[j].size() > 0 && g[j].size() < 3){
            cout << -1 << endl;
            return 0;
        }
    }

    for (j = 0; g[j].size() > 0; j++){
        for (k = 0; k < g[j].size(); k++) cout << g[j].at(k) << " ";
        cout << endl;
    }
    return 0;
}