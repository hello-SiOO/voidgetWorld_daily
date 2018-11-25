#include<iostream>
#include<cmath>
using namespace std;
//중심도시
//도시위치 계산 합 배열에 넣기
void sumOfCities(double pointOfCity[][2], int size, double sum[]){
	for(int i = 0 ; i < size ; i++){
		for(int k = 0 ; k < size ; k++){
			sum[i] += sqrt(pow((pointOfCity[k][0]-pointOfCity[i][0]),2.0)+pow((pointOfCity[k][1]-pointOfCity[i][1]),2.0));
		}
	}
} 
//중심도시 구하기
int centerIndex(double sumOfCity[], int size){
	double min = sumOfCity[0];
	int minIndex = 0;
	for(int i = 1 ; i < size ; i++){
		if(min > sumOfCity[i]){
			min = sumOfCity[i];
			minIndex = i;
		}
	}
	return minIndex;
} 
int main(){
	//도시 수 입력 
	cout << "Enter the number of cities: ";
	int n;
	cin >> n;
	//도시 위치 입력 
	double pointsOfCity[20][2];
	cout << "Enter the coordinates of the cities: ";
	for(int i = 0 ; i < n ; i++){
			cin >> pointsOfCity[i][0] >> pointsOfCity[i][1] ;
	}
	//한도시당 거리의합 배열
	double sumOfCity[20]={0,};
	sumOfCities(pointsOfCity, n, sumOfCity);
	cout<<"The central city is at ("<<pointsOfCity[centerIndex(sumOfCity, n)][0]<<", "<<pointsOfCity[centerIndex(sumOfCity, n)][1]<<")"<<endl;
	cout << "The total distance to all other cities is " << sumOfCity[centerIndex(sumOfCity, n)]<<endl; 
	
	return 0;
}
