#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, k;
int color[11][11];

bool check(int x, int y){
    if(x == 0 || y == 0) return true;

    int b = 0;
    if(color[x-1][y-1] == 1) b++;
    if(color[x][y-1] == 1) b++;
    if(color[x-1][y] == 1) b++;
    if(color[x][y] == 1) b++;

    return (b == 3 || b == 1);
}

int bt(int x, int y){
    if(x == n) return 1;

    int ans = 0;
    if(color[x][y] == 0){
        color[x][y] = 1;
        if(check(x, y)){
            if(y+1 == m) ans += bt(x+1, 0);
            else ans += bt(x, y+1);
        }


        color[x][y] = 2;
        if(check(x, y)){
            if(y+1 == m) ans += bt(x+1, 0);
            else ans += bt(x, y+1);
        }

        color[x][y] = 0;
    }
    else{
        if(check(x, y)){
            if(y+1 == m) ans += bt(x+1, 0);
            else ans += bt(x, y+1);
        }
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int x, y, c;
        cin >> x >> y >> c;

        x--; y--; c++;

        color[x][y] = c;
    }

    cout << bt(0, 0) << "\n";

    return 0;
}