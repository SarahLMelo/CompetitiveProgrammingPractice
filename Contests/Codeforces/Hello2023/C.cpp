#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t = 1;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(i<m){
                sum+=v[i];
            }
        }
        
        int cnt = 0;
        int aux = sum - v[m-1];
        priority_queue <pair <int, int>> pq;
        pq.emplace(v[m-1], m-1);

        for(int i = m-2; i >= 0; i--){
            cout << i << " " << aux << " " << sum << "\n";
            while(aux < sum){
                cout << i << " " << aux << " " << sum << "\n";
                int change = pq.top().first, pos = pq.top().second;
                pq.pop();

                sum += 2*(-change);
                v[pos] = -change;
                cnt++;
            }
            aux -= v[i];
            if(v[i] > 0) pq.emplace(v[i], i);
            
        }


        priority_queue <int, vector <int>, greater <int>> pq2;
        aux = sum;
        for(int i = m; i < n; i++){
            if(v[i] < 0) pq2.emplace(v[i]);

            aux += v[i];
            while(aux < sum){
                int change = -pq2.top();
                pq.pop();
                aux += 2*change;
                // cout << change << " ";
                cnt++;
            }
        }
        // cout << "\n";
        cout << cnt << endl;
    }

    return 0;
}   