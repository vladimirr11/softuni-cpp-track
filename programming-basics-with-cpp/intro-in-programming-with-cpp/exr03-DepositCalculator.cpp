#include <iostream>

using namespace std;


int main() {

    double sumToDeposit, interestRate;
    int depositTerm;
    // double interestRate;

    cin >> sumToDeposit >> depositTerm >> interestRate;

    double money = sumToDeposit + depositTerm * ((sumToDeposit * (interestRate / 100)) / 12);
    
    cout << money << endl;

    return 0;
}