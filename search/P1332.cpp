#include<bits/stdc++.h>
using namespace std;


const int MAXN = 505;
int n, m, a, b;
int dis[MAXN][MAXN];
int grid[MAXN][MAXN] = {0};
vector<pair<int, int> > site;
vector<pair<int, int> > source;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


void BFS() {
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int> > q;

    //让每个感染源入队
    for(int i = 0;i < a;i++) {
        auto [x, y] = source[i];
        dis[x][y] = 0;
        q.emplace(x, y);
    }
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0;i < 4;i++) {
            int nx = x+dx[i];
            int ny = y + dy[i];

            if(nx <= n && nx >= 1 && ny >= 1 && ny <= n) {
                if(dis[nx][ny] == -1) {
                    q.emplace(nx, ny);
                    dis[nx][ny] = dis[x][y] + 1;
                }else if(dis[nx][ny] == 0) {
                    continue;
                }else {
                    if(dis[x][y] + 1 < dis[nx][ny]) {
                        dis[nx][ny] = dis[x][y] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }
            

        }

    }


}



int main() {
    cin >> n >> m >> a >> b;
    for(int i = 0;i < a;i++) {
        int x, y;
        cin >> x >> y;
        source.push_back({x, y});
    }
    for(int i = 0;i < b;i++) {
        int x, y;
        cin >> x >> y;
        site.push_back({x, y});
        grid[x][y] = 1;
    }

    BFS();

    for(int i = 0;i < b;i++) {
        auto [x, y] = site[i];
        cout << dis[x][y] << endl;
    }

    return 0;
}