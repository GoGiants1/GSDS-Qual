#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y;
    int cluster; // Cluster id

    Point(double a, double b) : x(a), y(b), cluster(0) {};
    Point(double a, double b, int c) : x(a), y(b), cluster(c) {};
};

double euclideanDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void initializeCentroids(vector<Point>& centroids, const vector<Point>& points, int k) {
    srand(time(0));                                      // 초기화를 위함
    for (int i = 0; i < k; ++i) {
        centroids[i] = points[rand() % points.size()];   // 랜덤한 point로 모든 centroid를 배정
    }
}

// 한 point와 centroid들이 주어졌을 때 그 point와 가장 가까운 centroid를 골라주는 함수
int findClosestCentroid(const Point& point, const vector<Point>& centroids) {
    int bestIndex = 0;
    double bestDist = numeric_limits<double>::max();

    for (int i = 0; i < centroids.size(); ++i) {
        double dist = euclideanDistance(point, centroids[i]);
        if (dist < bestDist) {
            bestDist = dist;
            bestIndex = i;
        }
    }
    return bestIndex;
}

void updateCentroids(vector<Point>& centroids, const vector<Point>& points, int k) {
    vector<int> count(k, 0);
    vector<Point> newCentroids;
    for (int i = 0; i < k; i++) newCentroids.push_back(Point(0, 0, 0));

    for (const auto& point : points) {
        newCentroids[point.cluster].x += point.x;
        newCentroids[point.cluster].y += point.y;
        count[point.cluster]++;
    } // 각각의 cluster별로 해당하는 point들의 값을 더해줌 (나중에 평균 낼 용도)

    for (int i = 0; i < k; ++i) {
        if (count[i] > 0) {
            centroids[i].x = newCentroids[i].x / count[i];
            centroids[i].y = newCentroids[i].y / count[i];
        }
    }
}

bool hasConverged(const vector<Point>& oldCentroids, const vector<Point>& newCentroids) {
    for (int i = 0; i < oldCentroids.size(); ++i) {
        if (euclideanDistance(oldCentroids[i], newCentroids[i]) > 1e-6) {
            return false;
        } // 근소한 정도 (1e-6) 이상의 차이가 난다면 converge하지 않았다 판단
    }
    return true;
}

void kMeans(vector<Point>& points, int k) {
    vector<Point> centroids;
    for (int i = 0; i < k; i++) centroids.push_back(Point(0, 0, 0));
    initializeCentroids(centroids, points, k);

    vector<Point> oldCentroids;
    bool converged = false;

    while (!converged) {
        oldCentroids = centroids;

        for (auto& point : points) {
            point.cluster = findClosestCentroid(point, centroids);
        } // 모든 point들마다 가장 가까운 centroid 찾아줌

        updateCentroids(centroids, points, k);
        converged = hasConverged(oldCentroids, centroids);
    }
}

int main() {
    vector<Point> points;
    points.push_back(Point(1.0, 2.0, 0));
    points.push_back(Point(1.5, 1.8, 0));
    points.push_back(Point(5.0, 8.0, 0));
    points.push_back(Point(8.0, 8.0, 0));
    points.push_back(Point(1.0, 0.6, 0));
    points.push_back(Point(9.0, 11.0, 0));
    points.push_back(Point(8.0, 2.0, 0));
    points.push_back(Point(10.0, 2.0, 0));
    points.push_back(Point(9.0, 3.0, 0));


    int k = 3;
    kMeans(points, k);

    for (const auto& point : points) {
        cout << "Point (" << point.x << ", " << point.y << "): Cluster " << point.cluster << endl;
    }

    return 0;
}
