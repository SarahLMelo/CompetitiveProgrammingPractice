#include <bits/stdc++.h>

using namespace std;

int main(){
    int dp[100];
    dp[0] = 0;

    for(int i = 1; i < 100; i++){
        set <int> nimbers;
        for(int x = 1; 2 * x <= i+1; x++){
            nimbers.insert(dp[i-x]);
        }

        int ans = 0;
        while(nimbers.count(ans) > 0)
            ans++;
        
        dp[i] = ans;
    }

    for(int i = 0; i < 100; i++){
        cout << i << ": " << dp[i] << "\n";
    }


    return 0;
}