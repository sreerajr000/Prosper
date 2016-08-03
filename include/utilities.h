
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>

class Utilities {
 private:
	std::vector<int> array;
	int size;

 public:
	static int binarySearch(std::vector<int> &, int, int, int);
	static void swap(int *, int *);
};

#endif
