#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector <bool> dp(n);

    dp[0] = 1;
    int cnt = 2;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < cnt && i + j < n; j++){
            dp[i + j] = 0;
        }
        i += cnt;
        for(int j = 0; j < cnt && i + j < n; j++){
            dp[i + j] = 1;
        }
        i += cnt - 1;
        cnt++;
    }

    // for(int i = 0; i < n; i++){
    //     cout << i+1 << ": " << dp[i] << "\n";
    // }

    if(dp[n-1]) cout << "Jane\n";
    else cout << "John\n";

    return 0;
}