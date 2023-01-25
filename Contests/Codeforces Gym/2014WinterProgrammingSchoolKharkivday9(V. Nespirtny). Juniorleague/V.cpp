#include <bits/stdc++.h>

using namespace std;
// #define int long long

int32_t main(){
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();

    int ans = 0;
    // set <vector <string>> sub;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){

                string a, b, c;
                int cmd = 0;
                for(int pos = i; pos < n; pos++){
                    if(pos == j) cmd = 1;
                    if(pos == k) cmd = 2;

                    switch (cmd){
                    case 0:
                        a.push_back(s[pos]);
                        break;
                    case 1:
                        b.push_back(s[pos]);
                        break;
                    case 2:
                        c.push_back(s[pos]);
                        break;
                    }
                }
                for(int pos = 0; pos < i; pos++){
                    switch (cmd){
                    case 0:
                        a.push_back(s[pos]);
                        break;
                    case 1:
                        b.push_back(s[pos]);
                        break;
                    case 2:
                        c.push_back(s[pos]);
                        break;
                    }
                }

                if(a == "" || b == "" || c == "") continue;

                if(a + b > c && b + c > a && c + a > b){
                    // vector <string> aux = {a, b, c};
                    // sort(aux.begin(), aux.end());
                    // if(sub.find(aux) == sub.end()){
                        // sub.emplace(aux);
                        ans++;


                    // }
                }
            }

        }
    }

    cout << ans << "\n";

    return 0;
}