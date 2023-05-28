#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, x;
    cin >> n >> x;

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    long double b, sum = 0;
    b = n*x;

    for(int i = 0; i < n; i++)
        sum += a[i] * a[i];

    if(sum == 0 || x == 0){
        b = 0;
    }
    else{
        b /= sum;
        b = sqrtl(b); 
    }
    

    cout << setprecision(11) << fixed;
    for(int i = 0; i < n; i++)
        cout << a[i] * b << " ";
    
    cout << "\n";

    return 0;
}