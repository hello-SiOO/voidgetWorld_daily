//
//  main.cpp
//  1124_12.3_임수정
//
//  Created by 임수정 on 2018. 11. 25..
//  Copyright © 2018년 임수정. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
template<typename T>
int binarySearch(T list[], int size, T key){
    int high = size-1;
    int low = 0;
    for(int i = 0 ; i < size ; i++){
        int mid = (high+low)/2;
        if(*(list+mid) == key)
            return mid;
        else if(*(list+mid)<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
int main(){
    int list1[10] = {1,2,3,4,5,6,7,8,9,0};
    double list2[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1};
    string list3[4] = {"sujeong","sorry","hyein","bus"};
    
    int key1;
    cout << "Enter a integer key: ";
	cin >> key1;
	cout << key1 << " in " << binarySearch(list1,10,key1) <<" index of the list" << endl;
	
	double key2;
    cout << "Enter a double key: ";
	cin >> key2;
	cout << key2 << " in " << binarySearch(list2,10,key2) <<" index of the list" << endl;
	
	string key3;
    cout << "Enter a string key: ";
	cin >> key3;
	cout << key3 << " in " << binarySearch(list3,4,key3) <<" index of the list" << endl;
	
	 
    return 0;
}
