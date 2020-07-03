#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    for (cin >> t; t > 0; t--){
        double ans = 0, p, a, b, c, d;
        cin >> a >> b >> c >> d;
        
        //Fórmula de Brahmagupta, onde p é o semiperímetro do quadrilátero
        p = (a+b+c+d)/2;
        ans = sqrt((p-a)*(p-b)*(p-c)*(p-d));
        printf("%.2lf\n", ans);
    }
    
    return 0;
}