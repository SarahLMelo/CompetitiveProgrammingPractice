#include <bits/stdc++.h>

using namespace std;

const int mxe = 105, mxpb = 105, mxtm = (1<<11);
int dp[mxtm][mxpb][mxe];
vector <int> dif, energy, score;
int t, p;

int solve(int tm, int pb, int en){
    // cout << "HERE" << "\n";
    if(dif.size() == pb) return 0;
    int &ans = dp[tm][pb][en];
    if(~ans) return ans;

    ans = solve(tm, pb+1, en);
    for(int i = 0; i < t; i++){
        if((1 << i) & tm) continue;
        ans = max(ans, solve(tm | (1 << i), pb, energy[i]));
    }
    if(en - dif[pb] >= 0) ans = max(ans, solve(tm, pb + 1, en - dif[pb]) + score[pb]);

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);

    cin >> t >> p;
    dif.resize(p);
    energy.reserve(t);
    score.resize(p);

    for(int i = 0; i < t; i++) cin >> energy[i];
    for(int i = 0; i < p; i++) cin >> dif[i];
    for(int i = 0; i < p; i++) cin >> score[i];

    int ans = 0;
    for(int i = 0; i < t; i++){
        ans = max(ans, solve((1 << i), 0, energy[i]));
    }

    cout << ans << "\n";

    return 0;
}