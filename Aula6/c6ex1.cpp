#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, i, l, r, res = 0;

	cin >> n >> k;
	int* a = new int[n];
	l = 0;
	r =  n -1;

	for (i = 0; i < n; i++) cin >> a[i];

	while (l <= r){
		if (a[l] <= k){
			l++;
			res++;
		}else if (a[r] <= k){
			r--;
			res++;
		}else l = r + 1;
	}

	cout << res << endl;
}
