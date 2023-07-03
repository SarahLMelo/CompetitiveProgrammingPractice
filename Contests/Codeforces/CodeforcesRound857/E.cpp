#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        priority_queue <vector <int>, vector <vector <int>>, greater <vector <int>>> pq;

        cin >> n;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;

            vector <int> LIS;
            for(int i = 0; i < m; i++){
                int x;
                cin >> x;

                if(LIS.empty() || x > LIS.back()) LIS.emplace_back(x);
            }

            pq.emplace(LIS);
        }

        while(pq.size() > 1){
            
        }
    }

    return 0;
}