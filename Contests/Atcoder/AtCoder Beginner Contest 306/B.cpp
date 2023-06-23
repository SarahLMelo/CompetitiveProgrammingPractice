#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long ans = 0;

    for(unsigned long long i = 0; i < 64; i++){
        unsigned long long x;
        cin >> x;

        ans += x * (1ULL<<i);
    }

    cout << ans << "\n";
}