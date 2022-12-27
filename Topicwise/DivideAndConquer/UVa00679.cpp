#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <vector <int>> precalc(21);
    precalc[1].push_back(1);

    for(int i = 2; i < 21; i++){
        for(auto j:precalc[i-1]){
            precalc[i].push_back(j<<1);
        }
        for(auto j:precalc[i-1]){
            precalc[i].push_back((j<<1) + 1);
        }
    }


    int t;
    cin >> t;

    while(t--){
        int d, i;
        cin >> d >> i;

        i -= 1;
        i %= 1<<(d - 1);

        cout << precalc[d][i] << "\n";
    }
    int x;
    cin >> x;

    return 0;
}