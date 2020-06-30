#include<bits/stdc++.h>
using namespace std;

bool contained (int *v, int tam, int val){
  int i;
  for(i = 0; i < tam; i++){
    if (v[i] == val) return true;
  }

  return false;
}

int main(){
  bool div3;
  int n, i, quantIndex = 0;
  long long int a[100];
  stack<long long int> s;
  int index[100];
  
  cin >> n;
  for (i = 0; i < n; i++){
    cin >> a[i];
    if (a[i] % 3 == 0) div3 = true;
  }

  if (div3){
    for(i = 0; i < n && s.size() != n; i++){
      if (!contained(index, quantIndex, i) && (s.empty() || (s.top() % 3 == 0 && s.top() / 3 == a[i]) || s.top() * 2 == a[i]) ){
        s.push(a[i]);
        index[quantIndex++] = i;
        i = -1;
      }

      if (i == n - 1 && s.size() != n){
        if (!s.empty()) s.pop();
        
        i = index[quantIndex-1];
        quantIndex--;
        
        while (i >= n - 1 && quantIndex >= 1){
          i = index[quantIndex-1];
          quantIndex--;
          if (!s.empty()) s.pop();
        }
      }

    }

    for (i = n-1; !s.empty(); i--){
      a[i] = s.top();
      s.pop();
    }
  }else{
    sort(a, a+n);
  }

  for (i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
