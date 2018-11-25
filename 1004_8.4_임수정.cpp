#include <iostream>
using namespace std;
 
int sumOfWorkHour(int H[][7], int rowIndex){
	int sum = 0;
	for(int j = 0; j<7 ; j++)
		sum += H[rowIndex][j];
	
	return sum;
}
void selectionSort(int list[][2], int size){
	for(int i = 0 ; i < size ; i++){
		int min = list[i][1];
		int minIndex = i;
		for(int j = i ; j < size ; j++){
			if(list[j][1]<min){
				min = list[j][1];
				minIndex = j;
			}	
		}
		if(minIndex != i){
			list[minIndex][1] = list[i][1];
			list[i][1] = min;
			int temp = list[minIndex][0];
			list[minIndex][0] = list[i][0];
			list[i][0] = temp; 
		}		
	}
}
int main(){
	int workHour[8][7];
	cout << "          S M T W T F S" <<endl;
	for(int i = 0 ; i < 8 ; i++){
		cout << "Employee" << i << " ";
		for(int j = 0 ; j < 7 ; j++)
			cin >> workHour[i][j];	
	}
	//�� �迭 
	int sumOfHour[8] = {0,};
	for(int i = 0 ; i < 8 ; i++)
		sumOfHour[i] = sumOfWorkHour(workHour, i);
	//��Ʈ ����Ʈ�� �ε����� ���̶� �������� 
	int lastList[8][2];
	for(int i = 0 ; i < 8 ; i++ ){
		lastList[i][1] = sumOfHour[i];
		lastList[i][0] = i;
	}
	//��Ʈ ����Ʈ �迭 ���� 
	selectionSort(lastList,8);
	//��Ʈ ����Ʈ ��� 
	for(int i = 0 ; i < 8 ; i++)
		cout << "Employee" <<lastList[i][0] <<": "<< lastList[i][1] << endl ;
	
	
	return 0;
}
