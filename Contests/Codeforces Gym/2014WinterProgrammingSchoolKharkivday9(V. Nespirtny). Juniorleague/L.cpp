#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    
    k--;
    vector <int> v(1, 1);

    int pos = 2;
    while(k){
        v.push_back(pos);
        k -= pos;
        for(int i = 1; i < pos-1; i++){
            if(v[i]){
                k++;
                v[i]--;
            }
            else{
                v[i] = i+1;
                k -= i+1;
            }
        }
        pos++;
    }
    for(int i = 0; i < v.size(); i++){
        if(!v[i]) continue;
        cout << i+1 << " " << v[i] << "\n";
    }
    
    return 0;
}