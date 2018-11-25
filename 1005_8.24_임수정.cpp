#include<iostream>
using namespace std;
const int SIZE = 9 ;
bool ischeck(int list[][SIZE]){
	//1~9까지 체크할 불타임 배열 만들기 
	bool isCheck[9];
	//row 검사
	for(int i = 0 ; i < SIZE ; i++){
		//불타입 배열 false로 초기화 
		for(int a = 0 ; a < SIZE ; a++)
			isCheck[a] = false;
		for(int j = 0 ; j < SIZE ; j++)
			isCheck[list[i][j]-1] = true;
		//isCheck 다 트루인지 체크 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
	}
	//column검사 
	for(int j = 0 ; j < SIZE ; j++){
		//
		for(int a = 0 ; a < SIZE ; a++)
			isCheck[a] = false;
		for(int i = 0 ; i < SIZE ; i++)
			isCheck[list[i][j]-1] = true;
		//isCheck 다 트루인지 체크 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
	}	
	//사각형 검사
	for(int i = 0 ; i < SIZE ; i=i+3){
		for(int j = 0 ; j < SIZE ; j=j+3){
			//검사 범위 
			for(int a = 0 ; a < SIZE ; a++)
				isCheck[a] = false;
			for(int l = i ; l < i+3 ; l++){
				for(int k = j; k < j+3 ; k++){
					isCheck[list[l][k]-1] = true;
				}
			} 
			//isCheck 다 트루인지 체크 
		for(int b = 0 ; b < SIZE ; b++)
			if(!isCheck[b])
				return false;
		}
	}	
	return true;
}
int main(){
	//스도쿠판 입력받기
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

