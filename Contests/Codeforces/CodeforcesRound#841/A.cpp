#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue <int> pq;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;

            pq.emplace(x);
        }

        int ans = 0;
        while(pq.size() > 1){
            int x, y;
            x = pq.top();
            pq.pop();

            y = pq.top();
            pq.pop();

            pq.emplace(x*y);
            ans++;
        }

        if(!pq.empty()) ans += pq.top();

        cout << ans * 2022 << "\n";
    }

    return 0;
}