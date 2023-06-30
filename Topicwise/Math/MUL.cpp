#include <bits/stdc++.h>

using namespace std;

#define int long long
vector <int> dp, vals;
int n;

int solve(int pos){
    if(pos == n) return 0;
    int &ans = dp[pos];

    if(~ans) return ans;

    int smash, not_smash;
    not_smash = solve(pos + 1);
    for(int i = pos; i <= n; i += pos){
        
    }
}

int32_t main(){

    
    return 0;
}