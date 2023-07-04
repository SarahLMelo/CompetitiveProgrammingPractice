#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 105;
int memo[MAXN][MAXN][MAXN], n;
vector <int> v;

int dp(int pos, int sz, int amount){
    if(pos == n){
        if(sz & 1 && (amount) & 1) return 1;
        else return false;
    }

    int &ans = memo[pos][sz][amount];
    if(~ans) return ans;

    //Continuando a sequencia
    ans = dp(pos+1, sz+1, amount);

    if((v[pos]&1) && (sz&1)) ans = max(ans, dp(pos+1, 0, amount+1));
    
    return ans;
}

void solve(){
    memset(memo, -1, sizeof memo);
    cin >> n;
    v.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    if(!(v[0]&1) || !(n&1) || !(v.back() & 1)){
        cout << "No\n";
        return;
    }
    else cout << "YES\n";

    // if(dp(0, 0, 1)) cout << "Yes\n";
    // else cout << "No\n";
}

int32_t main(){
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}