#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int SIZE = 4;
int main(){
	srand(time(0));
	int list[SIZE][SIZE];
	//�迭�� 0, 1 ��� 
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			list[i][j] = rand()%2;
	//�迭 ���
	 for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++)
			cout << list[i][j] << " " ;
		cout << endl;
	}
	//1ī��Ʈ �ະ
	int maxRowIndex = 0;
	int maxRowCount = -1;
	for(int i = 0 ; i < SIZE ; i++){
		int count = 0;
		for(int j = 0 ; j < SIZE ; j++)
			if(list[i][j] == 1)
				count++;
		if(count > maxRowCount){
			maxRowCount = count;
			maxRowIndex = i;
		}
	}
	//1ī��Ʈ ����  
	int maxColumnIndex = 0;
	int maxColumnCount = -1;
	for(int j = 0 ; j < SIZE ; j++){
		int count = 0;
		for(int i = 0 ; i < SIZE ; i++)
			if(list[i][j] == 1)
				count++;
		if(count > maxColumnCount){
			maxColumnCount = count;
			maxColumnIndex = j;
		}
	}
	//���
	cout << "The largest row index: " << maxRowIndex  << endl;
	cout << "The largest column index: " <<maxColumnIndex << endl; 
	 
	
	return 0;
}
