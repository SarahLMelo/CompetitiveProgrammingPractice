#include <bits/stdc++.h>

using namespace std;
// #define int long long

uint64_t p = 31, mod = (1LL << 61) - 1;

uint64_t hashing(string &s){
    uint64_t h = 0;
    for(int i = 1; i <= s.size() + 1; i++){
        h = ((h * p) % mod + (s[i - 1] - 'a' + 1)) % mod;
    }

    return h;
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += s;

    map <uint64_t, int> leg;

    int g;
    cin >> g;

    for(int i = 1; i <= g; i++){
        string x;
        cin >> x;

        leg[hashing(x)] = i;
    }

    vector <int> ans(n);
    for(int i = 0; i <k; i++){
        bool valid = true;
        set <int> used;
        for(int j = 0; j < n && valid; j++){
            string aux = s.substr(i + j*k, k);
            uint64_t aux2 = hashing(aux);

            if(leg.find(aux2) == leg.end()){
                valid = false;
            }
            else{
                ans[j] = leg[aux2];
                if(used.find(ans[j]) != used.end()) valid = false;
                used.emplace(ans[j]);
            }
        }

        if(valid){
            cout << "YES\n";
            for(int j = 0; j < n; j++){
                if(j) cout << " ";
                cout << ans[j];
            }

            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}

