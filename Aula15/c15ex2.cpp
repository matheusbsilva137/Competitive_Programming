#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, l, a, aAnt = 0;
    double d = 0;
    vector<int> lanterns;
    cin >> n >> l;

    for (i = 0; i < n; i++){
        cin >> a;
        lanterns.push_back(a);
    }
    sort(lanterns.begin(), lanterns.end());

    aAnt = 0;
    if ( (lanterns.at(0) == 0 || lanterns.at(0) == l) && n == 1) d = l;
    else d = lanterns.at(0);

    for(i = 0; i < n; i++){
        a = lanterns.at(i);
        if ((double)(a - aAnt)/2 > d) d = (double)(a - aAnt)/2;
        aAnt = a;
    }
    if (d < max(lanterns.at(0), l - lanterns.back()) ) d = max(lanterns.at(0), l - lanterns.back());
    printf("%.9lf\n", d);

    return 0;
}