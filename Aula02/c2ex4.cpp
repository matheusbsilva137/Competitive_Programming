#include<bits/stdc++.h>
using namespace std;

bool isPalindrome (string s, int start, int end){
    while(start < end){
        if(s[start] != s[end]) return false;
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

int main(){
    string s;
    unsigned int k, wordSize, i, tam;
    bool bag = true;

    cin >> s;
    cin >> k;
    tam = s.size();

    wordSize = tam / k;

    if(wordSize == 1 && tam % k == 0){
        cout << "YES" << endl;
        return 0;
    }else if( tam % k != 0 ){
        cout << "NO" << endl;
        return 0;
    }

    for(i = 0; i < tam && bag == true; i += wordSize)
        if(!isPalindrome(s, i, i + wordSize - 1)) bag = false;
    if(bag == true) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}