#include<iostream>
using namespace std;

const int SIZE = 4;
double sumMajorDiagonal(const double m[][SIZE]){
	double sum = 0; 
	for(int i = 0 ; i < SIZE ; i++)
		sum += m[i][i];
	
	return sum;
}
int main(){
	cout << "Enter a 4-by-4 matrix row by row:" ;
	double list[SIZE][SIZE] = {0,};
	for (int i = 0 ; i < SIZE ; i++)
		for (int j = 0 ; j < SIZE ; j++)
			cin >> list[i][j]; 
			
	cout << "Sum of the elements in the major diagonal is " << sumMajorDiagonal(list) << endl;
	
	
	return 0;
}
