#include <iostream>
using namespace std;
int up(int n,int a,int b) {
	if (n == 1) {
		return a;
	}
	if (n == 2) {
		return b;
	}
	return up(n - 1, a,b) + up(n - 2, a,b);
}
int down(int n, int a,int b) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return b;
	}
	return up(n - 1, a,b);
}
int now(int n, int a,int b) {
	if (n == 1 || n == 2) {
		return a;
	}
	return now(n - 1, a,b) + up(n, a,b) - down(n, a,b);
}
int main()
{
	int a, n, m, x,b;
	cin >> a >> n >> m >> x;
	for (b = 0; b < 100000; b++) {
		if (now(n - 1, a, b) == m) {
			break;
		}
	}
	cout << now(x, a, b);
} 