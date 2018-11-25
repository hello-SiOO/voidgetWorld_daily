#include<iostream>
using namespace std;

const int SIZE =3;
bool equals(const int m1[][SIZE], const int m2[][SIZE]){
	bool equalsm1[SIZE][SIZE];
	bool equalsm2[SIZE][SIZE];
	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			equalsm1[i][j]=false;
			equalsm2[i][j]=false;
		}
	}
	
	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			for(int l = 0 ; l < SIZE ; l++){
				for(int k = 0 ; k < SIZE ;k++){
					if(m1[i][j]==m2[l][k] && !equalsm2[l][k] && !equalsm1[i][j]){
						equalsm1[i][j]=true;
						equalsm2[l][k]=true;
						
					}
				}
			}							
		}
	}
	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			if(!equalsm1[i][j] || !equalsm2[i][j])
				return false;
		}
	}
	return true;
}
int main(){
	cout << "Enter m1:" ;
	int m1[SIZE][SIZE];
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			cin >> m1[i][j];
	cout << "Enter m2:" ;
	int m2[SIZE][SIZE];
	for(int i = 0 ; i < SIZE ; i++)
		for(int j = 0 ; j < SIZE ; j++)
			cin >> m2[i][j];
	
	if(equals(m1,m2))
		cout << "Two arrays are identical" << endl;
	else
		cout << "Two arrays are not identical" << endl;
	
	
	return 0;
} 
