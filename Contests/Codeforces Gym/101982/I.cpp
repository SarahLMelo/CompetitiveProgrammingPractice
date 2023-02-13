#include <bits/stdc++.h>

using namespace std;
#define int long long

struct RabinKarp{
    private:
        string s;
        int n, base, mod;
        vector <int> p, h;

    public:
        RabinKarp(string &s, int base = 243, int mod = 1e9 + 7){
            this->s = s;
            this->n = s.size();

            this->base = base;
            this->mod = mod;

            build();
        }
        
        int hash(int l, int r){
            if(!l) return h[r];
            return (h[r] - ((h[l-1] * p[r - l + 1]) % mod) + mod) % mod;
        }

    private:
        void build(){
            p.assign(n+1, 1);
            for(int i = 1; i <= n; i++){
                p[i] = (p[i-1] * base) % mod;
            }

            h.assign(n, s[0]);
            for(int i = 1; i < n; i++){
                h[i] = (h[i-1] * base + s[i]) % mod;
            }
        }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int caso = 1; caso <= t; caso++){
        string s;
        cin >> s;
        RabinKarp rk(s);

        int ans = 0;
        for(int i = 1; i < s.size(); i++){
            ans += rk.hash(0, i-1) == rk.hash(s.size() - i, s.size() - 1);
        } 

        cout << "Case " << caso << ": " << ans << "\n";
    }


    return 0;
}