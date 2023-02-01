#include "practice-8-task-3.h"

void fill_struct(std::vector<numSet>* vec, int amount) {
	numSet tmpStruct;
	srand(time(NULL));
	while (amount) {
		tmpStruct.num1 = rand() % 50;
		tmpStruct.num2 = rand() % 100;
		tmpStruct.num3 = rand() % 500;
		vec->push_back(tmpStruct);
		amount--;
	}
}
void print_struct(std::vector<numSet>& vec) {
	std::cout << std::endl;
	std::for_each(vec.begin(), vec.end(), [](numSet v) {
		std::cout << v.num1 << "-" << v.num2 << "-" << v.num3 << std::endl;
		});
}
void sort_struct(std::vector<numSet>* vec, bool(*func)(numSet a, numSet b)) {
	numSet tmpStruct;
	for (int i = 0; i < vec->size(); ++i) {
		for (int j = i + 1; j < vec->size(); j++) {
			if (func(vec->at(i), vec->at(j))) {
				tmpStruct = vec->at(i);
				vec->at(i) = vec->at(j);
				vec->at(j) = tmpStruct;
			}
		}
	}
}
bool ascending(numSet a, numSet b) {
	return (a.num1 > b.num1 || (a.num1 == b.num1 && a.num2 > b.num2) ||
		(a.num1 == b.num1 && a.num2 == b.num2 && a.num3 > b.num3));
}
bool descending(numSet a, numSet b) {
	return (a.num1 < b.num1 || (a.num1 == b.num1 && a.num2 < b.num2) ||
		(a.num1 == b.num1 && a.num2 == b.num2 && a.num3 < b.num3));
}