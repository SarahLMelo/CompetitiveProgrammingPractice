#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string aux = "";
    while(!s.empty() && s.front() == s.back()){
        aux += s.back();
        s.pop_back();
    }

    if(s.empty()){
        cout << "-1\n";
        return 0;
    }

    s = aux + s;
    int msz = 0, idx = -1;
    vector <int> freq(26, 0);
    for(int i = 0, j = 0; j < n; j++){
        freq[s[j] - 'a']++;

    }

    return 0;
}

// aabbaa