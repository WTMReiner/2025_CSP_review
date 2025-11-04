#include<bits/stdc++.h>
using namespace std;

//地柜枚举+剪枝优化
const int MAXN = 25;
int n, m; // n=物品数，m=背包最大重量
int w[MAXN];//物品的重量
int v[MAXN];//物品的价值
int sum_v[MAXN];//预存后缀剩余价值. sum_v[i] = v[i] + v[i + 1] + v[i + 2] + ... + v[n];(用于最优性剪枝)
int max_val = 0; //全局最优价值

//当前处理的第i个物品，目前重量cw，已选价值cv
void DFS(int i, int cw, int cv) {
    //终止条件：遍历完所有物品，找到最大价值
    if(i >= n) {
        max_val = max(max_val, cv);
        return ;
    }

    //剪枝：
    //1. 超出包容量的条件：直接回溯
    if(cw > m) {
        return ;
    }
    //2.最优性剪枝：当前价值cv+剩余所有物品价值 <= max_val(目前最大价值), 无需继续
    if(cv + sum_v[i] >= max_val) {
        return ;
    }

    //递归实现枚举.无非就两个选择：选了i物品，或者没选。
    DFS(i+1, cw, cv);
    DFS(i+1, cw+w[i], cv + v[i]);

}

//预处理后缀剩余价值
void precompute_sum() {
    sum_v[n + 1] = 0;
    for(int i = n;i >= 0;i--) {
        sum_v[i] += v[i];
    }
}


int main() {
    cin >> n>> m;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }
    precompute_sum();
    DFS(1, 0, 0);
    cout << max_val << endl;


    return 0;
}