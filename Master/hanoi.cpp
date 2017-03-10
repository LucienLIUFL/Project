#include <iostream>


void solve(int n, char a, char b, char c) {
	if (n == 1) {
		std::cout << n << ":" << a << "->" << c << std::endl;
	} else {
		solve(n - 1, a, c, b);
		std::cout << n << ":" << a << "->" << c << std::endl;
		solve(n - 1, b, a, c);
	}
}

int main(int argc, const char * argv[]) {
	int n;
	char a, b, c;

	std::cin >> n >> a >> b >> c;
	solve(n, a, b, c);
	return 0;
}