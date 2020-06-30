#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a, tot = 0, minCar;
  
  scanf("%d", &n);
  while(n > 0){
    scanf("%d", &a);
    tot += a;
    n--;
  }

  minCar = tot/5;
  if (tot % 5 > 0) minCar++;
  printf("%d\n", minCar);

  return 0;
}
