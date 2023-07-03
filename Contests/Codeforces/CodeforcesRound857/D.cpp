#include <bits/stdc++.h>

using namespace std;
#define int long long

bool cmp(pair <int, int> &a, pair <int, int> &b){
    return a.second > b.second;
}

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <pair <int, int>> shops(n);
        multiset <int> a;
        for(int i = 0; i < n; i++){
            cin >> shops[i].first >> shops[i].second;
            a.emplace(shops[i].first);
        }

        sort(shops.begin(), shops.end(), cmp);
        
        int maxA = -1e16, ans = 1e15;
        for(int i = 0; i < n; i++){
            a.erase(a.find(shops[i].first));

            auto it = a.lower_bound(shops[i].second);
            int mh = abs(maxA - shops[i].second);
            if(it != a.end()) mh = min(mh, abs(max(*it, maxA) - shops[i].second));
            if(it != a.begin()) mh = min(mh, abs(shops[i].second - max(*(--it), maxA)));

            ans = min(ans, mh);
            maxA = max(maxA, shops[i].first);
        }

        cout << ans << "\n";
    
    }

    return 0;
}

/*
7 10
2 10
1 10
1 10

*/