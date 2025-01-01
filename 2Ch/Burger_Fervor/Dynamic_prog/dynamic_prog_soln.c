#include <stdio.h>

#define SIZE 10000

int max(int v1, int v2) {
	return v1 > v2 ? v1 : v2;
}


void solve(int m, int n, int t) {
	int result, i, first, second;
	int dp[SIZE];

	dp[0] = 0;
	for(i = 1; i <= t; i++) {
		if(i >= m)
			first = dp[i - m];
		else
			first = -1;

		if(i >= n)
			second = dp[i - n];
		else
			second = -1;

		if(first == -1 && second == -1)
			dp[i] = -1;
		else
			dp[i] = max(first, second) + 1;
	}

	result = dp[t];
	if(result >= 0)
		printf("result: %d\n", result);
	else {
		i = t - 1;
		result = dp[i];
		while(result == -1)
			result = dp[--i];
		printf("%d %d\n", result, t - 1);
	}
}

int main(void) {
	int m, n, t;

	while(scanf("%d%d%d", &m, &n, &t) != -1) {
		printf("m: %d, n: %d, t: %d\n", m, n, t);
		solve(m, n, t);
	}
	return 0;
}

// crazy how changing the method can crazily increase the efficiency and reduce run time.
// with the recursive solution and input of 4 2 90, took about 40 seconds on my computer.
// but with this solution and that of memoization it almost instantly.
