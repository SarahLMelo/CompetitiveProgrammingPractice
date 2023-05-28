#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;

    cin >> n >> k >> s;
    vector <pair <char, int>> v;
    vector <int> freq(26, 0);

    s = s + s;

    int st = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != s[i-1]){
            v.emplace_back(s[i-1], i - st);
            st = i;
        }
    }

    v.emplace_back(s[s.size()-1], s.size() - st);

    if(v.size() > 1 && v.back().first == v.front().first){
        v.front().second += v.back().second;
        v.pop_back();
    }

    int msz = 0, idx = -1, sz = 0;
    for(int i = 0, j = 0; j < v.size(); j++){
        freq[v[j].first - 'a'] += v[j].second;
        
        if(freq[v[j].first - 'a'] > k){
            while(freq[v[j].first - 'a'] > k){
                freq[v[i].first - 'a'] -= v[i].second;
                sz -= v[i].second;
                i++;
            }
        }

        sz += v[j].second;
        if(sz > msz){
            msz = sz;
            idx = i;
        }
    }

    string ans = "";
    msz = min(n, msz);
    if(msz != 0){
        sz = 0;
        while(sz < msz){
            for(int i = 0; i < v[idx].second; i++){
                ans.push_back(v[idx].first);
            }
            sz += v[idx].second;
            idx++;
        }
    }

    if(idx != -1 && v.size() > 1) cout << msz << "\n" << ans << "\n";
    else cout << "-1\n";

    return 0;
}

/*
10 3
abcaabcabcabcaabcabc

9
bcabcaabc

abbaa
aaabbaaabb
*/