#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int bAns = 1e9;

    for(int i = 0; i+2 < n; i++){
        int difCount = 0;
        for(int j = 0; j < 3; j++){
            if(v[i+j] != v[i+j+1]) difCount++;
        }

        if(difCount == 2){

        }
        else{
            
        }
    }

    return 0;
}