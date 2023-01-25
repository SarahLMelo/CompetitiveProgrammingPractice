#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, n;
    cin >> p >> n;

    vector <int> a(n+1);
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    for(int i = 0; i <= p*p; i++){
        int aux = 1, sum = a[0];
        for(int j = 1; j <= n; j++){
            aux *= i;
            aux %= p*p;
            sum += a[j] * aux; 
            sum %= p*p;
        }

        if(!(sum % (p*p))){
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    
    return 0;
}