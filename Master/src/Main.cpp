#include <iostream>

int main(int argc, const char * argv[]) {
	int p, e, i, d;
	int count = 1;
	while (std::cin >> p >> e >> i >> d) {
		if (p == -1 && e == -1 && e == -1 && d == -1) {
			break;
		}
		p %= 23;  
        e %= 28;  
        i %= 33; 

		for (int date = d + 1;; date++) {
			if (((date - p) % 23 == 0) && ((date - e) % 28 == 0) && ((date - i) % 33 == 0)) {
				std::cout << "Case " << count++ <<
						": the next triple peak occurs in " << (date - d) << std::endl;
				break;
			}
		}		
	}	
	return 0;
}
