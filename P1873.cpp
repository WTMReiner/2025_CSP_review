#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL n, m;
vector<LL> height(1e6 + 10);
bool check(LL k) {
    LL len = 0;
    for(auto h : height) {
        if(h > k) {
            len += h - k;
        }
    }
    return len >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    LL max_h = 0;
    for(int i = 0;i < n;i++) {
        cin >> height[i];
        max_h = max(max_h, height[i]);
    }

    LL left = 0, right = max_h - 1, mid =0;
    while(left < right) {
        mid = (left + right + 1) / 2;
        if(check(mid)) { // 还可以更高
            left = mid;
        }else {
            right = mid - 1;
        }
    }
    cout << left;


    return 0;
}