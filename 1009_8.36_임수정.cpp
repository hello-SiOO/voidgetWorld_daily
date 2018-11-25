#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
bool checkParity(int arr[][6]){
	//행 검사
	for(int i = 0 ; i < 6 ; i++){
		int count = 0 ;
		for(int j = 0 ; j < 6 ; j++){
			if(arr[i][j] == 1)
				count++;
		}
		if(count%2 != 0)
			return false;
	} 
	//열 검사
	 for(int j= 0 ; j < 6 ; j++){
		int count = 0 ;
		for(int i = 0 ; i< 6 ; i++){
			if(arr[i][j] == 1)
				count++;
		}
		if(count%2 != 0)
			return false;
	}
	
	return true;
}
int main(){
	srand(time(0));
	int arr[6][6] ;
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 6 ; j++)
			arr[i][j] = rand()%2;
	}
	//배열 출력
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 6 ; j++)
			cout << arr[i][j] << " " ;
		cout << endl;
	} 
	//결과 출력
	if(checkParity(arr))
		cout << "The array is parity" <<endl;
	else
		cout << "The array is not parity" <<endl; 
	
	
	return 0;
}
