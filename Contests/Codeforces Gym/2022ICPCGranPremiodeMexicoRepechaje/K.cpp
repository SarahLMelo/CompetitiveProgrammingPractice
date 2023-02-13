#include <bits/stdc++.h>

using namespace std;
#define int long long
map <char, char> leg;

void init(){
    leg['a'] = '2';
    leg['b'] = '2';
    leg['c'] = '2';

    leg['d'] = '3';
    leg['e'] = '3';
    leg['f'] = '3';

    leg['g'] = '4';
    leg['h'] = '4';
    leg['i'] = '4';

    leg['j'] = '5';
    leg['k'] = '5';
    leg['l'] = '5';

    leg['m'] = '6';
    leg['n'] = '6';
    leg['o'] = '6';

    leg['p'] = '7';
    leg['q'] = '7';
    leg['r'] = '7';
    leg['s'] = '7';

    leg['t'] = '8';
    leg['u'] = '8';
    leg['v'] = '8';

    leg['w'] = '9';
    leg['x'] = '9';
    leg['y'] = '9';
    leg['z'] = '9';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    map <string, int> freq;

   init();

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++){
            s[j] = leg[s[j]];
        }

        // cout << s << "\n";
        freq[s]++;
    }
    // cout << '\n';

    for(int i = 0; i < q; i++){
        string s;
        cin >> s;

        // cout << s << ": ";

        cout << freq[s] << "\n";
    }

    return 0;
}