#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int d;
        cin >> d;

        vector <string> names(d);
        vector <pair <int, int>> values(d);

        for(int i = 0; i < d; i++){
            cin >> names[i] >> values[i].first >> values[i].second;
        }

        int q;
        cin >> q;

        while(q--){
            int ans = -1, x;
            
            cin >> x;
            for(int i = 0; i < d; i++){
                if(x <= values[i].second && x >= values[i].first){
                    if(ans != -1){
                        ans = -1;
                        break;
                    }
                    else ans = i;
                }
            }

            if(ans == -1) cout << "UNDETERMINED\n";
            else cout << names[ans] << "\n";
        }
        if(t) cout << "\n";

    }

    return 0;
}