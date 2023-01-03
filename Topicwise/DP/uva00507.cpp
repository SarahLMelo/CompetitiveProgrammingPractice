#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int k = 1; k <= t; k++){
        int n;
        cin >> n;

        pair <int, int> dp[n];

        // cout << "HERE" << endl;

        dp[0] = {0, 1};

        for(int i = 1; i < n; i++){
            int x;
            cin >> x;

            if(dp[i-1].first + x < x){
                dp[i] = {x, i};
            }
            else dp[i] = {dp[i-1].first + x, dp[i-1].second};
        }

        int ans = -1;

        for(int i = 1; i < n; i++){
            if(dp[i].first < 0) continue;

            if(ans == -1) ans = i;
            else{
                if(dp[i].first > dp[ans].first) ans = i;
                else if(dp[i].first == dp[ans].first && i+1 - dp[i].second > ans+1 - dp[ans].second) ans = i;
            }
        }

        if(ans == -1) cout << "Route " << k <<" has no nice parts\n";
        else
            cout << "The nicest part of route " << k << " is between stops " << dp[ans].second << " and " << ans+1 << "\n";
            // cout << endl;
    }
    

    return 0;
}