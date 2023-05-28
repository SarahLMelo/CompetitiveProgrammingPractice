#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    map <string, int> freq;
    while(t--){
        int x;
        cin >> x;

        string s = "";
        for(int i = 0; i < x; i++){
            string aux;
            cin >> aux;

            s.push_back(aux[0]);
        }

        freq[s]++;
    }

    int ans = 0;
    for(auto i:freq){
        if(i.second == 1) ans++;
    }

    cout << ans << "\n";

    return 0;
}