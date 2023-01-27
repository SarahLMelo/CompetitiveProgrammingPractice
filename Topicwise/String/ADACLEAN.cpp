#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod1 = 1e9+7, mod2 = 1e9+9 , base1 = 761, base2 = 243 , mx = 1e5+5;

pair <int, int> pot[mx];

void init(){
    pot[0] = {1, 1};

    for(int i = 1; i < mx; i++){
        pot[i].first = pot[i-1].first * base1 % mod1;
        pot[i].second = pot[i-1].second * base2 % mod2;
    }
}

int32_t main(){
    init();

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <pair <int, int>> h(n + 1);
        h[0] = {0,0};

        for(int i = 0; i <n; i++){ //Calculando os hashes
            h[i+1].first = (h[i].first + (s[i] - 'a' + 1) * pot[i].first) % mod1;
            h[i+1].second = (h[i].second + (s[i] - 'a' + 1) * pot[i].second) % mod2;
        }

        set <pair <int, int>> ans;
        for(int i = 0; i + k <= n; i++){ //Calculando todos de tamanho k
            int aux1 = (h[i + k].first - h[i].first + mod1) % mod1, aux2 = (h[i + k].second - h[i].second + mod2) % mod2;
            aux1 = (aux1 * pot[n-i-1].first) % mod1;
            aux2 = (aux2 * pot[n - i - 1].second) % mod2;

            ans.emplace(aux1, aux2);
        }

        cout << ans.size() << "\n";
    }


    return 0;
}