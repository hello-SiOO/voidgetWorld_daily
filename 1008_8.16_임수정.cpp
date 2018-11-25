#include <iostream>
using namespace std;
const int SIZE = 2;
bool sameLine(const double points[][SIZE], int numberOfPoints) {
	for (int i = 0; i < numberOfPoints - 2; i++) {
		if ((points[i+1][1]-points[i][1])/(points[i+1][0]-points[i][0]) != (points[i + 2][1] - points[i+1][1]) / (points[i + 2][0] - points[i+1][0])) {
			return false;
		}
	}
	return true;
}
int main() {
	double points[5][SIZE];
	cout << "Enter five points: ";
	for (int i = 0; i < 5; i++) {
		cin >> points[i][0] >> points[i][1];
	}
	if (sameLine(points, 5))
		cout << "The five points are on same line" << endl;
	else 
		cout << "The five points are not on same line" << endl;
	system("pause");
	return 0;
}