#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    // cin >> s;

    for(int i = 1; i <= n; i++){
        int cnt = 0, aux = i;

        while(!(aux&1)){
            cnt++;
            aux >>= 1;
        }

        s.push_back('a' + cnt);
    }

    cout << s << "\n";
    
    return 0;
}