#include<bits/stdc++.h>
using namespace std;

int main(){
  unsigned long int x1, x2, x3, x4, a, b, c;
  cin >> x1;
  cin >> x2;
  cin >> x3;
  cin >> x4;

  if(x1 > x2 && x1 > x3 && x1 > x4){
    a = x1 - x2;
    b = x1 - x3;
    c = x1 - x4;
    printf("%d %d %d\n", a, b, c);
  }else if(x2 >x1 && x2 > x3 && x2 > x4){
    a = x2 - x1;
    b = x2 - x3;
    c = x2 - x4;
    printf("%d %d %d\n", a, b, c);    
  }else if(x3 > x1 && x3 > x2 && x3 > x4){
    a = x3 - x2;
    b = x3 - x1;
    c = x3 - x4;
    printf("%d %d %d\n", a, b, c);
  }else{
    a = x4 - x2;
    b = x4 - x3;
    c = x4 - x1;
    printf("%d %d %d\n", a, b, c);
  }
  
  return 0;
}
