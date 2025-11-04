#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int r, c;
int n;
vector<int> dir;
char m[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[] = {0, 1, 0, -1};//东 南 西 北
int dy[] = {1, 0, -1, 0};

void BFS(int sx, int sy) {
    queue<tuple<int,int, int> > q;
    memset(dis, 0, sizeof(dis));

    q.emplace(sx, sy, dir[0]);
    while(!q.empty()) {
        auto [x, y, f] = q.front();
        q.pop();
        //方向就是dir[dis[x][y]]  = f
        int nx = x + dx[f];
        int ny = y + dy[f];
        //如果这个点没有被阻碍
        while(nx >= 0 && nx < c && ny >= 0 && ny < r && m[nx][ny] != 'X') {
            dis[nx][ny] = dis[x][y] + 1;
            if(dis[nx][ny] == n) {
                m[nx][ny] = '*';
            }else {
                q.emplace(nx, ny, dir[dis[nx][ny]]);
            }
            nx += dx[f];
            ny += dy[f];
        }
    }
    return ;
}


int main() {
    cin >> r >> c;
    int sx = 0,sy = 0;
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            cin >> m[i][j];
            //标记起点
            if(m[i][j] == '*') {
                sx = i;
                sy = j; 
                m[i][j] = '.';
            }
        }
    }
    cin >> n;
    for(int i = 0;i < n;i++) {
        string f;
        cin >> f;
        if(f == "NORTH") {
            dir.push_back(3);
        }else if(f == "SOUTH") {
            dir.push_back(1);
        }else if(f == "WEST") {
            dir.push_back(2);
        }else if(f == "EAST"){
            dir.push_back(0);
        }
    }
    BFS(sx, sy);
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
    // cout << " dis = " << endl;
    // for(int i = 0;i < r;i++) {
    //     for(int j = 0;j < c;j++) {
    //         cout << dis[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "dir = " << endl;
    // for(int i = 0;i < n;i++) {
    //     cout << dir[i] << " ";
    // }
    // cout << endl;

    return 0;
}