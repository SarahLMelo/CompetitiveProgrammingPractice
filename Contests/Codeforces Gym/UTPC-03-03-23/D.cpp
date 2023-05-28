#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    vector <string> pile;

    while(t--){
        string cmd;
        cin >> cmd;

        if(cmd == "put"){
            string s;
            cin >> s;

            pile.push_back(s);
        }

        else if(cmd == "get"){
            if(pile.empty()) cout << "empty\n";
            else{
                cout << pile.back() << "\n";
                pile.pop_back();
            }
        }

        else{
            auto it = find(pile.begin(), pile.end(), "snowcoat");
            if(it != pile.end()){
                cout << "winner winner chicken dinner :)\n";
                pile.erase(it);
            }
            else cout << "oopsimcold :(\n";
        }

    }

    return 0;
}