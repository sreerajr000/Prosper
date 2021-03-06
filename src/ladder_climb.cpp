//Program to perform the problem of Monkey climbing Ladder with  1 or 2 steps 
//Header file inclusion
#include "ladder_climb.h"

//Function to perform no of possible ways
int Ladder::countPossibleWays(int size) {
	int a = 0, b = 1;
	for (int i = 0; i <= size; i++) {
		i % 2 == 0 ? a = a + b : b = a + b;
	}
	return (size + 1) % 2 == 0 ? a : b;	//Return (n+1)th fibonacci number
}

//Print all combinations
void Ladder::printCompositions(int n, int i) {
	static vector<int> arr(100);
	if (n == 0)
		printArray(arr, i);	//Print one such combination
	else if (n > 0) {
		int k;
		for (k = 1; k <= 2; k++) {
			arr[i] = k;
			printCompositions(n - k, i + 1);// Fix and recur
		}
	}
}

//Function to print one combination
void Ladder::printArray(vector<int>& arr, int size) {
	int i;
	cout << "(" << arr[0];
	for (i = 1; i < size; i++) cout << "," << arr[i];
	cout << ")" << endl;
}

/*int main(void){
				int n;
				cout<<"n?:";
				cin>>n;
				Ladder obj;
				cout<<"Different compositions form "<<endl;
				obj.printCompositions(n,0);
				cout<<obj.countPossibleWays(n);
				return 0;
}*/
