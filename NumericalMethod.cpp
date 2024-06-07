#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


float linear(const double* arr, int size, int x) {
    float m, c, sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < size; i++) {
        sum_x += i;
        sum_y += arr[i];
        sum_xy += i * arr[i];
        sum_x2 += i * i;
    }

    m = (size * sum_xy - sum_x * sum_y) / (size * sum_x2 - sum_x * sum_x);
    c = (sum_y - m * sum_x) / size;
    return m * x + c;
}
double firstDerivative(const double* arr, int i, int h, int type) {
    switch (type) {
    case 1:
        return (arr[i + h] - arr[i]) / h;
    case 2:
        return (arr[i] - arr[i - h]) / h;
    case 3:
        return (arr[i + h] - arr[i - h]) / (2 * h);
    default:
        return 0.0;
    }
}

double error(const double* forecast, const double* real, int n) {
    double sumSquaredError = 0.0;
    for (int i = 0; i < n; ++i) {
        sumSquaredError += pow(forecast[i] - real[i], 2);
    }
    return sqrt(sumSquaredError / n);
}

int main() {
    //1 - 20
    double arr[20] = { 53.9, 54.0, 54.5, 53.1, 53.5, 53.7, 54.7, 54.4, 54.8, 53.2, 52.3, 53.5, 51.1, 53.4, 54.4, 53.1, 53.3, 55.0, 54.2, 54.7 };
    //20-24
    double real[4] = { 53.9, 54.8, 53.5, 54.0 };
    int h = 1;
    

    cout << "forward difference of f(19.5) "<< endl;

    double forward = arr[18] + 0.5 * firstDerivative(arr, 18, h, 1);

    cout << forward<< endl;

    cout << "backwards difference of f(21) "<< endl;

    double backward = arr[19] - 1 * firstDerivative(arr, 19, h, 2);
    cout << backward << endl;
    cout << "central difference of f(2.5) " << endl;
    double central = arr[1] + 0.5 * firstDerivative(arr, 1, h, 3);
    cout << central << endl;

    int size = 20;
    
    double linear_forecast[4];
    for (int i = 0; i < 4; ++i) {
        linear_forecast[i] = linear(arr, 20, 18 + i);
    }

    cout << "Linear Regression Forecasted Values:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Day " << (21 + i) << ": " << linear_forecast[i] << endl;
    }


    cout << "\nReal Values:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Day " << (21 + i) << ": " << real[i] << endl;
    }

    double errLinear = error(linear_forecast, real, 4);
    cout << "\Error for Linear Regression Forecast: " << errLinear << endl;
    return 0;
}
