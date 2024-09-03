#include <iostream>
#include <vector>

using namespace std;

// 배열 기반 이진 트리 순회 - 부모로부터 자식 노드 찾기
void traversal_from_root(const vector<char>& tree) {
    int n = tree.size();
    for (int i = 0; i < n; ++i) {
        if (tree[i] != '\0') {
            cout << "Parent: " << tree[i];

            int left = 2 * i + 1;
            int right = left + 1;

            if (left < n && tree[left] != '\0') {
                cout << ", Left: " << tree[left];
            }
            if (right < n && tree[right] != '\0') {
                cout << ", Right: " << tree[right];
            }
            cout << endl;
        }
    }
}

// 배열 기반 이진 트리 순회 - 자식으로부터 부모 노드 찾기
void traversal_from_leaf(const vector<char>& tree) {
    int n = tree.size();
    for (int i = n - 1; i > 0; --i) {
        if (tree[i] != '\0') {
            cout << "Parent of " << tree[i] << " -> " << tree[(i - 1) / 2] << endl;
        }
    }
}

int main() {
    // 트리 데이터를 벡터로 초기화
    vector<char> tree = {'A', 'B', 'C', 'D', 'E', 'F', '\0', 'G'};

    // 부모에서 자식 노드 찾기
    cout << "Finding children given parents." << endl;
    traversal_from_root(tree);
    cout << endl;

    // 자식에서 부모 노드 찾기
    cout << "Finding parent given child." << endl;
    traversal_from_leaf(tree);

    return 0;
}