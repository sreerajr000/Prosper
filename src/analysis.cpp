#include "analysis.h"

//Function to get Random key
int Analysis::getRandomKey() {
	srand(time(0) + seed++);
	return rand() % SCALE;	//Return scaled random number
}
//Constructor definition
Analysis::Analysis() {
	ofstream outFile;	//output stream object
	//Creating all dat files to output analysis data and clean if data already existing
	outFile.open("../PROSPER/dat/insertion_sort_i.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/insertion_sort_r.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/insertion_sort_b.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/counting_inversions.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/quick_sort_f.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/quick_sort_l.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/quick_sort_m.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/quick_sort_r.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/merge_insertion_sort.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/quick_insertion_sort.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/variant_linear.dat", ios::out);
	outFile.close();
	outFile.open("../PROSPER/dat/linear.dat", ios::out);
	outFile.close();
}
//Generate random input to array
void Analysis::genRandomInput(vector<int>& array, size_t size, size_t scale) {
	srand(time(0) + seed++);	//Random seed->seed
	array.clear();
	for (int index = 0; index < size; index++) array.push_back(rand() % scale);
}

//Estimate time of insertion sort variations
void Analysis::estimateTimeIns() {
	ofstream outFileIns;	//output stream
	InsertionSort insertionSort;	//InsertionSort Object Instantiation
	clock_t clockStart, clockEnd;
	for (int i = 1; i <= 10; i++) {
		// Insertion Sort Iterative
		outFileIns.open("../PROSPER/dat/insertion_sort_i.dat", ios::app);
		clockStart = clock();	//Start Clock
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			insertionSort.sortIterative(array, 0, array.size() - 1);
		}
		clockEnd = clock();	//End Clock
		cout << "\nInsertion Sort Iterative Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;	//out time
		outFileIns.close();	//File Close
		// end

		// Insertion Sort Recursive
		outFileIns.open("../PROSPER/dat/insertion_sort_r.dat", ios::app);
		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			insertionSort.sortRecursive(array, 0);
		}
		clockEnd = clock();
		cout << "\nInsertion Sort Recursive Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// Insertion Sort Using Binary Search
		outFileIns.open("../PROSPER/dat/insertion_sort_b.dat", ios::app);
		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			insertionSort.sortUsingBinarySearch(array);
		}
		clockEnd = clock();
		cout << "\nInsertion Sort Using Binary Search Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// Counting Inversions
		outFileIns.open("../PROSPER/dat/counting_inversions.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			insertionSort.countInversion(array);
		}
		clockEnd = clock();
		cout << "\nCounting Inversions Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end
	}
}

void Analysis::estimateTimeQui() {
	ofstream outFileIns;
	QuickSort quickSort;
	clock_t clockStart, clockEnd;

	for (int i = 1; i <= 10; i++) {
		// QuickSort Pivot Last
		outFileIns.open("../PROSPER/dat/quick_sort_l.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			quickSort.sort(array, 0, array.size() - 1, 4);
		}
		clockEnd = clock();
		cout << "\nQuick Sort Pivot Last Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// QuickSort Pivot First
		outFileIns.open("../PROSPER/dat/quick_sort_f.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			quickSort.sort(array, 0, array.size() - 1, 1);
		}
		clockEnd = clock();
		cout << "\nQuick Sort Pivot First Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// QuickSort Pivot middle
		outFileIns.open("../PROSPER/dat/quick_sort_m.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			quickSort.sort(array, 0, array.size() - 1, 2);
		}
		clockEnd = clock();
		cout << "\nQuick Sort Pivot Middle Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// QuickSort Pivot Random
		outFileIns.open("../PROSPER/dat/quick_sort_r.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			quickSort.sort(array, 0, array.size() - 1, 3);
		}
		clockEnd = clock();
		cout << "\nQuick Sort Pivot Random Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end
	}
}

void Analysis::estimateTimeHyb() {
	ofstream outFileIns;
	MergeSort mergeSort;
	QuickSort quickSort;
	Linear linear;
	int key;
	clock_t clockStart, clockEnd;
	for (int i = 1; i <= 10; i++) {
		// Merge Insertion Sort
		outFileIns.open("../PROSPER/dat/merge_insertion_sort.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			mergeSort.mergeInsertionSort(array, 0, array.size() - 1);
		}
		clockEnd = clock();
		cout << "\nMerge Insertion Sort Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// Quick Insertion Sort
		outFileIns.open("../PROSPER/dat/quick_insertion_sort.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			quickSort.quickInSort(array, 0, array.size() - 1);
		}
		clockEnd = clock();
		cout << "\nMerge-Insertion Sort Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// Variant Linear Search
		outFileIns.open("../PROSPER/dat/variant_linear.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			key = getRandomKey();
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			linear.variantSearch(array, key);
		}
		clockEnd = clock();
		cout << "\nVariant Linear Search Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end

		// Linear Search
		outFileIns.open("../PROSPER/dat/linear.dat", ios::app);

		clockStart = clock();
		for (int testCase = 0; testCase < TEST_CASES; testCase++) {
			key = getRandomKey();
			genRandomInput(array, i * INPUT_SIZE_SCALE, SCALE);
			linear.search(array, key);
		}
		clockEnd = clock();
		cout << "\nLinear Search Running\nSize : ";
		cout << i * INPUT_SIZE_SCALE << " ";
		cout << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns << i * INPUT_SIZE_SCALE << " ";
		outFileIns << (double)(clockEnd - clockStart) / CLOCKS_PER_SEC << endl;
		outFileIns.close();
		// end
	}
}

void Analysis::plot() { system("gnuplot ../PROSPER/dat/plot_script"); }//Plot using gnuplot external program

