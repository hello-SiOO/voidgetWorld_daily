#include<iostream>
using namespace std;
const int SIZE = 3;
bool isMarkovMatrix(const double m[][SIZE]){
	for(int j = 0 ; j < SIZE ; j++){
		double sum = 0 ;
		for(int i = 0 ; i < SIZE ; i++){
			sum += m[i][j];
		}
		if(sum != 1)
			return false;
	}
	return true;
}
int main(){
	cout << "Enter a 3 by 3 matrix row by row:"<<endl;
	double matrix[SIZE][SIZE];
	//행렬입력받기 
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			cin >> matrix[i][j];
	//출력
	if(isMarkovMatrix(matrix))
		cout << "It is a Markov Matrix" <<endl;
	else
		cout << "It is not Markov Matrix" <<endl; 
	
	return 0;
}
