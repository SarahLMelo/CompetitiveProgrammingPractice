#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, c, r;
vector <int> v;
typedef tuple<int, int, int, int> iiii;

int32_t main(){
    cin >> n >> c >> r;

    v.resize(n);
    set <pair <int, int>> inter;
    priority_queue <iiii, vector <iiii>, greater <iiii>> pq;
    int ans = 0, now = 0;

    int last_non_zero = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];

        if(!v[i]) now+= r;
        else{
            if(last_non_zero * v[i] > 0) now+=r;
            last_non_zero = v[i];
        }

        if(i){
            inter.emplace(i-1, i);
            if(i+1 < n) pq.emplace(abs(v[i]), i, i -1, i + 1);
            else pq.emplace(abs(v[i]), i, i - 1, i);
        }
        else{
            if(i+1 < n) pq.emplace(abs(v[i]), i, i, i + 1);
            else pq.emplace(abs(v[i]), i, i, i);
        }    
    }

    ans = now;

    while(!pq.empty()){
        int val = get<0>(pq.top());
        now = c*val;

        while(!pq.empty() && get<0>(pq.top()) == val){
            int l, x, r;
            tie(val, x, l, r) = pq.top();
            pq.pop();

            if()

            if((x - l) & 1){
                
            }
        }

        ans = min(ans, now);
    }
    


    return 0;
}