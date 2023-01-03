t = int(input())

for k in range(0, t):
    n = int(input())
    ans = (n*(n+1)*(2*n + 1)/6) * 2022
    ans = ans + (((n-1) * n * (n+1))/3) * 2022
    # ans = ans % (10000000007)

    print(int(ans))