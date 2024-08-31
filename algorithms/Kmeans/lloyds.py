import random
import math
import sys

class Point:
    def __init__(self, x, y, cluster=0):
        self.x = x
        self.y = y
        self.cluster = cluster

# 구조는 다른 언어들과 같게 써봤는데 실전에선 이런 식으로 함수 정의 안 해도 될 것 같애요...

def euclidean_distance(p1, p2):
    return math.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)

def initialize_centroids(points, k):
    centroids = random.sample(points, k)
    return centroids

def find_closest_centroid(point, centroids):
    best_index = 0
    best_dist = sys.float_info.max

    for i, centroid in enumerate(centroids):
        dist = euclidean_distance(point, centroid)
        if dist < best_dist:
            best_dist = dist
            best_index = i
    
    return best_index

def update_centroids(points, centroids, k):
    new_centroids = [Point(0, 0) for _ in range(k)]
    count = [0] * k

    for point in points:
        new_centroids[point.cluster].x += point.x
        new_centroids[point.cluster].y += point.y
        count[point.cluster] += 1
    
    for i in range(k):
        if count[i] > 0:
            new_centroids[i].x /= count[i]
            new_centroids[i].y /= count[i]
    
    return new_centroids

def has_converged(old_centroids, new_centroids):
    for old, new in zip(old_centroids, new_centroids):
        if euclidean_distance(old, new) > 1e-6:
            return False
    return True

def k_means(points, k):
    centroids = initialize_centroids(points, k)
    converged = False

    while not converged:
        for point in points:
            point.cluster = find_closest_centroid(point, centroids)
        
        new_centroids = update_centroids(points, centroids, k)
        converged = has_converged(centroids, new_centroids)
        centroids = new_centroids
    
    return centroids

if __name__ == "__main__":
    points = [
        Point(1.0, 2.0),
        Point(1.5, 1.8),
        Point(5.0, 8.0),
        Point(8.0, 8.0),
        Point(1.0, 0.6),
        Point(9.0, 11.0),
        Point(8.0, 2.0),
        Point(10.0, 2.0),
        Point(9.0, 3.0),
    ]

    k = 3
    k_means(points, k)

    for point in points:
        print(f"Point ({point.x}, {point.y}): Cluster {point.cluster}")
