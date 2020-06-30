#include<bits/stdc++.h>
using namespace std;

int main(){
    long int l = 1, r = 1000000000, g = (l  + r)/2;
    char c;

    cout << "Q " << g << endl;
    cout.flush();
    cin >> c;

    while (c != '='){
        if (c == '<') r = g - 1;
        else l = g + 1;
        g = (l+r)/2;
        cout << "Q " << g << endl;
        cout.flush();
        cin >> c;
    }

    return 0;
}