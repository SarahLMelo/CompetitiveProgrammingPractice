#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> freq(n+1, 0), ans;
    for(int i = 0; i < 3*n; i++){
        int x;
        cin >> x;

        if(freq[x] == 1) ans.push_back(x);
        freq[x]++;
    }

    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";

    return 0;
}