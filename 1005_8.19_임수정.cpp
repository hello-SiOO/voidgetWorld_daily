#include<iostream>
using namespace std;

int main(){
	int n;//ÀºÇà °¹¼ö 
	double limit;//ÃÖ¼Ò ÀÚ»ê 
	cin >> n >> limit ;
	
	double balance[100];
	double loan[100][100];
	double landbalance[100];
	for(int i = 0 ; i < n ; i++){//k = ºô·ÁÁØ ÀºÇà °¹¼ö 
		int loanNum=0;
		cin >> balance[i] >> loanNum ;
		for(int j = 0 ; j < loanNum ; j++)
			cin >> loan[i][j] ; 
	}
	
	return 0;
}
