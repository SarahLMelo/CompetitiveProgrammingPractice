#include <bits/stdc++.h>

using namespace std;
// #define int long long
// #define cin input
// #define cout output

ofstream output;
ifstream input;
vector <int> v;
int n, k;

bool test(int m){
    int hit = 0;
    set <int> incache;
    map <int, int> lastvis;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;

    for(int i = 0; i < n; i++){
        // if(m == 2){
        //     for(auto j:incache) cout << j << " ";
        //     cout << "\n";
        // }
            
        if(incache.find(v[i]) != incache.end()){
            hit++;
            // if(m == 2){
            //     cout << v[i] << " " << i << "\n";
            // }
        }

        else{
            if(incache.size() == m){
                pair <int, int> top = pq.top();

                while(lastvis[top.second] != top.first){
                    pq.pop();
                    top = pq.top();
                }

                lastvis[top.second] = -1;
                incache.erase(top.second);
                pq.pop();   
            }
            incache.emplace(v[i]);
            
        }

        lastvis[v[i]] = i;
        pq.emplace(i, v[i]);
    }

    return hit >= k;
}

void solve(){
    cin >> n >> k;

    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 1, r = n+1;
    while(l < r){
        int mid = (l + r)/2;
        // cout << l << " " << r << endl;

        if(test(mid)) r = mid;
        else l = mid+1;
    }

    if(l == n+1) cout << "cbddl\n";
    else cout << l << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // output.open ("out");
    // input.open("in");
    // int t;
    // cin >> t;
    // while(t--)
        solve();

    // output.close();
    // input.close();


    return 0;
}