#include<bits/stdc++.h>
using namespace std;

//问题描述：
//从 n 个整数中任选 k 个（k≤n），要求这 k 个数的和恰好为 sum，统计符合条件的方案数（组合问题，不考虑顺序）。
//核心约束：n≤20，k≤10，数值范围 [-1e3,1e3]（需避免和溢出）。

int n, k,target_sum;//n个数，选k个，
vector<int> nums;
int counts = 0;//符合要求的方案数

//组合枚举+可行性剪枝

// DFS递归函数
// 参数：当前索引i（从0开始，处理第i个数）、已选个数cnt、当前和current_sum
void DFS(int i, int cnt, int current_sum) {
    //剪枝1：已选数超过k，直接回溯
    if(cnt >= k) {
        return ;
    }
    //剪枝2：当和超过目标数，回溯
    if(current_sum > target_sum) {
        return ;
    }
    //终止条件：遍历完所有数
    if(i >= n){
        //如果选择的k个数的和=target_sum，方案数+1
        if(current_sum == target_sum && cnt == k){
            counts++;
        }
        return ;
    }


    // 枚举两种选择：不选第i个数 / 选第i个数
    // 1. 不选第i个数：直接处理下一个
    DFS(i+1,cnt, current_sum);
    // 2. 选第i个数：更新已选个数和当前和，处理下一个
    DFS(i + 1, cnt+1,current_sum+nums[i]);

}



int main() {
    cin >> n >> k >> target_sum;
    nums.resize(n);
    for(int i = 0;i < n;i++) {
        cin >> nums[i];
    }

    DFS(0, 0, 0);
    cout << counts << endl;


    return 0;
}