#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>


std::list<int> getBinary(char ch) {
	const int WORD_WIDTH = 5;
	std::list<int> returnValue;
	int value = static_cast<int>(ch);
	while (value / 2 != 0) {
		returnValue.push_front(value % 2);
		value /= 2;
	}
	returnValue.push_front(value % 2);
	while (returnValue.size() < WORD_WIDTH) {
		returnValue.push_front(0);
	}
	return returnValue;
}


int main(int argc, const char * argv[]) {
	return 0;
}