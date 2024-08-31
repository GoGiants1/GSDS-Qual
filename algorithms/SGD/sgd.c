#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

double predict(double* weights, double* features, int n) {
    double z = weights[0];  
    for (int i = 1; i <= n; ++i) {
        z += weights[i] * features[i - 1];
    }
    return sigmoid(z);
}

// 이중포인터 조심
void logistic_regression(double** X, int* y, double* weights, double learning_rate, int epochs, int m, int n) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (int i = 0; i < m; ++i) {
            double prediction = predict(weights, X[i], n);
            double error = y[i] - prediction;

            weights[0] += learning_rate * error;
            for (int j = 0; j < n; ++j) {
                weights[j + 1] += learning_rate * error * X[i][j];
            }
        }
    }
}

int main() {
    srand(time(0));

    double X[6][2] = {
        {2.0, 3.0}, {1.0, 1.0}, {4.0, 5.0}, {6.0, 8.0}, {10.0, 12.0}, {5.0, 7.0}
    };
    int y[6] = {0, 0, 0, 1, 1, 1};

    int m = 6;
    int n = 2;

    // C++과는 달리 여기서는 동적 할당으로 배열을 초기화해줌
    double* weights = (double*)calloc(n + 1, sizeof(double));  // +1은 bias 항을 위한 것!!

    double learning_rate = 0.1;
    int epochs = 1000;

    double* X_ptr[6];
    for (int i = 0; i < m; ++i) {
        X_ptr[i] = X[i];
    }

    logistic_regression(X_ptr, y, weights, learning_rate, epochs, m, n);

    printf("훈련된 가중치 (0항은 bias):\n");
    for (int i = 0; i <= n; ++i) {
        printf("%f ", weights[i]);
    }
    printf("\n");

    double new_data[2] = {7.0, 9.0};
    double prediction = predict(weights, new_data, n);
    printf("for test data {7.0, 9.0}: %f\n", prediction);

    // **중요** 동적 할당된 메모리 해제
    free(weights);

    return 0;
}
