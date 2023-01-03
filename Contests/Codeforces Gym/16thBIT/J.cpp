#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        while(!(x&1) && x>0){
            x >>= 1;
            x--;
        }

        // cout << x << " " << "\n";
        ans ^= (x+1)/2;
    }

    if(ans) cout << "Alice\n";
    else cout << "Bob\n";

    return 0;
}