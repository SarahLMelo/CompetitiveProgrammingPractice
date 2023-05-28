#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <vector <int>> dp;
string p = "cdhs";
string s;

int solve(int pos, int naipe){
    if(pos == s.size()) return 0;
    if(dp[pos][naipe] != -1) return dp[pos][naipe];
    
    int ans = solve(pos+1, naipe) + (s[pos] != p[naipe]);
    if(naipe < 3) ans = min(ans, solve(pos, naipe+1));

    return dp[pos][naipe] = ans;
}


int32_t main(){
    cin >> s;

    map <char, int> freq;
    for(auto i:s) freq[i]++;

    
    int ans = 1e9;

    do{
        dp.assign(s.size(), vector <int> (4, -1));
        ans = min(ans, solve(0, 0));
    }
    while(next_permutation(p.begin(), p.end()));

    cout << ans << "\n";

    return 0;
}