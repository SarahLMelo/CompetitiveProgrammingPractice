#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <string> two, four, six, eight;

    two = {
        "00",
        "01",
        "81",
    };

    four = {
        "0000",
        "0001",
        "2025",
        "3025",
        "9801"
    };

    six = {
        "000000",
        "000001",
        "088209",
        "494209",
        "998001"
    };

    eight = {
        "00000000",
        "00000001",
        "04941729",
        "07441984",
        "24502500",
        "25502500",
        "52881984",
        "60481729",
        "99980001"
    };

    int x;
    while(cin >> x){

        switch (x)
        {
        case 2:
            for(auto i:two)
                cout << i << "\n";
            break;
        
        case 4:
            for(auto i:four)
                cout << i << "\n";
            break;

        case 6:
            for(auto i:six)
                cout << i << "\n";
            break;
        
        case 8:
            for(auto i:eight)
                cout << i << "\n";
            break;
        }
        // cout << endl;
    }


    return 0;
}