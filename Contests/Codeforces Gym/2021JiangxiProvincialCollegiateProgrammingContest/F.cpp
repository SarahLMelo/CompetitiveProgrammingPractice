#include <bits/stdc++.h>

using namespace std;
// #define int long long
// #define cin input
// #define cout output

ofstream output;
ifstream input;

int brute(int n, int rod1, int rod2, int aux1, int aux2){
    if (!n) return 0;
    if (n == 1) return 1;
    
    int ans = brute(n - 2, rod1, aux1, aux2, rod2) + 3 + brute(n - 2, aux1, rod1, rod2, aux2);
    return ans;
}

void solve(){
    for(int i = 1; i <= 15; i++){
        cout << i << ": " << brute(i, 1, 2, 3, 4) << endl;
    }
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