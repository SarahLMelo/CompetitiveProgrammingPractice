#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    while(cin >> x){
        vector <int> pos, neg;

        while(x != -999999){
            if(x > 0) pos.push_back(x);
            else if(x < 0) neg.push_back(x);

            cin >> x;
        }
    }

    return 0;
}