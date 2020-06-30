#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t, sussu = "Sussu";
    std::size_t f;
    int i, j;
    bool found = false;

    cin >> s;
    while(s.back() != '.' && s.back() != '?' && s.back() != '!'){
        s = s + ' ';
        cin >> t;
        s += t;
    }

    if (s.back() == '?'){
        cout << 7 << endl;
    }else{
        s.pop_back();
        for (i = 0; s.size() >= 5 && i <= s.size() - 5 && !found; i++){
            for (j = 0; j < 5 && s.at(i+j) == sussu.at(j); j++);
            if (j == 5 && (i+5 >= s.size() || s.at(i+5) == ' ' || s.at(i+5) == ',')) {
                if (i - 1 >= 0 && s.at(i - 1) == ' ') found = true;
                else if (i - 1 < 0) found = true;
            }
            else if (j == 5) i++;
        }
        if (found) cout << "AI SUSSU!" << endl;
        else cout << "O cara é bom!" << endl;
    }
    return 0;
}