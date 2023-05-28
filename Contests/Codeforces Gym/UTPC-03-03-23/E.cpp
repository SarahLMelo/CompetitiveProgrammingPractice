#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector <int> prefix(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }

    while(q--){
        int k;
        cin >> k;

        int x = 0, y = n+1;
        for(int i = 0; i < n+1; i++){
            int l = i, r = n+1;

            while(l < r){
                int mid = (l+r)/2;
                if(prefix[mid] - prefix[i] < k) l = mid + 1;
                else r = mid;
            }

            if(prefix[r] - prefix[i] == k && r - i < y - x){
                x = i;
                y = r;
            }
        }

        cout << x << " " << y-1 << "\n";
    }

    return 0;
}