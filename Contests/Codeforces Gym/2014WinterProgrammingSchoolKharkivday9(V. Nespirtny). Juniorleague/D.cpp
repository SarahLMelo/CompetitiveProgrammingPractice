#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if(a + b <= c) cout << "Impossible\n";
    else if(b + c <= a) cout << "Impossible\n";
    else if(a + c <= b) cout << "Impossible\n";
    else{
        cout << 0 << " " << 0 << "\n";
        cout << 0 << " " << a << "\n";
        
        double x, y;

        y = 1.0*(c*c + a*a - b*b)/(2.0*a);
        x = sqrt(1.0*c*c - y*y);

        cout << setprecision(9) << fixed;
        cout << x << " " << y << "\n";
        
    }
    
    return 0;
}