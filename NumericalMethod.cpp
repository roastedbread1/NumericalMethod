#include <iostream>
#include <cmath>

using namespace std;

float ft(const float* arr, int i, float h) {
    return (arr[i + 1] - arr[i - 1]) / (2 * h);
}

float f(const float* arr, int i, float ft_val) {
    return arr[i] + ft_val;
}

float forward(const float* arr, int i, float h) {
    return (arr[i+1] - arr[i]) / h;
}
float backward(const float* arr, int i, float h) {
    return (arr[i] - arr[i-1]) / h;
}

float linear(const float* arr, int size, float x) {
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

int main() {
    float arr[20] = {
        53.9, 54.0, 54.5, 53.1, 53.5,
        53.7, 54.7, 54.4, 54.8, 53.2,
        52.3, 53.5, 51.1, 53.4, 54.4,
        53.1, 53.3, 55.0, 54.2, 54.7
    };
    //53.9, 54.8, 53.5, 54.0

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Day | Value" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i < 9 ? " " : "") << i + 1 << " | " << arr[i] << endl;
    }

    cout << "1. Finite Difference \n2. Linear Regression: ";
    int method;
    cin >> method;
    float d;
    float h;

    if (method == 1) {
        cout << "1. Central Difference\n2.Forward Difference\n3.Backward Difference" << endl;
        cout << "Enter a difference method: ";
        int diff;
        cin >> diff;
        
        if (diff == 1) {
            cout << "Enter a day - 1 value to predict : ";
            cin >> d;
            cout << "Enter h: ";
            cin >> h;
            cout << f(arr, d, ft(arr, d, h)) << endl;
        }
        else if (diff == 2) {
            cout << "Enter a day - 1 value to predict : ";
            cin >> d;
            cout << "Enter h: ";
            cin >> h;
            cout << f(arr, d, forward(arr, d, h)) << endl;

        }
        else if (diff == 3) {
            cout << "Enter a day - 1 value to predict : ";
            cin >> d;
            cout << "Enter h: ";
            cin >> h;
            cout << f(arr, d, backward(arr, d, h)) << endl;
        }
    }
    else if (method == 2) {
        cout << "Enter the value of x to predict y: ";
        float x;
        cin >> x;
        cout << "Predicted value of y: " << linear(arr, size, x) << endl;
    }
    else {
        cout << "Invalid method" << endl;
    }

    return 0;
}
