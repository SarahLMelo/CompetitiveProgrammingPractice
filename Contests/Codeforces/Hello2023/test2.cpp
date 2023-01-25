#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;

    vector <int> preffix(n);
    for(int i = 0; i < n; i++){
        cin >> preffix[i];
        if(i) preffix[i] += preffix[i-1];
    }

    for(int i = 0; i < n; i++){
        cout << preffix[i] << " ";
    }
    cout << "\n";

    return 0;
}