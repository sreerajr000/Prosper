#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "variant_linear.h"

#define SCALE 1000
#define TEST_CASES 100
#define INPUT_SIZE_SCALE 100

using namespace std;

class Analysis {
 private:
	std::vector<int> array;
	int seed;

 public:
	void genRandomInput(std::vector<int>&, size_t, size_t);
	int getRandomKey();
	void estimateTimeIns();
	void estimateTimeQui();
	void estimateTimeHyb();
	void plot();
	Analysis();
};

#endif
