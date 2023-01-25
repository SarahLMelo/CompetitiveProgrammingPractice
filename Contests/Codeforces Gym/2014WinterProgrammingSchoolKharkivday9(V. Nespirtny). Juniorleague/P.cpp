#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> a(n), b(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0, ans = 0;

    for(int i = 0; i < n; i++){
        if(b[i] >  a[l]){
            ans++;
            l++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}