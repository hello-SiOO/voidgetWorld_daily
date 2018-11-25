#include<iostream>
#include<cmath>
using namespace std;
//���� ������ ���� ���� ��
const int SIZE = 2;
void getRightmostLowestPoint(double points[][2], int numberOfPoint, double rightMostPoint[]){
	//����
	for(int i = 0 ; i < numberOfPoint-1 ; i++){
		double rightpointx = points[i][0];
		double rightpointindex = i;
		for(int j = i+1 ; j < numberOfPoint ; j++){
			if(rightpointx < points[j][0]){
				rightpointx = points[j][0];
				rightpointindex = j;
			}
		}
		if(rightpointindex != i){
			//x��ǥ �ٲٱ� 
			points[rightpointindex][0] = points[i][0];
			points[i][0] = rightpointx;
			//y��ǥ �ٲٱ�
			double temp = points[rightpointindex][1];
			points[rightpointindex][1] = points[i][1];
			points[i][1] = temp; 
		}
	}
	//���� ������ üũ
	double min = points[5][1];
	int minIndex = 5 ;
	for(int j = 4 ; j >= 0 ; j--){
		if(min > points[j][1]){
			min = points[j][1];
			minIndex = j;
		}
	}
	rightMostPoint[0] = points[minIndex][0];
	rightMostPoint[1] = points[minIndex][1];
}
int main(){
	cout << "Enter 6 points: ";
	double points[6][SIZE];
	for(int i = 0 ; i < 6 ; i++)
		cin >> points[i][0] >> points[i][1];
	
	double rightMostPoint[2];
	getRightmostLowestPoint(points,6,rightMostPoint);
	cout << "The rightmost lowest point is (" << rightMostPoint[0] << ", " << rightMostPoint[1]<<")"<<endl;
	
	
	
	return 0;
} 
