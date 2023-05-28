#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    cout << setprecision(8) << fixed;
    pair <int, int> fib[31];
    fib[1] = {0, 1};
    fib[0] = {1, 0};
    fib[2] = {1, 1};
    for(int i = 3; i < 31; i++) fib[i] = {fib[i-1].first + 2*fib[i-2].first, fib[i-1].second + 2*fib[i-2].second};

    int n;
    cin >> n;
    n--;

    n = min(n, 30LL);
    cout << 100.0 * fib[n].first / (fib[n].first + fib[n].second) << " ";
    cout << 100.0 * fib[n].second / (fib[n].first + fib[n].second) << "\n";

    return 0;
}