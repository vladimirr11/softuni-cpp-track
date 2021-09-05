#include <iostream>

using namespace std;


int main() {

    double strawberryPrice, amountBananas, amountOranges, amountRaspberries, amountStrawberry;
    cin >> strawberryPrice >> amountBananas >> amountOranges >> 
    amountRaspberries >> amountStrawberry;

    double raspberriesPrice = strawberryPrice - (strawberryPrice * 0.5);
    double orangesPrice = raspberriesPrice - (raspberriesPrice * 0.4); 
    double bananasPrice = raspberriesPrice - (raspberriesPrice * 0.8);

    double neededMoney = (strawberryPrice * amountStrawberry) + (bananasPrice * amountBananas) + 
    (orangesPrice * amountOranges) + (raspberriesPrice * amountRaspberries);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << neededMoney << endl;

    return 0;
}