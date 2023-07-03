#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int cnt = 0;
        vector <int> mn(n), mx(n);
        int neg = 0, pos = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;

            if(x > 0) pos++;
            else neg++;
        }

        mx[0] = 1;
        for(int i = 1; i < pos; i++){
            mx[i] = mx[i-1] + 1;
        }
        for(int i = 0; i < neg; i++){
            mx[pos + i] = mx[pos + i - 1] - 1;
        }

        mn[0] = 1;
        for(int i = 1; i < n; i++){
            if(i & 1){
                if(neg > 0){
                    mn[i] = mn[i-1] - 1;
                    neg--;
                }
                else{
                    mn[i] = mn[i-1] + 1;
                    pos--;
                }
            }

            else{
                if(pos > 0){
                    mn[i] = mn[i-1] + 1;
                    pos--;
                }
                else{
                    mn[i] = mn[i-1] - 1;
                    neg--;
                }
            }
        }

        for(auto i:mx) cout << i << " ";
        cout << "\n";
        for(auto i:mn) cout << i << " ";
        cout << "\n";
    }

    return 0;
}