#include<iostream>
#include<cmath>
using namespace std;
//다각형의 부면적 
const int SIZE = 2;
void getIntersectingPoint(const double points[][SIZE], double result[]){
	//result[0] = x , result[1] = y
	double e = (points[0][1]-points[2][1])*points[0][0] - (points[0][0]-points[2][0])*points[0][1] ;
	double f = (points[1][1]-points[3][1])*points[1][0] - (points[1][0]-points[3][0])*points[1][1] ;
	double a = points[0][1]-points[2][1];
	double b = - (points[0][0]-points[2][0]);
	double c = (points[1][1]-points[3][1]);
	double d = - (points[1][0]-points[3][0]);
	result[0] = (e * d - b * f )/(a*d - b*c);
	result[1] = (a*f-e*c)/(a*d-b*c);
}
double getTriangleArea(double p1x, double p1y, double p2x, double p2y, double ip[SIZE]){
	
	
	double side1 = sqrt((p2x-p1x)*(p2x-p1x) + (p2y-p1y)*(p2y-p1y));
	double side2 = sqrt((ip[0]-p2x)*(ip[0]-p2x) + (ip[1]-p2y)*(ip[1]-p2y));
	double side3 = sqrt((ip[0]-p1x)*(ip[0]-p1x) + (ip[1]-p1x)*(ip[1]-p1y));
	double s = (side1+side2+side3)/2;
	return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
void selectionSort(double area[]){
	for(int i = 0 ; i < 3 ; i++){
		double min = area[i];
		int minIndex = i ;
		for(int j = i+1 ; j < 4 ; j++){
			if(area[j]<min){
				min = area[j];
				minIndex = j;
			}
		}
		if(minIndex != i){
			area[minIndex] = area[i];
			area[i] = min;
		}
	}
}
int main(){
	cout << "Enter x1,y1,x2,y2,x3,y3,x4,y4: ";
	double points[4][SIZE]; 
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < SIZE ; j++)
			cin >> points[i][j];
	}
	if ((points[1][1]-points[0][1])/(points[1][0]-points[0][0]) == (points[2][1] - points[1][1]) / (points[2][0] - points[1][0]) ==(points[3][1] - points[2][1]) / (points[3][0] - points[2][0])){
		cout << "The four points are on the same line" <<endl;
		return 0;
	}
	double intersectingPoint[SIZE];
	getIntersectingPoint(points, intersectingPoint);
	double area[4];
	for(int i = 0 ; i < 3 ; i++){
		area[i] = getTriangleArea(points[i][0],points[i][1],points[i+1][0],points[i+1][1],intersectingPoint);
	}
	area[3] = getTriangleArea(points[0][0],points[0][1],points[3][0],points[3][1],intersectingPoint);
	selectionSort(area);
	cout << "The areas are " ;
	for(int i = 0 ; i < 4 ; i++)
		cout << area[i] << " " ;
	cout << endl;

	
	return 0;
}
