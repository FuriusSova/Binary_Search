#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calcSum(double& x, int& counter);
void printHeader(double& x, int& counter, double& result);
void printResult(double& x, int& counter, double& result);
int main()
{
    double x;
    int counter = 2;
    cout << "Enter x (-1; 1)" << endl;
    cin >> x;
    while (x <= -1 || x >= 1) {
        cout << "Wrong argument, please enter x" << endl;
        cin >> x;
    };
    calcSum(x, counter);
}
void printResult(double& x, int& counter, double& result) {
    cout << right << setw(8) << x;
    cout << setw(20) << result;
    cout << setw(20) << counter << endl;
};
void printHeader(double& x, int& counter, double& result) {
    cout << right << setw(8) << "x";
    cout << setw(20) << "f_sum(x)";
    cout << setw(20) << "N_adds" << endl;
    printResult(x, counter, result);
};
double calcSum(double& x, int& counter) {
    double result = x;
    double elem = result;
    double absElem = 0;
    double num = pow(10, -8);
    while (absElem > num || absElem == 0) {
        double expression = x / ((4 * (counter * counter)) + 2 * counter);
        elem = elem * expression;
        absElem = abs(elem);
        result += elem;
        counter++;
    };
    printHeader(x, counter, result);
    return 0;
};

/*  1 варіант
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calcSum(double& x, int& counter);
void printHeader(double& x, int& counter, double& result);
void printResult(double& x, int& counter, double& result);
int main()
{
    double x;
    int counter = 1;
    cout << "Enter x (-1; 1)" << endl;
    cin >> x;
    while (x <= -1  x >= 1) {
        cout << "Wrong argument, please enter x" << endl;
        cin >> x;
    };
    calcSum(x, counter);
}
void printResult(double& x, int& counter, double& result) {
    cout << right << setw(8) << x;
    cout << setw(20) << result;
    cout << setw(20) << counter << endl;
};
void printHeader(double& x, int& counter, double& result) {
    cout << right << setw(8) << "x";
    cout << setw(20) << "f_sum(x)";
    cout << setw(20) << "N_adds" << endl;
    printResult(x, counter, result);
};
double calcSum(double& x, int& counter) {
    double result = -x/2;
    double elem = result;
    double absElem = 0;
    double num = pow(10, -8);
    while (absElem > num  absElem == 0) {
        double expression = x / 4;
        elem = elem * expression;
        absElem = abs(elem);
        result += elem;
        counter++;
    };
    printHeader(x, counter, result);
    return 0;
};
*/
