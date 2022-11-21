

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *Insert(Node *root, int data)
{

    if (root == NULL)
    {
        Node *new_node = new Node(data);
        root = new_node;
        return root;
    }

    if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }

    else if (data < root->data)
    {
        root->left = Insert(root->left, data);
    }

    else
    {
        return root;
    }

    return root;
}

void Traverse(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            };
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *Min(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *Delete(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = Delete(root->left, key);

    else if (key > root->data)
        root->right = Delete(root->right, key);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = Min(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void func(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n;
    cout << "\nEnter number of elements";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nArray:[";
    func(arr, n);
    cout << "]";
    cout << endl;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = Insert(root, arr[i]);
    }

    Traverse(root);

    int key;
    cout << "\nEnter element to be deleted:";
    cin >> key;

    root = Delete(root, key);

    cout << "\nAfter deleting:" << key << endl;
    cout << endl;
    Traverse(root);
}

//Time Complexity of Binary Search Tree is O(n)
