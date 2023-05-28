#include <bits/stdc++.h>

using namespace std;
#define int long long
// #define cin input
// #define cout output

ofstream output;
ifstream input;
int game(int l1, int f1, int l2, int f2, int turn, int damage){
    int ans;
    if(turn == 1){
        l1 -= f1;
        if(l1 <= 0) return 2;

        ans = game(l1, f1+1, l2 - damage, f2, 2, damage);
        ans = min(ans, game(l1 + damage, f1+1, l2, f2, 2, damage));
    }
    else{
        l2 -= f2;
        if(l2 <= 0) return 1;

        ans = game(l1 - damage, f1, l2, f2, 1, damage);
        ans = max(ans, game(l1, f1, l2 + damage, f2, 1, damage));
    }

    return ans;
}

void solve(){
    // for(int n = 1; n < 15; n++)
    //     for(int k = 1; k < 15; k++)
    //         cout << n << " " << k << ": " << game(n, 1, n, 1, 1, k) << "\n";

    int n, m;
    cin >> n >> m;

    m += 2;
    if(n == 1){
        cout << "freesin\n";
        return;
    }

    if(n == 2){
        cout << "pllj\n";
        return;
    }

    if(n - m >= 0) cout << "freesin\n";
    else cout << "pllj\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // output.open ("out");
    // input.open("in");
    int t;
    cin >> t;
    while(t--)
        solve();

    // output.close();
    // input.close();


    return 0;
}