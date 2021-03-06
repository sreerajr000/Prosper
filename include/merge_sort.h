

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <cstdlib>
#include <iostream>

class MergeSort {
 private:
	std::vector<int> array;
	;	// Change this to vector later
	size_t size;	// make it dynamic
 public:
	// MergeSort();
	void sort();
	// void display();
	void mergeSort(std::vector<int> &, int, int);
	void merge(std::vector<int> &, int, int, int);
	void mergeInsertionSort(std::vector<int> &, int, int);
};

#endif
