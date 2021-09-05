#include <iostream>

using namespace std;


int main(){

    int firstNum, secondNum;
    cin >> firstNum >> secondNum;

    int greaterNum;

    if (firstNum > secondNum){
        greaterNum = firstNum;
    } else {
        greaterNum = secondNum;
    }

    cout << greaterNum << endl;

    return 0;
}