#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t = 1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') l++;
            else r++;
        }

        if(r == 0 || l == 0) cout << "-1\n";
        else{
            int pos = 0;

            for(int i = 0; i < n-1; i++){
                if(s[i] == 'L' && s[i+1] == 'R') pos = i+1;
            }

            cout << pos << "\n";
        }
    }

    return 0;
}