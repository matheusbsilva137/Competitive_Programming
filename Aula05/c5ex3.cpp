#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, i, j, n, soma = 0;
    int* a;
    map<int, pair<int, int>> s;
    map<int,pair<int,int>>::iterator it;

    cin >> k;
    for (i = 0; i < k; i++, soma = 0){
        cin >> n;
        a = new int[n];

        for (j = 0; j < n; j++){
            cin >> a[j];
            soma += a[j];
        }

        for(j = 0; j < n; j++){
            it = s.find(soma-a[j]);
            if (it != s.end() && it->second.first != i){
                cout << "YES" << endl;
                cout << i+1 << " " << j+1 << endl;
                cout << it->second.first + 1 << " " << it->second.second + 1 << endl;
                return 0;
            }else s.insert({soma-a[j], pair<int, int>(i, j)});
        }

        delete a;
    }

    cout << "NO" << endl;
    return 0;
}