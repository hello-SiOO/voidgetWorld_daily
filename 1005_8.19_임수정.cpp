#include<iostream>
using namespace std;

int main(){
	int n;//���� ���� 
	double limit;//�ּ� �ڻ� 
	cin >> n >> limit ;
	
	double balance[100];
	double loan[100][100];
	double landbalance[100];
	for(int i = 0 ; i < n ; i++){//k = ������ ���� ���� 
		int loanNum=0;
		cin >> balance[i] >> loanNum ;
		for(int j = 0 ; j < loanNum ; j++)
			cin >> loan[i][j] ; 
	}
	
	return 0;
}
