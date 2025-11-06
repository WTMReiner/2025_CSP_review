#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL n, k;
vector<LL> len(1e5 + 10);

bool check(LL mid)
{
    LL sum = 0;
    for(int i = 0;i < n;i++) {
        sum += (len[i] / mid);
    }
    return sum >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    LL max_l = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> len[i];
        max_sum += len[i];
        max_l = max(max_l, len[i]);
    }

    if(max_sum < k) {
        cout << 0;
        return 0;
    }
    LL left = 1, right = max_l, mid = 0;
    while (left < right)
    {
        mid = (left + right + 1) / 2;
        if(check(mid)) {
            left = mid;
        }else {
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}