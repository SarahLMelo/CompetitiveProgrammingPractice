#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int last = 0, ans;

    for(int i = 0; i < 41; i++){
        cout << "? " << (1LL<<i) << endl;
        int x;
        cin >> x;
        
        if((1LL<<i) != x){
            cout << "! " << (1LL<<i) - x << endl;
            return 0;
        }

        last = x;
    }

    return 0;
}