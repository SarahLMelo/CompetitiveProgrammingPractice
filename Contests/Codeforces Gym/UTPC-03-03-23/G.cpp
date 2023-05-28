#include <bits/stdc++.h>

using namespace std;
#define int long long
int m;
vector <int> primes;

void primefac(){
    for(int i = 2; i * i <= m; i++){
        if(m % i) continue;
        
        primes.push_back(i);
        while(!(m % i)){
            m /= i;
        }
    }

    if(m != 1) primes.push_back(m);

    return;
}

int solve(int x){
    int total = x;

    for(int i = 1; i < (1 << primes.size()) ; i++){
        bool par = (__builtin_popcountll(i) & 1);

        int val = 1;
        for(int j = 0; j < primes.size(); j++){
            if(i & (1 << j)){
                val *= primes[j];
            }
        }
        // cout << val << " ";
        if(par) total -= (x / val);
        else total += (x / val);
    }

    // cout << total << "\n";
    return total;
}

int32_t main(){
    int n;
    cin >> n >> m;

    primefac();


    for(int i = 0; i < n; i++){
        int ask;
        cin >> ask;

        int l = ask, r = 2e9;

        while(l < r){
            int mid = (l+r)/2;

            int miss = ask - solve(mid);
            if(miss > 0) l = mid + 1;
            else r = mid;
        }

        cout << l << " ";
    }

    return 0;
}