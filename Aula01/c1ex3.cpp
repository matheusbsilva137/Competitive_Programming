#include<bits/stdc++.h>
using namespace std;


int main(){
    unsigned long long int n;

    cin >> n;
    if(n == 0 || (n+1) % 2 == 0) printf("%llu\n", (n+1)/2);
    else printf("%llu\n", n+1);
    return 0;
}
