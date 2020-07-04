#include<bits/stdc++.h>
using namespace std;


int main(){
  int t, i, erase, strSize, zeros = 0;
  string s;

  cin >> t;
  
  erase = 0;
  
  while ( t > 0 ){
    cin >> s;
    strSize = s.size();

    i = 0;
    while (i < strSize && s.at(i) == '0') i++;

    while ( i < strSize ){
      while( i < strSize && s.at(i) == '1') i++, erase += zeros, zeros = 0;
      while (i < strSize && s.at(i) == '0') i++, zeros++;
    }
    printf("%d\n", erase);
    zeros = 0;
    erase = 0;
    t--;
  }

  return 0;
}
