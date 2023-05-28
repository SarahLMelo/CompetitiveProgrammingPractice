#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair <int, int> ii;
vector <ii> ans;

void solve(int a, int b){
    if(!a || !b) return;

    if(a > b){
        ans.emplace_back(1, a/b);
        solve(a % b, b);
    }
    else{
        ans.emplace_back(2, b/a);
        solve(a, b % a);
    }
}

int32_t main(){
    int a, b;
    cin >> a >> b;

    solve(abs(a), abs(b));

    cout << ans.size() << "\n";
    bool changesign = (a > 0 && b > 0) || (a < 0 && b < 0);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << (changesign ? -1:1) * ans[i].second << "\n";
    }

    return 0;
}