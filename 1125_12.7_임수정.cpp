//
//  main.cpp
//  1123_12.6_임수정
//
//  Created by 임수정 on 2018. 11. 23..
//  Copyright © 2018년 임수정. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Stack{
public:
    Stack(){
        size = 0;
    }
    bool empty() const{
        if(size != 0)
        return true;
        else
            return false;
    }
    T peek() const{
        return elements[size-1];
    }
    void push(T value){
        elements[size] = value;
    }
    T pop(){
        return elements[--size];
    }
    int getSize() const{
        return size;
    }
    void printStack(){
        for(int i = 0 ; i < size ; i++){
            cout << elements[i];
            if(i != size-1)
                cout << ", ";
        }
        cout << endl;
    }
    bool contains(T a){
    	for(int i = 0 ; i < size ; i++){
			if(*(elements+i)==a)
    			return true;
    	}
    	return false;
	}
private:
    T elements[100];
    int size;
};
int main(){
    Stack<int> Stack1;
    int n;
    cout << "Enter elements of stack :";
    for(int i = 0 ; i < 5 ; i++){
        cin >> n;
        Stack1.push(n);
    }
    if(!Stack1.empty()){
        Stack1.printStack();
    }
    
    Stack<string> Stack2;
    string s;
    cout << "Enter elements of stack :";
    for(int i = 0 ; i < 5 ; i++){
        cin >> s;
        Stack2.push(s);
    }
    if(!Stack2.empty()){
        Stack1.printStack();
    }
    
    cout << "the key : " ;
    string a;
	cin >> a ;
	if(Stack2.contains(a))
		cout << "yes" << endl;
	else
		cout << "nooo" << endl;
    
    return 0;
}
