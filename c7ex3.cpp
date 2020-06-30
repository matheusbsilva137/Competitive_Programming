#include<bits/stdc++.h>
using namespace std;

struct terna{
    int h, e, a, ind;
};

int main(){
    int n, i;
    terna max, min, atual;
    
    min.a = max.e = min.h = 0;
    max.a = min.e = max.h = 10001;
    cin >> n;

    for (i = 0; i < n; i++){
        cin >> atual.h >> atual.e >> atual.a;
        if ( i == 0 || atual.h > min.h ||
             (atual.h == min.h && atual.e < min.e) ||
             (atual.h == min.h && atual.e == min.e && atual.a >= min.a) ){
            min.a = atual.a;
            min.h = atual.h;
            min.e = atual.e;
            min.ind = i+1;
        }
        
        if( i == 0 || atual.h < max.h ||
            (atual.h == max.h && atual.e > max.e) ||
            (atual.h == max.h && atual.e == max.e && atual.a <= max.a)){
            max.a = atual.a;
            max.h = atual.h;
            max.e = atual.e;
            max.ind = i+1;
        }
    }

    if (min.ind != max.ind){
        cout << "Easiest is level " << min.ind << endl;
        cout << "Hardest is level " << max.ind << endl;
    }else{
        cout << "Easiest and Hardest is level " << min.ind << endl;
    }
}