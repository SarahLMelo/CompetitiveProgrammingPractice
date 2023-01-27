#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod1 = 1432757981, b1 = 151, mod2 = 1584729899, b2 = 761;
vector <pair <int, int>> pot, invPot;
vector <pair <int, int>> h;

int fExp(int a, int b, int mod){
    int ans = 1;

    while(b){
        if(b & 1) ans = 1LL * ans * a % mod;

        a = 1LL * a*a % mod;
        b >>= 1;
    }

    return ans;
}

pair <int, int> hashF(string &s, bool flag = 0){
    pair <int, int> cur = {0, 0};
    for(int i = 0; i < s.size(); i++){
        cur.first = (cur.first + pot[i].first * (s[i])) % mod1;
        cur.second = (cur.second + pot[i].second * (s[i])) % mod2;
        if(flag){
            h[i+1].first = cur.first;
            h[i+1].second = cur.second;
        }
    }

    return cur;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    pot.resize(s.size());
    invPot.resize(s.size());
    h.resize(s.size() + 1);
    h[0] = {0, 0};

    pot[0] = {1, 1};
    invPot[0] = {1, 1};

    for(int i = 1; i < s.size(); i++){
        pot[i].first = pot[i-1].first * b1 % mod1;
        invPot[i].first = fExp(pot[i].first, mod1 - 2, mod1);

        pot[i].second = pot[i-1].second * b2 % mod2;
        invPot[i].second = fExp(pot[i].second, mod2 - 2, mod2);
    }

    hashF(s, 1);

    int t;
    cin >> t;

    while(t--){
        string q;
        cin >> q;

        pair <int, int> x = hashF(q);
        bool ans = false;

        for(int i = 0; i + q.size() < s.size() && !ans; i++){
            pair <int, int> aux;
            aux.first = (h[i + q.size()].first - h[i].first + mod1) % mod1;
            aux.first = aux.first * invPot[i].first % mod1;

            aux.second = (h[i + q.size()].second - h[i].second + mod2) % mod2;
            aux.second = aux.second * invPot[i].second % mod2;

            ans = (aux == x);
        }

        cout << (ans ? "Y\n":"N\n");
    }

    return 0;
}