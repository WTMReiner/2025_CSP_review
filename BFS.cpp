#include <bits/stdc++.h>
using namespace std;

// 队列存储状态+层次遍历+状态标记，确保每个状态只访问1次

const int MAXN = 1000;
int n, m;             // 行数、列数
int grid[MAXN][MAXN]; // 网格,0 = 空地，1 = 障碍物
int dis[MAXN][MAXN];  // 记录到每个点的最短距离

// 4个方向的移动
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int BFS(int sx, int sy, int ex, int ey) {
    //1.初始化，将dis数组设置为-1，表示未访问。
    memset(dis, -1, sizeof(dis));
    //设置队列q的初始状态
    queue<pair<int, int> > q;
    //将起点的dis设置为0，同时将起点入队，表示从此出发。
    dis[sx][sy] = 0;
    q.emplace(sx, sy);
    //当队列不为空，将当前对列头部的点(x0, y0)的4周还未访问过的点(x, y)入队，并设置dis[x][y] = dis[x0][y0]+1,同时点(x0, y0)出队
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        //如果是终点，停止循环
        if(x == ex && y == ey) {
            return dis[x][y];
        }

        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //如果点符合要求
            if(dis[nx][ny] != -1 && nx >= 1 && nx <= m && 
                ny >= 1 && ny <= n && grid[nx][ny] == 0) {
                dis[nx][ny] = dis[x][y] +1;
                q.emplace(nx, ny);
            }
        }
        
    }

    //如果跳出循环了，说明起点不能到达终点，返回0
    return 0;
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    // 起点(1,1)，终点(n,m)，输出最短步数
    cout << BFS(1, 1, n, m) << endl;
    return 0;

    return 0;
}