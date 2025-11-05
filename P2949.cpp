#include <bits/stdc++.h>
using namespace std;

#define ll long long
// 初始化最小堆(优先队列)
priority_queue<ll, vector<ll>, greater<ll>> pq;

ll n;
struct jobs{
    ll d, p;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;


    vector<jobs> job(n);
    for(int i = 0;i < n;i++) {
        cin >> job[i].d >> job[i].p;
    }
    sort(job.begin(), job.end(), [](const jobs& a, const jobs& b){
        if(a.d == b.d) {
            return a.p > b.p;
        }else {
            return a.d < b.d;
        }
    });

    for(int i = 0;i < n;i++) {
        ll t = job[i].d;
        pq.push(job[i].p);
        if(pq.size() > t) {
            pq.pop();
        }
    }

    ll ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}