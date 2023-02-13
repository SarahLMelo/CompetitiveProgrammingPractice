#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;
    
    
    cout << min(15LL, (3000 / x + (3000 % x? 1:0))) << "\n";

    return 0;
}