#include<iostream>
#include<cmath>
//»ï°¢Çü ¸é Àû 
using namespace std;
const int SIZE = 2;
double getTriangleArea(const double points[][SIZE]){
	if ((points[1][1]-points[0][1])/(points[1][0]-points[0][0]) == (points[2][1] - points[1][1]) / (points[2][0] - points[1][0]))
		return 0;
	double side1 = sqrt((points[1][0]-points[0][0])*(points[1][0]-points[0][0]) + (points[1][1]-points[0][1])*(points[1][1]-points[0][1]));
	double side2 = sqrt((points[2][0]-points[1][0])*(points[2][0]-points[1][0]) + (points[2][1]-points[1][1])*(points[2][1]-points[1][1]));
	double side3 = sqrt((points[2][0]-points[0][0])*(points[2][0]-points[0][0]) + (points[2][1]-points[0][1])*(points[2][1]-points[0][1]));
	double s = (side1+side2+side3)/2;
	return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
int main(){
	cout << "Enter x1,y1,x2,y2,x3,y3:" ;
	double points[3][SIZE];
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < SIZE ; j++){
			cin >> points[i][j];
		}
	} 
	if(getTriangleArea(points)==0)
		cout << "The three points are on the same line" << endl;
	else
		cout << "The area of the triangle is " << getTriangleArea(points) << endl;
	
	return 0;	
}
