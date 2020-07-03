#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int m, n, sy, ey, a;
    int q, sx, ex;
    vector<int> v;

    cin >> m >> n >> q;
    a = __gcd(m, n);

    for (int i = 0; i < q; i++){
        cin >> sx >> sy >> ex >> ey;
        int b, c;
        if (sx == 1) b = ((sy % (m/a) == 0) ? sy/(m/a) - 1 : sy/(m/a));
        else b = ((sy % (n/a) == 0) ? sy/(n/a) - 1 : sy/(n/a));

        if (ex == 1) c = ((ey % (m/a) == 0) ? ey/(m/a) - 1 : ey/(m/a));
        else c = ((ey % (n/a) == 0) ? ey/(n/a) - 1 : ey/(n/a));

        if (b == c) cout << "YES" << endl;
        else cout << "NO" << endl;   
    }

    return 0;
}