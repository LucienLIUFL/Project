#include <iostream>

int main(int argc, const char * argv[]) {
	int p, e, i, d;
	int count = 0;
	while (std::cin >> p >> e >> i >> d) {
		if (p == -1 && e == -1 && e == -1 && d == -1) {
			break;
		}

		for (int date = 0;; date++) {
			if (((date - p) % 23 == 0) && ((date - e) % 28 == 0 ) && ((date - i) % 33 == 0)) {
				if (date <= d) {
					continue;
				}
				std::cout << "Case " << ++count << 
					": the next triple peak occurs in " << (date - d) << " days." << std::endl;	
				break;  
			}
		}
	}	
	return 0;
}
