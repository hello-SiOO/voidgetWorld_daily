#include<iostream>
using namespace std;
const int SIZE = 3;
void sortRow(const double m[][SIZE], double result[][SIZE]){
	//����Ʈ �迭�� ���迭 ��� 
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			result[i][j] = m[i][j];
	//����Ʈ ���� 
	for(int j = 0 ; j < SIZE ; j++){
		for(int k = 0 ; k < SIZE-1 ; k++){
			double min = result[k][j];
			int minIndex = k; 
			for(int i = k+1 ; i < SIZE ; i++){
				if(result[i][j] < min){
					min = result[i][j];
					minIndex = i;
				}
			}
			if(minIndex != k){
				result[minIndex][j] = result[k][j];
				result[k][j] = min;
			}
		}	
	}
}
int main(){
	cout << "Enter a 3 by 3 matrix row by row:"<<endl;
	double matrix[SIZE][SIZE];
	//����Է¹ޱ� 
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			cin >> matrix[i][j];
	//���� �迭 ��� 
	double sortedMatrix[SIZE][SIZE];
	sortRow(matrix, sortedMatrix);
	cout << "The row-sorted array is" <<endl;
	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++)
			cout << sortedMatrix[i][j] << " ";
		cout << endl;
	}
		
		
	return 0;
}
