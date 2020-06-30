#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

int min(int a, int b){
    if (a < b) return a;
    else return b;
}

int main(){
    int n, pos, l, r, totFech, totSeg = 0, a = 1, b;

    cin >> n;
    cin >> pos;
    cin >> l;
    cin >> r;
    b = n;

    while(a != l || b != r){
        if( b == r || r == n || pos == n || ( l <= pos && r <= pos) || (abs(l - pos) <= abs(r - pos) && l != a && l <= pos) ){
            //Passo à esquerda
            if (pos == r && r != b){
                b = r;
                if (a != l) totSeg += r - l + 1;
                totSeg++;
                a = l; 
            }else if(b == r && a != l){
                a = l;
                totSeg += abs(a - pos) + 1;
            }else if( pos != l ){
                pos = max(pos - 1, a);
                totSeg++;
                if (pos == l){
                    if(a != l){
                        a = l;
                        totSeg++;
                        if(b != r) {
                            b = r;
                            totSeg += b - a + 1;
                        }
                    }
                    else b = r, totSeg++;
                }
            }else if(pos == l && l != a){
                a = l;
                totSeg++;
            }
        }else if ( a == l || l == 1 || pos == 1 || ( r >= pos && l >= pos) || (abs(l - pos) > abs(r - pos) && b != r && r >= pos) ){
            //Passo à direita
            if(pos == l && l != a){
                a = l;
                if (b != r) totSeg += r - l + 1;
                totSeg++;
                b = r;
            }else if(a == l && b != r){
                b = r;
                totSeg += abs(b - pos) + 1;
            } else if(pos != r){
                pos = min(pos + 1, b);
                totSeg++;
                if (pos == r){
                    if (b != r){
                        b = r;
                        totSeg++;
                        if(a != l){
                            a = l;
                            totSeg += b - a + 1;
                        }
                    }else a = l, totSeg++;
                }
            }else if(pos == r && r != b){
                b = r;
                totSeg++;
            }
        }
    }

    printf("%d\n", totSeg);
    return 0;
}
