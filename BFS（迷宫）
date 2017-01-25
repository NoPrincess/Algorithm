#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <memory.h>
using namespace std;

int m, n, tx, ty;
int mp[100][100];
queue<int> que;
int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
bool vis[100][100];
int pre[10000];
stack<int> stk;

void write(int s)
{
	if (pre[s] == 0)
		return;
	int mx = s / m;
	int my = s % m;
	stk.push(pre[s]);
	write(pre[s]);
}

bool illige(int x, int y)
{
	return (x < m && y < n) && mp[x][y] == 1;
}

void bfs(int x, int y)
{
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	vis[x][y] = 1;
	que.push(x * m + y);
	while (!que.empty())
	{
		int mx = que.front() / m;
		int my = que.front() % m;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = mx + dir[i][0];
			int ny = my + dir[i][1];
			if (vis[nx][ny] == false && illige(nx, ny))
			{
				que.push(nx * m + ny);
				pre[nx * m + ny] = mx * m + my;
				vis[nx][ny] = true;
				if (nx == tx && ny == ty)
				{
					return;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &m, &n, &tx, &ty);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &mp[i][j]);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d", mp[i][j]);
		}
		cout << endl;
	}

	bfs(0, 0);

	write(tx * m + ty);
	int q = 0;
	while (!stk.empty())
	{
		++q;
		cout << '(' << stk.top() / m << ',' << stk.top() % m << ")\n";
		stk.pop();
	}
	cout << q << endl;
	return 0;
}

/*
6 5 5 4
1 1 0 1 1
1 0 1 1 1
1 0 1 0 0
1 0 1 1 1
1 1 0 0 1
1 1 1 1 1
*/
