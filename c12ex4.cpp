#include<bits/stdc++.h>
using namespace std;
int crivo[1005];

int pot(int base, int exp){
    int res = base;
    if (exp == 0) return 1;
    while (exp > 1){
        res *= base;
        exp--;
    }
    return res;
}

int main(){
    int n, i, j, rn, quantNums = 0, qPrimos;
    vector<int> nums;
    cin >> n;

    rn = sqrt(n);

    for (i = 2; i <= n; i++) crivo[i] = i;

    for (i = 2; i <= rn; i++){
        if (crivo[i] == i){
            nums.push_back(i);
            quantNums++;
        }
        for (j = i*i; j <= n; j += i) crivo[j] = 0;
    }

    for (i = rn + 1; i <= n; i++){
        if (crivo[i] == i){
            nums.push_back(i);
            quantNums++;
        }
    }
    qPrimos = quantNums;

    for(i = 0; i < qPrimos && pot(nums.at(i), 2) <= n; i++){
        for ( j = 2; pot(nums.at(i), j) <= n; j++ ){
            nums.push_back(pot(nums.at(i), j));
            quantNums++;
        }
    }

    cout << quantNums << endl;
    for (i = 0; i < nums.size(); i++) cout << nums.at(i) << " ";
    cout << endl;

    return 0;
}