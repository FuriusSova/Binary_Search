#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void about();
void getArgs(double & x, double & epsilon);
void calcFunc(double & x, double & epsilon);
void calcSum(double & x, double & epsilon, double& res, int  & counter);
void printHeader(double & x, double & res, double & result, double & diff, int & counter);
void printResult(double & x, double & res, double & result, double & diff, int & counter);

int main()
{
    about();
    double x, epsilon;
    cout << "Enter x (-1; +1)" << endl;
    cin >> x;
    while (x <= -1 || x >= 1) {
        cout << "Wrong argument, please enter x (-1; +1)" << endl;
        cin >> x;
    };
    cout << "Enter epsilon" << endl;
    cin >> epsilon;
    while (epsilon <= 0) {
        cout << "Wrong argument, please enter epsilon" << endl;
        cin >> epsilon;
    };
    getArgs(x, epsilon);
}

void about() {
    cout << "Lab 2" << endl << "Sova Denis from K-17" << endl;
};

void getArgs(double& x, double& epsilon) {
    cout << "Arguments have been received" << endl;
    calcFunc(x, epsilon);
};

void calcFunc(double& x, double& epsilon) {
    double res = pow(1 + x, -0.5);
    int counter = 1;
    calcSum(x, epsilon, res, counter);
};

void calcSum(double& x, double& epsilon, double& res, int& counter) {
    double sum = 0;
    int countDod = counter;
    for (double dodanok = 1 + (-x / 2), summa = dodanok, modyl = epsilon + 1; modyl > epsilon; countDod++) {
        sum = summa;
        cout << dodanok << endl;
        double expression = (((2 * counter) + 1) * (-x)) / ((2 * counter) + 2);
        if (counter % 2 == 0) {
            if (dodanok < 0) {
                dodanok = dodanok * expression;
            }
            else {
                dodanok = -dodanok * expression;
            };
        }
        else {
            if (dodanok < 0) {
                dodanok = -dodanok * expression;
            }
            else {
                dodanok = dodanok * expression;
            };
        }
        if (dodanok < 0) {
            modyl = -dodanok;
        }
        else {
            modyl = dodanok;
        };
        summa += dodanok;
        cout << sum << " " << summa << endl;
    };
    double differ = res - sum;
    printHeader(x, res, sum, differ, countDod);
};

void printHeader(double& x, double& res, double& result, double& diff, int& counter) {
    cout << right << setw(3) << "x";
    cout << setw(12) << "f_lib(x)";
    cout << setw(12) << "f_sum(x)";
    cout << setw(12) << "diff";
    cout << setw(12) << "N_adds" << endl;
    printResult(x, res, result, diff, counter);
};

void printResult(double& x, double& res, double& result, double& diff, int& counter) {
    cout << right << setw(3) << x;
    cout << setw(12) << res;
    cout << setw(12) << result;
    cout << setw(12) << diff;
    cout << setw(12) << counter << endl;
};




