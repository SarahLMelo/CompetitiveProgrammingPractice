#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    string s;
    cin >> s;

    int ans = 1;
    for(int i = 0; i < s.size(); i++){
        if(i == 0 && s[i] == '0'){
            ans = 0;
            break;
        }
        if(s[i] == '?'){
            ans *= 10 - (i == 0);
        }
    }

    cout << ans << "\n";
}

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}