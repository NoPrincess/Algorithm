#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;

struct point
{
	point(int x, int y) : x(x), y(y) {}
	point() {}
	int x, y;
};

struct op
{
	point idx;
	char c;
};

int m, n, num = 0;
char mp[510][510];
bool vis[510][510];
op pre[510][510];
int dir[4][2] = { 1, 0, 0, -1, 0, 1, -1, 0 };
queue<point> que;
stack<op> stk;

bool illige(int x, int y)
{
	if (x < m && y < n)
	{
		return mp[x][y] == '0';
	}
	return false;
}

char getOp(int x, int y)
{
	if (x == 0 && y == 1)
		return 'R';
	else if (x == 0 && y == -1)
		return 'L';
	else if (x == 1 && y == 0)
		return 'D';
	return 'U';
}

void bfs()
{
	memset(vis, false, sizeof(vis));
	memset(pre, 0, sizeof(pre));
	num = 0;
	point p(0, 0);
	que.push(p);
	vis[0][0] = true;
	while (!que.empty())
	{
		int tx = que.front().x;
		int ty = que.front().y;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int mx = tx + dir[i][0];
			int my = ty + dir[i][1];
			if (vis[mx][my] == false && illige(mx, my))
			{
				point _p1(mx, my);
				point _p2(tx, ty);
				que.push(_p1);
				pre[mx][my].idx = _p2;
				pre[mx][my].c = getOp(dir[i][0], dir[i][1]);
				vis[mx][my] = true;
				if (mx == m && my == n)
				{
					return;
				}
			}
		}
	}
}

void write(int x, int y)
{
	if (x == 0 && y == 0)
		return;
	++num;
	op o = pre[x][y];
	stk.push(o);
	write(o.idx.x, o.idx.y);
}

int main()
{
	while (~scanf("%d%d", &m, &n))
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf(" %c", &mp[i][j]);
			}
		}
		bfs();
		write(m - 1, n - 1);

		printf("%d\n", num);
		while (!stk.empty())
		{
			printf("%c", stk.top().c);
			stk.pop();
		}
		printf("\n");
	}
	return 0;
}
