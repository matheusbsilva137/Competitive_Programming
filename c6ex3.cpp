#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k, i, j;
	string s;
	char c;

	int *ocurChar = new int[26];
	for (i = 0; i < 26; i++) ocurChar[i] = 0;

	cin >> n >> k;
	for (i = 0; i < n; i++){
		scanf(" %c", &c);
		s += c;
		ocurChar[s[i] - 'a'] = ocurChar[s[i] - 'a'] + 1;
	}

	for (i = 0; i < 26 && k > 0 && n > 0; i++){
		if (ocurChar[i] > 0){
			for(j = 0; j < n && k > 0; j++){
				if ('a' + i == s[j]){
					s.erase(s.begin()+j);
					n--;
					k--;

					ocurChar[i] = ocurChar[i] - 1;
					if (ocurChar[i] <= 0 ) j = s.size() + 1;
					else j--;
				}
			}
		}
	}

	cout << s << endl;
}