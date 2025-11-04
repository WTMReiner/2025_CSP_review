#include <iostream>
#include <vector>
#include <algorithm>  // 必须包含，否则sort()会导致编译/运行错误
#include <iomanip>   // 用于控制输出精度（保留2位小数）

using namespace std;

// 1. 物品结构体：用double存储重量/价值，避免整数除法精度丢失，且不引发内存问题
struct Item {
    double weight;   // 物品重量
    double value;    // 物品总价值
    double unit_val; // 单位重量价值（v_i / w_i）
};

// 2. 排序比较函数：按单位价值降序（核心贪心策略，返回值必须是bool类型的比较结果）
bool cmp(const Item& a, const Item& b) {
    // 注意：必须是「a的单位价值 > b的」，确保优先选单位价值高的
    return a.unit_val > b.unit_val; 
}

int main() {
    // 3. 读取输入：严格按「n（物品数）→ C（背包容量）」的顺序，避免颠倒
    int n;               // 物品数（1≤n≤100，题目约束，不会超范围）
    double capacity;     // 背包容量（用double适配部分选取的重量计算）
    cin >> n >> capacity; // 关键：顺序不能错！错了n会是容量值（可能很大），导致后续越界

    // 4. 初始化物品数组：vector大小严格等于n，避免越界
    vector<Item> items(n); // 直接初始化n个Item元素，每个元素默认初始化为0.0
    for (int i = 0; i < n; ++i) { // 循环范围：i从0到n-1，严格不越界
        cin >> items[i].weight >> items[i].value;
        // 计算单位价值：用double除法，避免整数除法（如5/2=2而非2.5）
        items[i].unit_val = items[i].value / items[i].weight;
    }

    // 5. 排序：调用标准库sort，传入正确的比较函数
    sort(items.begin(), items.end(), cmp); // 无越界风险（begin()到end()是合法范围）

    // 6. 贪心选取：遍历vector时用范围for，彻底规避索引越界
    double total_val = 0.0;    // 总价值（初始0，无未初始化风险）
    double remaining_cap = capacity; // 剩余容量（初始为总容量）
    for (const auto& item : items) { // 范围for：仅遍历vector内的所有元素，不会越界
        if (remaining_cap <= 1e-8) { // 浮点误差处理：剩余容量接近0视为装满
            break;
        }
        // 情况1：能装下整个物品，全取
        if (item.weight <= remaining_cap) {
            total_val += item.value;
            remaining_cap -= item.weight;
        }
        // 情况2：装不下整个物品，取部分
        else {
            total_val += (remaining_cap / item.weight) * item.value;
            remaining_cap = 0.0; // 取完后容量归零，退出循环
        }
    }

    // 7. 输出：严格按题目要求保留2位小数，避免格式错误
    cout << fixed << setprecision(2) << total_val << endl;

    return 0;
}