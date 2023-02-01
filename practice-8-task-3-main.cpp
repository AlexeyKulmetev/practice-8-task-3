#include "practice-8-task-3.h"

int main() {
	int amount;
	std::vector<numSet> structVec;
	std::cout << "Enter number of elements: ";
	std::cin >> amount;
	std::cin.get();
	fill_struct(&structVec, amount);
	
	std::cout << "Let`s measure the execution time!";
	std::cout << std::endl << "Custom sorting function (press any key to start):";
	std::cin.get();

	auto begin = std::chrono::steady_clock::now();
	sort_struct(&structVec, ascending);
	auto end = std::chrono::steady_clock::now();
	auto spent_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Execution time of the user`s ascending sorting function: "
		<< spent_time.count() << "ms";

	fill_struct(&structVec, amount);
	begin = std::chrono::steady_clock::now();
	sort_struct(&structVec, descending);
	end = std::chrono::steady_clock::now();
	spent_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Execution time of the user`s descending sorting function: "
		<< spent_time.count() << "ms";

	std::cout << std::endl << "Sorting function from the STL library (press any key to start): ";
	std::cin.get();

	fill_struct(&structVec, amount);
	begin = std::chrono::steady_clock::now();
	std::sort(structVec.begin(), structVec.end(), ascending); 
	end = std::chrono::steady_clock::now();
	spent_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Execution time of the STL library ascending function: "
		<< spent_time.count() << "ms";

	fill_struct(&structVec, amount);
	begin = std::chrono::steady_clock::now();
	std::sort(structVec.begin(), structVec.end(), descending);
	end = std::chrono::steady_clock::now();
	spent_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Execution time of the STL library descending function: "
		<< spent_time.count() << "ms";

	return 0;
}