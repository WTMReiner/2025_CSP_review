#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL l, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> n >> k;
    vector<LL> sign(n + 5);
    for(int i = 0;i < n;i++) {
        cin >> sign[i];
    }


    LL left = 1, right = l, mid = 0, ans = 0;
    while(left <= right) {
        //向下取整
        mid = (left + right) / 2;
        LL cnt = 0;//已经插的路标数
        LL last = sign[0];

        for(int i = 1;i < n;i++) {
            cnt += (sign[i] - sign[i - 1] - 1) / mid;
        }

        if(cnt > k) {
            left = mid + 1;
        }else {
            ans = mid;
            right = mid - 1;
        }


    }
    cout << ans;


    return 0;
}