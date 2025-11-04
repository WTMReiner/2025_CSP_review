#include<bits/stdc++.h>
using namespace std;

// 问题描述
// 在 8×8 的棋盘上放置 8 个皇后，使她们彼此不能攻击（即任意两个皇后不在同一行、同一列、同一对角线），统计所有合法的摆放方案数。
const int N = 8;
int counts = 0;

//标记数组(剪枝核心)
vector<int> cols(N, false);//标记列是否能被占用(cols[y] = true表示y列有皇后)
vector<int> diag1(2*N - 1, false);//标记对角线1(x - y = 常数)是否能被占用(索引 = x - y + 7,避免负数)
vector<int> diag2(2*N - 1, false);//标记对角线2(x+y = 常数)是否能被占用(索引 = x + y)

// DFS递归函数
// 参数：当前行x（从0开始，每行放1个皇后）
void DFS(int x) {
    //终止条件：已放完8行（0~7行），方案数+1
    if(x == N) {
        counts++;
        return ;
    }

    //枚举当前行的每一列(0~7列)
    for(int y = 0;y< 8;y++) {
        //剪枝：检查行列，对角线有没有被占用
        if(cols[y] || diag1[x - y + 7] || diag2[x+y]) {
            continue;//冲突，直接跳过
        }

        //放置皇后，标记占用
        cols[y] = true;
        diag1[x - y + 7] = true;
        diag2[x+y] = true;

        //递归处理下一行
        DFS(x+1);

        //回溯：还原现场(撤销标记)
        cols[y] = false;
        diag1[x - y + 7] = false;
        diag2[x+y] = false;
    }

}



int main() {
    DFS(0);
    cout << counts << endl;



    return 0;
}