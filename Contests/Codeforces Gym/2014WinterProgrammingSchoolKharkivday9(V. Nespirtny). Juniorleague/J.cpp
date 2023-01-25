#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    n++;

    vector <int> v(n);
    int sum  = 0;

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    bool isValid = true;
    for(int i = n-1; i > 0 && isValid; i--){
        if((v[i] + sum) % (i)){
            isValid = false;
        }
        else{
            sum += (v[i] + sum)/(i);
        }
    }

    cout << (isValid? "Yes\n":"No\n");
    
    return 0;
}