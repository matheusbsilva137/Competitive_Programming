#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int quantA = 0, sizeS, i;

  cin >> s;
  sizeS = s.size();

  for(i = 0; i < sizeS; i++){
    if(s[i] == 'a') quantA++;
  }

  if (quantA > (sizeS / 2) ) cout << sizeS << endl;
  else cout << 2*quantA - 1 << endl;
  return 0;
}
