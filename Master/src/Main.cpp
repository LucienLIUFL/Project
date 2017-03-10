#include <iostream>
#include <vector>
#include <list>


void getMaxScore(int n, int k, const std::vector<int> & ai, const std::vector<int> & bi) {
	std::list<int> results;

	for (int i = 0; i < n; ++i) {
		
	}

}


int main(int argc, const char * argv[]) {
	int n, k, temp;
	std::vector<int> & ai;
	std::vector<int> & bi;

	std::cin >> n >> k;

	if ((n != 0) && (k != 0)) {
		for (int i = 0; i < n; ++i) {
			std::cin >> temp;
			ai.push_back(temp);
		}
		for (int i = 0; i < n; ++i) {
			std::cin >> temp;
			bi.push_back(temp);
		}

		getMaxScore(n, k, ai, bi);
	}

	


	return 0;
}