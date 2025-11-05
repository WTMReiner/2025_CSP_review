#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL l, n, m;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> l >> n >> m;
    vector<LL> d(n + 5);
    for(int i = 1;i <= n;i++ ) {
        cin >> d[i];
    }
    d[0] = 0;
    d[n + 1] = l;

    LL left = 0, right = l, mid = 0;
    while(left < right) {
        // 向上取整计算mid，避免死循环。
        mid = (left + right + 1) / 2;
        LL last_p = d[0];
        LL cnt = 0;//剩余可以搬走的石头数

        for(int i = 1;i <= n + 1;i++) {
            if(d[i] - last_p < mid) {
                cnt++;
            }else {
                last_p = d[i];
            }
        }

        // 判断当前mid是否可行
        if(cnt > m) {//不可行，需要减小
            right = mid - 1;
        }else {
            left = mid;
        }

    }
    cout << left;

    return 0;
}