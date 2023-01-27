#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1000003397, b = 31;

vector <int> pot, potInv, hs;
string s;
int n;
int fExp(int a, int b){
    int ans = 1;

    while(b){
        if(b & 1) ans = ans * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}

void init(){
    n = s.size();

    pot.resize(n + 1);
    hs.resize(n + 1);
    potInv.resize(n + 1);

    pot[0] = 1;
    hs[0] = 0;
    for(int i = 1; i <= n; i++){
        pot[i] = pot[i-1] * b % mod;
        potInv[i] = fExp(pot[i], mod - 2);
        hs[i] = ((s[i-1] - 'a' + 1)*pot[i-1] + hs[i-1]) % mod;
    }

}


bool sufPref(int sz){
    int suf = (hs[n] - hs[n - sz] + mod) % mod;
    suf = suf * fExp(pot[n - sz], mod-2) % mod;

    return suf == hs[sz];
}

bool check(int sz){

    for(int i = 1; i + sz < n; i++){
        int aux = (hs[i + sz] - hs[i] + mod) % mod;
        aux = aux * potInv[i] % mod;

        if(aux == hs[sz]) return true;
    }

    return false;
}

int32_t main(){
    cin >> s;

    if(s.size() == 1){
        cout << "Just a legend\n";
        return 0;
    }
    init();

    vector <int> aux(1, 0);

    for(int i = 1; i <= n; i++){
        if(sufPref(i)) aux.push_back(i);
    }

    int l = 0, r = aux.size();
    while(l < r){
        int mid = (l+r)/2;

        if(check(aux[mid])) l = mid + 1;
        else r = mid;
    }

    l--;

    if(l){
        for(int i = 0; i < aux[l]; i++){
            cout << s[i];
        }
        cout << "\n";
    }
    else cout << "Just a legend\n";

    return 0;
}