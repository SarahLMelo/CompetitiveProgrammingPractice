#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int a, b;
    cin >> a >> b;

    int ans = 1;
    a--;
    b--;


    for(int x = 1; x < a; x++){
        int t = (a+x) * (a-x);
        int y = sqrt(t);

        if(y*y == t || (y+1)*(y+1)==t){
            if(!((x*b)%a) && !((y*b)%a)) ans++;
        }
    }
    if(a!=b) ans*=2;

    cout << ans << "\n";

    return 0;
}