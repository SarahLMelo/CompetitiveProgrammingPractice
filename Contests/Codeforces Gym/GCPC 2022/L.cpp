#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int l, w, n;
    cin >> l >> w >> n;

    if(l * w % n) cout << "IMPOSSIBLE\n";
    else{
        int area = l*w/n;

        set <int> divl, divw;

        for(int i = 1; i * i <= l; i++){
            if(l % i) continue;
            divl.emplace(i);
            divl.emplace(l/i);
        }

        for(int i = 1; i * i <= w; i++){
            if(w % i) continue;
            divw.emplace(i);
            divw.emplace(w/i);
        }

        int x, y;
        for(auto i:divl){
            if(area % i) continue;
            // cout << area/i << "\n";
            if(divw.find(area/i) != divw.end()){
                // cout << "HERE" << endl;
                x = i;
                y = area/i;
            }
        }
        // cout << x << " " << y << endl;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < w; j++){
                int aux1 = i/x, aux2 = j/y;
                cout << (char)('A' + (i/x)*(w/y) + (j/y));
            }
            cout << "\n";
        }
    }

    return 0;
}