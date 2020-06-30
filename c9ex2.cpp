#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, n, qA = 0, qB = 0, qC = 0, qD = 0, q;
    cin >> n;

    for (i = 0; i < n; i++){
        cin >> q;
        if (i % 4 == 0) qA += q;
        else if (i % 4 == 1) qB += q;
        else if (i % 4 == 2) qC += q;
        else qD += q;
    }

    if (qA >= qB && qA >= qC && qA >= qD) cout << "A" << endl;
    else if (qB > qA && qB >= qC && qB >= qD) cout << "B" << endl;
    else if (qC > qA && qC > qB && qC >= qD) cout << "C" << endl;
    else if (qD > qA && qD > qC && qD > qB) cout << "D" << endl;
    return 0;
}