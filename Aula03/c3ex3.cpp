#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k, i;
  int *v;
  cin >> n >> k;

  v = new int[n];
  for(i = 0; i < n; i++){
    cin >> v[i];
  }

  sort(v, v+n);
  if(k > n || ( k == 0 && v[0] == 1 )  ){
    cout << "-1" << endl;
  }else if (k == 0){
    cout << v[0] - 1 << endl;
  }else if (k == n){
    cout << v[k-1] << endl;
  }else{
    if (v[k-1] == v[k]) cout << "-1" << endl;
    else cout << v[k-1] << endl;
  }

  return 0;
}