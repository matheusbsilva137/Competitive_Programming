#include<bits/stdc++.h>
using namespace std;

int main(){
  long int n;
  int k;

  cin >> n;
  cin >> k;

  while( k > 0 ){
    if (n % 10 != 0){
      k--;
      n--;
    }else{
      k--;
      n = n/10;
    }        
  }

  cout << n << endl;
}
