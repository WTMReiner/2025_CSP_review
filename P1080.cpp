#include<bits/stdc++.h>
using namespace std;

// 高精乘：大整数*整数
vector<int> multiply(const vector<int>& a, int b) {
    vector<int> c;
    int carry = 0;
    for(int i = 0;i < a.size() || carry;i++) {
        if(i < a.size()) carry += a[i] * b;
        c.push_back(carry % 10);
        carry = carry / 10;
    }
    return c;
}

// 高精度除: 大整数 / 整数
vector<int> divide(const vector<int>& a, int b) {
    vector<int> c;
    int remainder = 0;
    for(int i = a.size() - 1;i >= 0;i--) {
        remainder = remainder*10 + a[i];
        c.push_back(remainder / b);
        remainder %= b;
    }
    reverse(c.begin(), c.end());

    //去除前导0
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

// 比较两个大整数的大小
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

struct Minister {
    int left, right;
    // 按照左右手乘积排序
    bool operator<(const Minister& other) const {
        return left * right < other.left * other.right;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<Minister> ministers(n);
    int kingLeft, kingRight;
    cin >> kingLeft >> kingRight;
    
    for (int i = 0; i < n; i++) {
        cin >> ministers[i].left >> ministers[i].right;
    }
    
    // 按左右手乘积从小到大排序
    sort(ministers.begin(), ministers.end());
    
    // 当前左手乘积（高精度存储）
    vector<int> product(1, 1);
    product = multiply(product, kingLeft);
    
    // 记录最大金币数
    vector<int> maxCoins(1, 0);
    
    // 遍历每个大臣
    for (int i = 0; i < n; i++) {
        // 计算当前大臣获得的金币数
        vector<int> coins = divide(product, ministers[i].right);
        
        // 更新最大金币数
        if (compare(coins, maxCoins)) {
            maxCoins = coins;
        }
        
        // 更新左手乘积
        product = multiply(product, ministers[i].left);
    }
    
    // 输出结果（从高位到低位）
    for (int i = maxCoins.size() - 1; i >= 0; i--) {
        cout << maxCoins[i];
    }
    cout << endl;

    return 0;
}