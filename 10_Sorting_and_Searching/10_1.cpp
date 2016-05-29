#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::cout;
using std::copy;

template<typename T>
void mergeSortedSequence(vector<T> & A,vector<T> & B, int lastA, int lastB){
	int indexMerged = A.size() -1;
	while(lastA >= 0 && lastB >=0){
		if(A[lastA] > B[lastB]){
			std::swap(A[lastA], A[indexMerged]);
			--lastA;		
		}
		else{
			std::swap(B[lastB], A[indexMerged]);
			--lastB;
		}
		--indexMerged;
	}
	while(lastB >= 0){
		A[indexMerged] = B[lastB];
		--lastB;--indexMerged;
	}
}

int main(){
	vector<int> A = {3,4,5,6,0,0,0,0};
	vector<int> B = {1,2,3,4};
	mergeSortedSequence(A, B, 3,3);
	copy(begin(A), end(A), std::ostream_iterator<int>(cout, ", "));
	return 0;	
}
