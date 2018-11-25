#include<iostream>
using namespace std;

bool isConsecutiveFour(int values[][7]){
	//행 검사
	for(int i = 0 ; i < 6 ; i++){
		int count = 1 ;
		for(int j = 0 ; j < 6 ; j++){
			if(values[i][j] == values[i][j+1]){
				count++;
				if(count == 4)
					return true;
			}
			else
				count = 1;
		}
	}	
	//열 검사
	for(int j= 0 ; j < 7 ; j++){
		int count = 1 ;
		for(int i = 0 ; i < 5 ; i++){
			if(values[i][j] == values[i+1][j]){
				count++;
				if(count == 4)
					return true;
			}
			else
				count = 1;
		}
	}
	//정대각선 검사
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 4 ; j++){	//점을 움직이는 포문 
			if(values[i][j] == values[i+1][j+1] == values[i+2][i+2] == values[i+3][i+3])
				return true;
			}		
		}
	//반대각선 검사
	for(int i = 5 ; i > 3 ; i--){
		for(int j = 0 ; j < 4 ; j++){	//점을 움직이는 포문 
			if(values[i][j] == values[i-1][j+1] == values[i-2][i+2] == values[i-3][i+3])
				return true;
			}		
		}
	return false; 
}
int main(){
	int arr[6][7];
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 7 ; j++)
			cin >> arr[i][j] ;
	} 
	if(isConsecutiveFour(arr))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	
	return 0;
}
