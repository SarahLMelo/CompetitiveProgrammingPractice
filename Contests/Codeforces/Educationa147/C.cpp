#include <bits/stdc++.h>

using namespace std;
#define int long long

int qnt(string s, char c){
    string aux;
    bool changed = true;
    int cnt  = 0;

    while(changed){
        changed = false;
        // cout << s << endl;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                aux.push_back(c);
                continue;
            }

            changed = true;
            if(i+1 < s.size()) aux.push_back(s[i+1]);
            ++i;
        }

        s = aux;
        aux.clear();
        if(changed) cnt++;
    }

    return cnt;
}

void solve(){
    string s;
    cin >> s;

    int mn = s.size();
    for(int i = 0; i < 26; i++) mn = min(mn, qnt(s, 'a' + i));

    cout << mn << "\n";
}

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}