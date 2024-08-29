#include <iostream>
#include <string>
#include <functional>

using namespace std;

// BST 의 노드로 사용될 예정
template <typename K, typename V> // Fill in the empty templates and implement the definition of the class and each member functions
class TreeNode
{
private:
    K key;
    V value;
    TreeNode<K, V> *left;
    TreeNode<K, V> *right;

public:
    TreeNode(K key, V value) : key(key), value(value), left(nullptr), right(nullptr) {}
    // getter
    K get_key() { return this->key; }
    V get_value() { return this->value; }
    TreeNode<K, V> *get_left() { return this->left; }
    TreeNode<K, V> *get_right() { return this->right; }
    V &get_value_ref() { return this->value; }

    // setter
    void set_key(K key) { this->key = key; }
    void set_value(V value) { this->value = value; }
    void set_left(TreeNode<K, V> *left) { this->left = left; }
    void set_right(TreeNode<K, V> *right) { this->right = right; }
};

template <typename K, typename V, typename Compare = std::less<K>> // Fill in the empty templates and implement the definition of the class and each member functions
class CustomMap
{
private:
    TreeNode<K, V> *root;
    Compare comp;

public:
    CustomMap() : root(nullptr), comp(Compare()) {}

    TreeNode<K, V> *get_root() { return root; }
    Compare get_compare() { return comp; }

    // iterative method
    void insert(K key, V value)
    {
        if (root == nullptr)
        {
            root = new TreeNode<K, V>(key, value);
            return;
        }
        TreeNode<K, V> *curr = root;
        TreeNode<K, V> *parent = nullptr;
        while (curr != nullptr)
        {
            parent = curr;
            if (comp(key, curr->get_key()))
            {
                curr = curr->get_left();
            }
            else
            {
                curr = curr->get_right();
            }
        }
        if (comp(key, parent->get_key()))
        {
            parent->set_left(new TreeNode<K, V>(key, value));
        }
        else
        {
            parent->set_right(new TreeNode<K, V>(key, value));
        }
    }

    void print_map()
    {
        inorder_traverse(root);
    }

    void inorder_traverse(TreeNode<K, V> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder_traverse(node->get_left());
        cout << node->get_key() << ":" << node->get_value() << endl;
        inorder_traverse(node->get_right());
    }

    void deleteKey(K key)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode<K, V> *curr = root;
        TreeNode<K, V> *parent = nullptr;

        while (curr != nullptr && curr->get_key() != key)
        {
            parent = curr;
            if (comp(key, curr->get_key()))
            {
                curr = curr->get_left();
            }
            else
            {
                curr = curr->get_right();
            }
        }

        if (curr == nullptr)
        {
            return;
        }

        // Case 1: Leaf Node
        if (curr->get_left() == nullptr && curr->get_right() == nullptr)
        {
            if (curr == root)
            {
                root = nullptr;
            }
            // curr is left child of parent
            else if (comp(curr->get_key(), parent->get_key()))
            {
                parent->set_left(nullptr);
            }
            else
            {
                parent->set_right(nullptr);
            }
            delete curr;
        }

        // Intermidiate Node with one child
        else if (curr->get_left() == nullptr || curr->get_right() == nullptr)
        {
            TreeNode<K, V> *child = (curr->get_left() == nullptr) ? curr->get_right() : curr->get_left();
            if (curr == root)
            {
                root = child;
            }
            else if (comp(curr->get_key(), parent->get_key()))
            {
                parent->set_left(child);
            }
            else
            {
                parent->set_right(child);
            }
            delete curr;
        }

        // Node with two children
        else
        {
            // 오른쪽 서브트리에서 제일 왼쪽에 있는 노드를 찾아서 삭제할 노드의 위치로 옮김
            TreeNode<K, V> *successor = curr->get_right();
            TreeNode<K, V> *successor_parent = curr;
            while (successor->get_left() != nullptr)
            {
                successor_parent = successor;
                successor = successor->get_left();
            }
            curr->set_key(successor->get_key());
            curr->set_value(successor->get_value());
            if (successor_parent->get_left() == successor)
            {
                successor_parent->set_left(successor->get_right());
            }
            // 삭제할 노드가 successor의 부모 노드인 경우
            else
            {
                successor_parent->set_right(successor->get_right());
            }
            delete successor;
        }
    }

    V get_value(K key)
    {
        TreeNode<K, V> *curr = root;
        while (curr != nullptr)
        {
            if (curr->get_key() == key)
            {
                return curr->get_value();
            }
            else if (comp(key, curr->get_key()))
            {
                curr = curr->get_left();
            }
            else
            {
                curr = curr->get_right();
            }
        }
        return V();
    }

    V &operator[](const K &key)
    {
        TreeNode<K, V> *curr = root;
        TreeNode<K, V> *parent = nullptr;
        while (curr != nullptr)
        {
            parent = curr;
            if (curr->get_key() == key)
            {
                return curr->get_value_ref();
            }
            else if (comp(key, curr->get_key()))
            {
                curr = curr->get_left();
            }
            else
            {
                curr = curr->get_right();
            }
        }

        if (parent == nullptr)
        {
            root = new TreeNode<K, V>(key, V());
            curr = root;
        }
        else if (comp(key, parent->get_key()))
        {
            parent->set_left(new TreeNode<K, V>(key, V()));
            curr = parent->get_left();
        }
        else
        {
            parent->set_right(new TreeNode<K, V>(key, V()));
            curr = parent->get_right();
        }
        return curr->get_value_ref();
    }
};
