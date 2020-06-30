#include<bits/stdc++.h>
using namespace std;
bool letras[26];

int main(){
    list<char> kbd;
    list<char>::iterator i;
    int t, j;
    bool foundKbd;
    string s;

    for (cin >> t; t > 0; t--){
        foundKbd = true;
        cin >> s;
        for (j = 0; j < s.size() && foundKbd; j++){
            if (kbd.size() == 0) {
                kbd.push_back(s.at(j));
                letras[s.at(j) - 'a'] = true;
            }else if (letras[s.at(j) - 'a'] == false){
                for (i = kbd.begin(); i != kbd.end() && *i != s.at(j-1); i++);
                if (i == kbd.begin()){
                    kbd.push_front(s.at(j));
                    letras[s.at(j) - 'a'] = true;
                }else if (i == --kbd.end()){
                    kbd.push_back(s.at(j));
                    letras[s.at(j) - 'a'] = true;
                }else foundKbd = false;
            }else{
                //se a letra anterior já está do lado de outra, não dá
                for (i = kbd.begin(); i != kbd.end() && *i != s.at(j-1); i++);
                if (*(++i) == s.at(j)) --i;
                else if (*(--(--i)) != s.at(j)) foundKbd = false;
            }
        }
        if(foundKbd) {
            cout << "YES" << endl;
            for (j = 0; j < 26; j++) if (letras[j] == false) kbd.push_back('a'+ j);
            for (i = kbd.begin(); i != kbd.end(); i++) cout << *i;
            cout << endl;
        }else cout << "NO" << endl;

        kbd.clear();
        for (j = 0; j < 26; j++) letras[j] = false;
    }
}