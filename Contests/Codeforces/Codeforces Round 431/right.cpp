#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int main()
{
    for(int t = 1; t <= 100000; t++){
        int k = t;
        cout << k << ":\n";
        for (int i = 0; i < 26; i++)
        {
            int cnt = 1;
            while ((cnt + 1) * cnt / 2 <= k) cnt++;
            k -= cnt * (cnt - 1) / 2;
            for (int j = 0; j < cnt; j++) printf("%c", 'a' + i);
        }
            cout << "\n";
    }
    return 0;
}