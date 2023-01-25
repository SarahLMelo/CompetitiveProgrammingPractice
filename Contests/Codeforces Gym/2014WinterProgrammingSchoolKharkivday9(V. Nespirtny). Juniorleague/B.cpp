#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;

    for(int i = n; i <= n*9; i++){
        int maxn, minn;
        int x = 0, aux = i;

        for(int i = 0; i < n; i++){
            x*=10;
            x += min(9LL, aux);

            aux -= min(9LL, aux);;
        }

        maxn = x;

        x = 0, aux = i;

        for(int i = 0; i < n; i++){
            x*=10;
            if(i){
                x += max(0LL, aux - (9*(n-i-1)));
                aux -= max(0LL, aux - (9*(n-i-1)));
            }
            else{
                x += max(1LL, aux - (9*(n-i-1)));
                aux -= max(1LL, aux - (9*(n-i-1)));
            }
        }

        minn = x;

        // cout << maxn[i] << " " << minn[i] << " " << maxn[i] - minn[i] << "\n";
        ans = max(ans, maxn - minn);
    }

    cout << ans << "\n";
    
    return 0;
}