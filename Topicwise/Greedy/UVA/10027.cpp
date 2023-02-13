#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second >= b.second;
}

int main(){
    int t;
    cin >> t;

    for(int cnt = 0; cnt < t; cnt++){
        if(cnt) cout << "\n";

        int m;
        cin >> m;

        vector <pair <int, int>> v, ans;

        int l, r;
        cin >> l >> r;

        while(l || r){
            v.emplace_back(l, r);

            cin >> l >> r;
        }

        sort(v.begin(), v.end(), cmp);

        // for(auto i:v){
        //     cout << i.first << " " << i.second << "\n";
        // }

        // cout << endl;

        pair <int, int> aux = {-50005, -50005};
        for(int i = 0; i < v.size() && l < m; i++){
            // cout << l << " " << v[i].first << " " << v[i].second << "\n";
            if(l > v[i].second) continue;
            if(l < v[i].first){
                if(aux.first == -50005) break;

                ans.push_back(aux);
                l = aux.second;
                aux = {-50005, -50005};
                i--;
            }
            else{
                if(aux.second < v[i].second) aux = v[i];
            }
        }

        if(aux.first != -50005){
            ans.push_back(aux);
            l = aux.second;
        }

        if(l < m) cout << "0\n";
        else{
            cout << ans.size() << "\n";

            for(auto i:ans){
                cout << i.first << " " << i.second << "\n";
            }
        }
    }

    return 0;
}