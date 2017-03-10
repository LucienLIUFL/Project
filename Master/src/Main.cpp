#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>

int toTen(int a, int n) {
	int returnValue = 0;
	int i;
	for (i = 0; a / 10 != 0; ++i) {
		returnValue += (a % 10) * pow(n, i); 
		a /= 10;
	}
	returnValue += (a % 10) * pow(n, i); 
	return returnValue;
}

int main(int argc, const char * argv[]) {


	int a, b, c;
	std::cin >> a >> b >> c;
	for (int i = 2; i < 17; ++i) {
		int ta = toTen(a, i);
		int tb = toTen(b, i);
		int tc = toTen(c, i);

		if (ta * tb == tc) {
			std::cout << i << std::endl;
		}
	}

	return 0;
}