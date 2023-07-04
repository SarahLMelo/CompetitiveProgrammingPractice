#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;

    vector <vector <int>> psum(3, vector <int> (s.size() + 1, 0));
    vector <int> qtd(3, 0);
    int ans = n + 1;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            qtd[0]++;
            psum[0][i+1]++;
        }

        if(s[i] == 'B'){
            qtd[1]++;
            psum[1][i+1]++;
        }

        if(s[i] == 'C'){
            qtd[2]++;
            psum[2][i+1]++;
        }

        psum[0][i+1] += psum[0][i];
        psum[1][i+1] += psum[1][i];
        psum[2][i+1] += psum[2][i];
    }

    for(int i = 0; i < 3; i++) qtd[i]>>=1;

    string perm = "ABC";
    for(int init = 0; init < n; init++){
        do{
            int aux = 0;
            for(int i = 0, pos = 0; i < 3; i++){
                int letter = perm[i] - 'A';
                aux += qtd[letter] - (psum[letter][pos + init + qtd[letter]] - psum[letter][pos + init]);
                pos += qtd[letter];
            }

            ans = min(ans, aux);
        }
        while (next_permutation(perm.begin(), perm.end()));
    }

    cout << ans << "\n";

    return 0;
}