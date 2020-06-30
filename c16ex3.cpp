#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    long long int k;
    vector<long long int> a;
    vector<long long int>::iterator it;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() && a.at(i)*k <= a.back(); i++){
        it = lower_bound(a.begin(), a.end(), a.at(i)*k);
        if (it != a.end() && *it == a.at(i)*k && *it != a.at(i)) {
            a.erase(it);
        }
    }
    cout << a.size() << endl;

    return 0;
}