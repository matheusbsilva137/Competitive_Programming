#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, i, c, d;
	char aux;
	string t;

	cin >> n >> t;
	for (i = 1; i < n; i++){
		if ( n % (i+1) == 0 ){
			for (c = 0, d = i; c < d; c++, d--){
				aux = t.at(c);
				t.at(c) = t.at(d);
				t.at(d) = aux;
			}
		}
	}

	cout << t << endl;
}