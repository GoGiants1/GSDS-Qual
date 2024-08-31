#include <float.h> // DBL_MAX
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

typedef struct {
    double x, y;
    int cluster;
} Point;

double euclideanDistance(const Point* p1, const Point* p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

void initializeCentroids(Point* centroids, const Point* points, int numPoints, int k) {
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        centroids[i] = points[rand() % numPoints];
    }
}

int findClosestCentroid(const Point* point, const Point* centroids, int k) {
    int bestIndex = 0;
    double bestDist = DBL_MAX;

    for (int i = 0; i < k; ++i) {
        double dist = euclideanDistance(point, &centroids[i]);
        if (dist < bestDist) {
            bestDist = dist;
            bestIndex = i;
        }
    }
    return bestIndex;
}

void updateCentroids(Point* centroids, const Point* points, int numPoints, int k) {
    int* count = (int*)calloc(k, sizeof(int));
    Point* newCentroids = (Point*)calloc(k, sizeof(Point));

    for (int i = 0; i < numPoints; ++i) {
        int cluster = points[i].cluster;
        newCentroids[cluster].x += points[i].x;
        newCentroids[cluster].y += points[i].y;
        count[cluster]++;
    }

    for (int i = 0; i < k; ++i) {
        if (count[i] > 0) {
            centroids[i].x = newCentroids[i].x / count[i];
            centroids[i].y = newCentroids[i].y / count[i];
        }
    }

    free(count);
    free(newCentroids);
}

int hasConverged(const Point* oldCentroids, const Point* newCentroids, int k) {
    for (int i = 0; i < k; ++i) {
        if (euclideanDistance(&oldCentroids[i], &newCentroids[i]) > 1e-6) {
            return 0;
        }
    }
    return 1;
}

void kMeans(Point* points, int numPoints, int k) {
    Point* centroids = (Point*)calloc(k, sizeof(Point));
    initializeCentroids(centroids, points, numPoints, k);

    Point* oldCentroids = (Point*)calloc(k, sizeof(Point));
    int converged = 0;

    while (!converged) {
        for (int i = 0; i < k; ++i) {
            oldCentroids[i] = centroids[i];
        }

        for (int i = 0; i < numPoints; ++i) {
            points[i].cluster = findClosestCentroid(&points[i], centroids, k);
        }

        updateCentroids(centroids, points, numPoints, k);
        converged = hasConverged(oldCentroids, centroids, k);
    }

    free(centroids);
    free(oldCentroids);
}

int main() {
    Point points[] = {
        {1.0, 2.0, 0},
        {1.5, 1.8, 0},
        {5.0, 8.0, 0},
        {8.0, 8.0, 0},
        {1.0, 0.6, 0},
        {9.0, 11.0, 0},
        {8.0, 2.0, 0},
        {10.0, 2.0, 0},
        {9.0, 3.0, 0}
    };

    int numPoints = sizeof(points) / sizeof(Point);
    int k = 3;
    kMeans(points, numPoints, k);

    for (int i = 0; i < numPoints; ++i) {
        printf("Point (%.1f, %.1f): Cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }

    return 0;
}
