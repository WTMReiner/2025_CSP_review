//长度54行，时间15ms
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=10010,MAXM=200010;//注意双向边，边要开2倍
int n,m,tot=0,sum[3],ans=0;
int h[MAXN],used[MAXN];//h[i]记录点i在邻接表中指向的第一条边
struct Edge{//边的结构体
	int v;
	int next;//next记录这条边在邻接表中指向同端点的另一条边
}e[MAXM];
void addEdge(int u,int v){//建边
	tot++;//边的代号
	e[tot].v=v;
	e[tot].next=h[u];h[u]=tot;
}
queue<int> q;
bool bfs(int start){//广搜，不存在返回真
	used[start]=1;//染为1
	sum[1]=1,sum[2]=0;//初始化
	q.push(start);//进队列
	while(!q.empty()){//队列非空
		int u=q.front();q.pop();//u为原端点
		for(int k=h[u];k;k=e[k].next){//邻接表
			int v=e[k].v;//v为指向端点
			if(used[v]==used[u]) return 1;//同色，直接返回
			if(used[v]==0){//没染过色
				used[v]=used[u]%2+1;//染相反颜色
				sum[used[v]]++;//记录
				q.push(v);//进队列
			}
		}
	}
	return 0;//满足
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int uu,vv;
		scanf("%d%d",&uu,&vv);
		addEdge(uu,vv);//建边，双向
		addEdge(vv,uu);
	}
	for(int i=1;i<=n;i++){
		if(used[i]) continue;//遍历过就不再遍历
		if(bfs(i)){//不满足
			printf("Impossible");
			return 0;//直接返回
		}
		else ans+=min(sum[1],sum[2]);//加和
	}
	printf("%d",ans);
	return 0;//华丽结束
}
