// C++ program to insert element in Binary Tree
// Binary search tree와 달리 left child < root < right child 규칙 적용X (그냥 max child 2 짜리 tree)
// Ref: https://www.geeksforgeeks.org/binary-tree-data-structure/?ref=lbp

// Insertion: level order traversal을 이용하여 빈 자리 찾아서 삽입
// Deletion: 해당 노드 삭제 후 그 자리는 rightmost deepest node로 대체 
// Traversal: inorder, preorder, postorder

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

////////////// INSERTION //////////////
Node* InsertNode(Node* root, int data)
{
	// If the tree is empty, assign new node address to root
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}

	// Else, do level order traversal until we find an empty place
    // i.e. either left child or right child of some node is pointing to NULL.
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}

////////////// DELETION //////////////
Node* deletion(Node* root, int key) // key: node to delete
{ 
    if (root == NULL) 
        return NULL; 
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == key) 
            return NULL; 
        else
            return root; 
    } 
    Node* key_node = NULL; 
    Node* temp; 
    Node* last; 
    queue<Node*> q; 
    q.push(root); 
    // Do level order traversal to find deepest 
    // node(temp), node to be deleted (key_node) 
    // and parent of deepest node(last) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp->data == key) 
            key_node = temp; 
        if (temp->left) { 
            last = temp; // storing the parent node 
            q.push(temp->left); 
        } 
        if (temp->right) { 
            last = temp; // storing the parent node 
            q.push(temp->right); 
        } 
    } 
    if (key_node != NULL) { 
        key_node->data = temp->data; // replacing key_node's data to deepest node's data 
        if (last->right == temp) 
            last->right = NULL; 
        else
            last->left = NULL; 
        delete (temp); 
    } 
    return root; 
} 

////////////// TRAVERSAL //////////////
// Inorder traversal 
void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

// preorder traversal 
void preorder(Node* temp)
{
	if (temp == NULL)
		return;

	cout << temp->data << ' ';
	preorder(temp->left);
	preorder(temp->right);
}

// postorder traversal 
void postorder(Node* temp)
{
	if (temp == NULL)
		return;

	postorder(temp->left);
	postorder(temp->right);
	cout << temp->data << ' ';
}

// Driver code
int main()
{
	Node* root = CreateNode(10);
	root->left = CreateNode(11);
	root->left->left = CreateNode(7);
	root->right = CreateNode(9);
	root->right->left = CreateNode(15);
	root->right->right = CreateNode(8);

	cout << "Inorder traversal before insertion: ";
	inorder(root);
    cout << '\n';

	root = InsertNode(root, 12);

	cout << "Inorder traversal after insertion: ";
	inorder(root);
    cout << '\n';

    root = deletion(root, 9);
    cout << "Inorder traversal after deletion: ";
    inorder(root);

	cout << endl;

	return 0;
}
