import math
import random

def sigmoid(z): return 1.0 / (1.0 + math.exp(-z))

def predict(weights, features):
    z = weights[0]
    for i in range(1, len(weights)):
        z += weights[i] * features[i - 1]
    return sigmoid(z)

def logistic_regression(X, y, weights, learning_rate, epochs):
    m = len(X)
    n = len(X[0])

    for epoch in range(epochs):
        for i in range(m):
            prediction = predict(weights, X[i])
            error = y[i] - prediction

            weights[0] += learning_rate * error
            for j in range(n):
                weights[j + 1] += learning_rate * error * X[i][j]

def main():
    # random.seed(0) 여기서 가중치 초기화를 랜덤으로 하고 싶으면 넣는 코드

    X = [
        [2.0, 3.0],
        [1.0, 1.0],
        [4.0, 5.0],
        [6.0, 8.0],
        [10.0, 12.0],
        [5.0, 7.0]
    ]
    y = [0, 0, 0, 1, 1, 1]

    weights = [0.0] * (len(X[0]) + 1)  # +1은 bias 항을 전제로 한 것
    # 아래는 weight들을 랜덤으로 초기화한 것
    # weights = [random.uniform(-0.1, 0.1) for _ in range(len(X[0]) + 1)]

    learning_rate = 0.1
    epochs = 1000

    logistic_regression(X, y, weights, learning_rate, epochs)

    print("훈련된 가중치 (0항은 bias):")
    for weight in weights:
        print(weight, end=" ")
    print()

    new_data = [7.0, 9.0]
    prediction = predict(weights, new_data)
    print(f"for test data {new_data}: {prediction}")

if __name__ == "__main__":
    main()
