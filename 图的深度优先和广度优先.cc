//http://cqust.openjudge.cn/20161012/024/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
#include <algorithm>

using namespace std;

int m, n, start = 0;
map<int, vector<int> > mp;
vector<bool> vis;
queue<int> que;
stack<int> stk;
int max_;

bool allvis(int type)
{
	for (int i = 0; i < m + 1; ++i)
	{
		if (vis[i] == false)
		{
			vis[i] = true;
			printf("v%d ", i);
			type == 0 ? stk.push(i) : que.push(i);
			return false;
		}
	}
	return true;
}

void bfs()
{
	for (int i = 0; i < m + 1; ++i) vis[i] = false;
	vis[0] = true;
	vis[start] = true;
	vis[m] = true;
	que.push(start);
	printf("v%d ", start);
	while (!que.empty() || allvis(1) == false)
	{
		int t = que.front();
		que.pop();
		sort(mp[t].begin(), mp[t].end());
		for (int i = mp[t].size() - 1; i >= 0; --i)
		{
			if (!vis[mp[t][i]])
			{
				vis[mp[t][i]] = true;
				que.push(mp[t][i]);
				printf("v%d ", mp[t][i]);
			}
		}
	}
	printf("v%d\n", max_);
}

void dfs()
{
	for (int i = 0; i < m + 1; ++i) vis[i] = false;
	vis[0] = true;
	vis[start] = true;
	vis[m] = true;
	stk.push(start);
	printf("v%d ", start);
	while (!stk.empty() || allvis(0) == false)
	{
		bool f = false;
		int t = stk.top();
		sort(mp[t].begin(), mp[t].end());
		for (int i = mp[t].size() - 1; i >= 0; --i)
		{
			if (!vis[mp[t][i]])
			{
				f = true;
				vis[mp[t][i]] = true;
				stk.push(mp[t][i]);
				printf("v%d ", mp[t][i]);
				break;
			}
		}
		if (!f) stk.pop();
	}
	printf("v%d\n", max_);
}

int main()
{
	scanf("%d%d", &m, &n);
	scanf(" v%d", &start);
	for (int i = 0; i < m - 1; ++i)
	{
		scanf(" v%d", &max_);
	}
	vis.resize(m + 1);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf(" v%d v%d", &a, &b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs();
	bfs();
	return 0;
}
