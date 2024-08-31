#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double sigmoid(double z) { return 1.0 / (1.0 + exp(-z)); }

double predict(const vector<double>& weights, const vector<double>& features) {
    double z = weights[0]; // bias를 제외한 나머지는 for loop 내에서 feature과 곱해줌
    for (int i = 1; i < weights.size(); ++i) {
        z += weights[i] * features[i - 1];
    }
    return sigmoid(z);
}

void logistic_regression(vector<vector<double>>& X, vector<int>& y, vector<double>& weights, double learning_rate, int epochs) {
    int m = X.size();
    int n = X[0].size();

    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (int i = 0; i < m; ++i) {
            double prediction = predict(weights, X[i]);
            double error = y[i] - prediction;

            weights[0] += learning_rate * error; // bias
            for (int j = 0; j < n; ++j) {
                weights[j + 1] += learning_rate * error * X[i][j];
            }
        }
    }
}

int main() {
    srand(time(0));

    // train data
    vector<vector<double>> X = {
        {2.0, 3.0}, {1.0, 1.0}, {4.0, 5.0}, {6.0, 8.0}, {10.0, 12.0}, {5.0, 7.0}
    };
    vector<int> y = {0, 0, 0, 1, 1, 1};

    // 가중치 초기화 (컴퓨팅 수업 기준으로 0)
    vector<double> weights(X[0].size() + 1, 0.0);  // +1은 bias 항을 전제로 한 것

    double learning_rate = 0.1;
    int epochs = 1000;

    logistic_regression(X, y, weights, learning_rate, epochs);

    cout << "훈련된 가중치 (0항은 bias):" << endl;
    for (const auto& weight : weights) {
        cout << weight << " ";
    }
    cout << endl;

    vector<double> new_data = {7.0, 9.0};
    double prediction = predict(weights, new_data);
    cout << "for test data {7.0, 9.0}: " << prediction << endl;

    return 0;
}
