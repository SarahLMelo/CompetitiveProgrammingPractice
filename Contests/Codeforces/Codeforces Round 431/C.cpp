#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    // int n;
    // cin >> n;

    for(int t = 1; t <= 100000; t++){
        int n = t;
        cout << n << ":\n";
        string s = "";

        for(int i = 0; i < 26; i++){
            int l = 0, r = 100005;
            while(l < r){
                int mid = (l+r)/2;

                if(mid*(mid-1)/2 <= n) l = mid + 1;
                else r = mid;
            }
            l--;

            n -= l*(l-1)/2;
            for(int j = 0; j < l; j++) s.push_back('a' + i);
        }
        cout << s << "\n";
    }


    return 0;
}