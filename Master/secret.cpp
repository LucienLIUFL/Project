#include <iostream>
#include <string>
#include <algorithm>



int main(int argc, const char * argv[]) {

	char origin[] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z'
	};
	char secret[] = {
		'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 
		'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P',
		'Q', 'R', 'S', 'T', 'U'
	};

	std::string recv;
	while (std::cin >> recv) {
		if (recv == "START") {
			continue;
		} else if (recv == "END") {
			std::cout << std::endl;
			continue;
		} else if (recv == "ENDOFINPUT") {
			break;
		}

		for (std::string::iterator i = recv.begin(); i != recv.end(); ++i) {
			char * temp = std::find(origin, origin + 26, *i);
			int index = std::distance(origin, temp);
			std::cout.put(secret[index]);
		}
		std::cout << " " <<std::ends;
	}

	return 0;
}