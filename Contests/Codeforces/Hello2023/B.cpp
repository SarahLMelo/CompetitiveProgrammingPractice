#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t = 1;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n&1){
            if(n == 3) cout << "NO\n";
            else{
                cout << "YES\n";
                int f = (n - 3)/2, s = - (f+1);
                for(int i = 0; i <  n; i++){
                    if(i) cout << " ";
                    cout << (i&1 ? s:f);
                }
                cout << "\n";
            }
        }
        else{
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                if(i) cout << " ";
                cout << (i&1 ? -1:1);
            }
            cout << "\n";
        }
    }

    return 0;
}   