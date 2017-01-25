//http://lx.lanqiao.cn/problem.page?gpid=T11

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return b < a;
}

int main()
{
	int n;
	vector<int> vec;
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &vec[i]);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		vector<int> cp(vec);
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		sort(cp.begin() + l - 1, cp.begin() + r, cmp);
		printf("%d\n", cp[l + k - 2]);
	}
	return 0;
}
