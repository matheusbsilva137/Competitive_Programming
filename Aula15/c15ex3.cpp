#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10000000
long long int crivo[MAXSIZE];

int main(){
    long long int n, i, j, x, maxX = 1;
    vector<long long int> nums;

    nums.push_back(1);
    for (i = 0; i < MAXSIZE; i++) crivo[i] = i;

    for (i = 2; i <= sqrt(MAXSIZE); i++)
        for (j = i*i; j <= MAXSIZE; j += i) crivo[j] = 0;

    for (cin >> n; n > 0; n--){
        scanf("%lld", &x);
        double raiz = sqrt(x);

        if (raiz > 1 && crivo[(int)raiz] == raiz) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}