#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
vector <vector <int>> g;
vector <int> tIn, low, cutEdge;
vector <bool> vis;

void dfs(int pos = 0, int par = -1){
    vis[pos] = 1;
    int childCount = 0;

    for(auto i:g[pos]){
        if(i == par) continue;

        if(vis[i]){ 
            low[pos] = min(low[pos], tIn[i]);
        }

        else{
            childCount++;
            tIn[i] = low[i] = ++cnt;
            dfs(i, pos);

            low[pos] = min(low[pos], low[i]);
            if(low[i] >= tIn[pos] && pos) cutEdge.push_back(pos);
        }

    }

    if(!pos && childCount>1) cutEdge.push_back(pos);

    return;
}

int main(){
    int cnt = 1;

    cin >> n >> m;

    while(n){
        g.assign(n, {});
        tIn.assign(n, -1);
        low.assign(n, -1);
        vis.assign(n, 0);
        cutEdge = {};

        while(m--){
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        tIn[0] = 0;
        low[0] = 0;
        vis[0] = 1;
        // cnt = 0;

        dfs();

        cout << "Teste " << cnt++ << "\n";
        if(cutEdge.empty()) cout << "nenhum\n";
        else{
            sort(cutEdge.begin(), cutEdge.end());
            cutEdge.resize(unique(cutEdge.begin(), cutEdge.end()) - cutEdge.begin());
            
            for(int i = 0; i < cutEdge.size(); i++){
                if(i) cout << " ";
                cout << cutEdge[i]+1;
            }

            cout << "\n";
        }

        cout << "\n";


        cin >> n >> m;
    }

    return 0;
}