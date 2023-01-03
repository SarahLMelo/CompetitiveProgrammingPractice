#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> mumbai;
int n, m;

bool check(int l){
    // cout <<"l: " << l << "\n";
    int ans = false;
    for(int i = 0; i+l-1 < n && !ans; i++){
        for(int j = 0; j+l-1 < m && !ans; j++){
            int aux = true;
            for(int a = 0; a < l && aux; a++){
                for(int b = 0; b < l && aux; b++){
                    // cout << mumbai[i+a][j+b] << " ";
                    aux = (l <= mumbai[i+a][j+b]);
                }
                // cout << "\n";
            }

            ans = aux;
        }
    }

    // cout << "end\n";

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;
        
        mumbai.assign(n, vector <int> (m, 0));

        int r = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mumbai[i][j];
                r = max(r, mumbai[i][j]);

                // cout << mumbai[i][j] << " ";
            }
            // cout << "\n";
        }

        int l = 0;
        r = min(r+1, min(m, n) + 1);

        while(l < r){
            int mid = (l+r)/2;
            if(check(mid)){
                l = mid + 1;
            }
            else r = mid;
        }
        cout << --l << "\n";
    }

    return 0;
}