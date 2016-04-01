#include <cstdio>
#include <cmath>

//typedef long long LL;
const int Maxn = (int)1e6 + 10;
long long prime[Maxn], mu[Maxn], k;
bool vis[Maxn];

void get_prime()
{
    for(int i = 2; i <= Maxn; ++i)
    {
        if(!vis[i])
        {
            prime[++prime[0]] = i;
            mu[i] = 1;
        }
        for(int j = 1; j <= prime[0] && i*prime[j] <= Maxn; ++j)
        {
            vis[i*prime[j]] = true;
            if(i % prime[j] == 0)
            {
                mu[i*prime[j]] = 0;
                break;
            }
            mu[i*prime[j]] = -mu[i];
        }
    }
    return;
}

long long getans(long long f)
{
    long long ret = 0, n = sqrt(f);
    for(int i = 2; i <= n; ++i)
    {
        ret += mu[i] * (f / (i*i));
    }
    return ret;
}

int main()
{
    get_prime();
    scanf("%lld", &k);
    long long l = k, r = 25505460948;
    while(l < r)
    {
        long long mid = (l+r) >> 1;
        if(getans(mid) >= k) r = mid;
        else l = mid+1;
    }
    printf("%lld\n", l);
}
