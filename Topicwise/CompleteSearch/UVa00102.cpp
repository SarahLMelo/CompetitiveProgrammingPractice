#include <bits/stdc++.h>

using namespace std;

int main(){
    
    while(!cout.eof()){
        int bin[3][3];

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) cin >> bin[i][j];
        }

        string aux = "BCG";
        vector <pair <string, int>> ans;

        do{
            int dif = 0;

            for(int i = 0; i < 3; i++){
                if(aux[i] != 'B') dif += bin[i][0];
                if(aux[i] != 'G') dif += bin[i][1];
                if(aux[i] != 'C') dif += bin[i][2];
            }

            // cout << aux << " " << dif << "\n";

            ans.emplace_back(aux, dif);
        }
        while(next_permutation(aux.begin(), aux.end()));

        int min = 1e9, id = -1;
        for(int i = 0; i < ans.size(); i++)
            if(min > ans[i].second){
                min = ans[i].second;
                id = i;
            }

        cout << ans[id].first << " " << ans[id].second << "\n";
    }

    return 0;
}