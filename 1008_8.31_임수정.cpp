#include <iostream>
using namespace std;
const int SIZE = 2;
bool getIntersectingPoint(const double points[][SIZE], double result[]){
	//result[0] = x , result[1] = y
	double e = (points[0][1]-points[1][1])*points[0][0] - (points[0][0]-points[1][0])*points[0][1] ;
	double f = (points[2][1]-points[3][1])*points[2][0] - (points[2][0]-points[3][0])*points[2][1] ;
	double a = points[0][1]-points[1][1];
	double b = - (points[0][0]-points[1][0]);
	double c = (points[2][1]-points[3][1]);
	double d = - (points[2][0]-points[3][0]);
	if(a*d-b*c == 0)
		return false;
	result[0] = (e * d - b * f )/(a*d - b*c);
	result[1] = (a*f-e*c)/(a*d-b*c);
	return true;
}
int main(){
	//점 4개 입력 받기 
	double points[4][2];
	cout << "Enter two point in a line and two point in the another line : ";
	for(int i = 0 ; i < 4 ; i++)
		cin >> points[i][0] >> points[i][1] ;
	double result[2];
	//교차점 출력
	if(getIntersectingPoint(points, result))
		cout << "The intersecting point is at (" << result[0] << ", " << result[1] <<")" <<endl;
	else
		cout << "The two lines are parallel" <<endl;
	
	return 0;
}
