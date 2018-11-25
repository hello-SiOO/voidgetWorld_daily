#include<iostream>
using namespace std;
const int SIZE = 9 ;
bool ischeck(int list[][SIZE]){
	//1~9���� üũ�� ��Ÿ�� �迭 ����� 
	bool isCheck[9];
	//row �˻�
	for(int i = 0 ; i < SIZE ; i++){
		//��Ÿ�� �迭 false�� �ʱ�ȭ 
		for(int a = 0 ; a < SIZE ; a++)
			isCheck[a] = false;
		for(int j = 0 ; j < SIZE ; j++)
			isCheck[list[i][j]-1] = true;
		//isCheck �� Ʈ������ üũ 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
	}
	//column�˻� 
	for(int j = 0 ; j < SIZE ; j++){
		//
		for(int a = 0 ; a < SIZE ; a++)
			isCheck[a] = false;
		for(int i = 0 ; i < SIZE ; i++)
			isCheck[list[i][j]-1] = true;
		//isCheck �� Ʈ������ üũ 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
	}	
	//�簢�� �˻�
	for(int i = 0 ; i < SIZE ; i=i+3){
		for(int j = 0 ; j < SIZE ; j=j+3){
			//�˻� ���� 
			for(int a = 0 ; a < SIZE ; a++)
				isCheck[a] = false;
			for(int l = i ; l < i+3 ; l++){
				for(int k = j; k < j+3 ; k++){
					isCheck[list[l][k]-1] = true;
				}
			} 
			//isCheck �� Ʈ������ üũ 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
		}
	}	
	return true;
}
int main(){
	//�������� �Է¹ޱ�
	int list[SIZE][SIZE];
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			cin >> list[i][j];
	if(ischeck(list))
		cout << "valid solution!" << endl; 
	else 
		cout << "invalid solution!" << endl;
	return 0;
}

