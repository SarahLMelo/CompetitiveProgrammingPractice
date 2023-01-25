#include <bits/stdc++.h>

using namespace std;
int n;

bool bt(vector <int> v, int pos){
    if(pos == v.size()){
        bool ans = true;
        int sum  = 0;
        for(int i = 0; i < v.size(); i++) sum+=v[i];
        for(int i = 0; i < v.size() -1 && ans; i++){
            if(v[i] + v[i+1] != sum) ans = false;
        }
        
        return ans;
    }

    bool ans = false;

    for(int i = -n; i <= n; i++){
        if(i == 0) continue;
        v[pos] = i;
        ans = bt(v, pos+1);
        if(ans && pos+1 == n){
            for(int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << endl;
            break;
        }
    }

    return ans;
}

int main(){
    cin >> n;

    cout << bt(vector <int> (n), 0);

}