# Practice for CSP2025

## 4. 贪心以及二分算法
一、贪心算法
贪心算法的核心是 **“局部最优→全局最优”**：每一步都选择当前 “最优” 的操作，且不回溯。但贪心并非万能，必须通过严格证明（如贪心领先、交换论证）确保局部最优能推导全局最优，否则可能得到次优解。

- 核心定义
  - 本质：模拟 “短视的贪婪决策”，每步按某一贪心指标（如单位价值、结束时间）选择最优解，不考虑未来影响。
  - 适用场景：问题需满足 “贪心选择性质”（局部最优能导出全局最优）和 “最优子结构”（全局最优包含子问题最优）。

### 题目列表
1. [P2240 【深基12.例1】部分背包问题](https://www.luogu.com.cn/problem/P2240)
2. [P1094 [NOIP 2007 普及组] 纪念品分组](https://www.luogu.com.cn/problem/P1094)
3. [P2949 [USACO09OPEN] Work Scheduling G](https://www.luogu.com.cn/problem/P2949)
4. [P2678 [NOIP 2015 提高组] 跳石头](https://www.luogu.com.cn/problem/P2678)
5. [P3853 [TJOI2007] 路标设置](https://www.luogu.com.cn/problem/P3853)
6. [P1873 [COCI 2011/2012 #5] EKO / 砍树](https://www.luogu.com.cn/problem/P1873)
7. [P2440 木材加工](https://www.luogu.com.cn/problem/P2440)
8. [P1080 [NOIP 2012 提高组] 国王游戏](https://www.luogu.com.cn/problem/P1080)