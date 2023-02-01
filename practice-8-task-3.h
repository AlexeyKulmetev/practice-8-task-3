#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

struct numSet {
	int num1;
	int num2;
	int num3;
};

void fill_struct(std::vector<numSet>* vec, int amount);
void print_struct(std::vector<numSet>& vec);
void sort_struct(std::vector<numSet>* vec, bool(*func)(numSet a, numSet b));
bool ascending(numSet a, numSet b);
bool descending(numSet a, numSet b);