#include <iostream>
#include <queue>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

struct Node;
Node* createNode(int);
void createTree(Node**);
void print(Node*, int);
void print(Node*);
int getHeight(Node*);
Node** getEmptyNode(Node**);
void empty(Node*);
Node** getLastNode(Node**);
int getSum(int val);
void searchEl6(Node* root);
int getAmount6(Node* root);
void insert(Node** root, int value);
void insert6(Node** root);
void rm6(Node** root, Node** last);
void rem6(Node** root);
void runProblem6(Node** root);
void searchEl12(Node* root);
int getAmount12(Node* root);
void insert12(Node** root);
void rm12(Node** root, Node** last);
void rem12(Node** root);
void runProblem12(Node** root);

bool is_prime(int x) {
    if(x == 2) return true;
    else if(x == 1) return false;
    for(int i = 2; i <= floor(sqrt(x)); i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

bool sqr(int x) {
    double y = abs(x);
    if(sqrt(y)==(int)sqrt(y) && sqrt(y)!=0) return true;
    else return false;
}


struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void createTree(Node** root)
{
    bool random;
    cout << "create  a random tree? 1/0 ";
    cin >> random;
    cout << endl;
    queue<Node**> myQueue;
    myQueue.push(root);
    for (int i = 0; i < 15; i++)
    {
        int data;
        if (random)
            data = -99 + rand() % 198;
        else
        {
            cout << "Input your data: ";
            cin >> data;
            cout << endl;
        }
        
        *myQueue.front() = createNode(data);
        myQueue.push(&((*myQueue.front())->left));
        myQueue.push(&((*myQueue.front())->right));
        myQueue.pop();
    }
}

void print (Node *root,int u)
{
    if (root==NULL) return;
    else
    {
        print(root->right,++u);
        for (int i=0;i<u;++i) cout<<"->  ";
        cout<< root->data <<endl;
        u--;
    }
    print(root->left,++u);
}
void print(Node* root)
{
    if (root == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    print(root, getHeight(root));
}

int getHeight(Node* root)
{
    int level = 0;
    queue<Node*> myQueue;
    myQueue.push(root);
    while (myQueue.front() != nullptr)
    {
        level++;
        myQueue.push(myQueue.front()->left);
        myQueue.pop();
    }
    return level;
}
//void searchEl(Node* root, int value)
//{
//    queue<Node*> q;
//    q.push(root);
//    while (q.front() != nullptr)
//    {
//        if (q.front()->data == value)
//        {
//            cout << "Node with value " << value << " found" << endl;
//            return;
//        }
//        q.push(q.front()->left);
//        q.push(q.front()->right);
//        q.pop();
//    }
//    cout << "Node with value " << value << " not found" << endl;
//}
Node** getEmptyNode(Node** root)
{
    queue<Node**> myQueue;
    myQueue.push(root);
    while (*(myQueue.front()) != nullptr && *myQueue.front())
    {
        myQueue.push(&((*myQueue.front())->left));
        myQueue.push(&((*myQueue.front())->right));
        myQueue.pop();
    }
    return myQueue.front();
}
void empty(Node* root)
{
    if (root == nullptr) return;
    empty(root->left);
    empty(root->right);
    delete root;
}

Node** getLastNode(Node** root)
{
    queue<Node**> q;
    q.push(root);
    Node** result = nullptr;
    while((*q.front()) != nullptr)
    {
        q.push(&(*q.front())->left);
        q.push(&(*q.front())->right);
        result = q.front();
        q.pop();
    }
    return result;
}

//int getSum(int val)
//{
//    int sum = 0;
//    while (val != 0)
//    {
//        sum += val % 10;
//        val /= 10;
//    }
//    return abs(sum);
//}

//void insert5(Node** root, int value)
//{
//    Node** temp = getEmptyNode(root);
//    (*temp) = createNode(value);
//}

void searchEl6(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (q.front() != nullptr)
    {
        if (is_prime(q.front()->data) && q.front()->data>0)
        {
            cout << "Node`s module with value " << q.front()->data << " is in the tree " << endl;
        }
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
}
int getAmount6(Node* root)
{
    int result = 0;
    queue<Node*> q;
    q.push(root);
    while (q.front() != nullptr)
    {
        if (is_prime(q.front()->data) && q.front()->data>0 && q.front() != nullptr && q.front())
        {
            result++;
        }
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
    return result;
}
void insert(Node** root, int value)
{
    Node** temp = getEmptyNode(root);
    (*temp) = createNode(value);
}
void insert6(Node** root)
{
    int val = 1;
    while (val < 100)
    {
        if (is_prime(val)) insert(root, val);
        val++;
    }
}
void rm6(Node** root, Node** last)
{
    if (*root == nullptr || !(*last)) return;
    if (is_prime((*root)->data) && (*root)->data >0)
    {
        (*root)->data = (*last)->data;
        delete *last;
        *last = nullptr;
        return;
    }
    rm6(&((*root)->left), last);
    rm6(&((*root)->right), last);
    
}
void rem6(Node** root)
{
    int n = getAmount6(*root);
    for (int i = 0; i < n; i++)
        rm6(root, getLastNode(root));
}
void runProblem6(Node** root)
{
    cout << "Finding items" << endl;
    searchEl6(*root);
    cout << "Removing items" << endl;
    rem6(root);
    print(*root);
        cout << "inserting items" << endl;
        insert6(root);
        print(*root);
}

/////////////////TASK 12////////////////////////

void searchEl12(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (q.front() != nullptr)
    {
        if (sqr(q.front()->data))
        {
            cout << "Node`s module with value " << q.front()->data << " is in the tree " << endl;
        }
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
}
int getAmount12(Node* root)
{
    int result = 0;
    queue<Node*> q;
    q.push(root);
    while (q.front() != nullptr)
    {
        if (sqr(q.front()->data)  && q.front() != nullptr && q.front())
        {
            result++;
        }
        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }
    return result;
}

void rm12(Node** root, Node** last)
{
    if (*root == nullptr || !(*last)) return;
    if (sqr((*root)->data))
    {
        (*root)->data = (*last)->data;
        delete *last;
        *last = nullptr;
        return;
    }
    rm12(&((*root)->left), last);
    rm12(&((*root)->right), last);
    
}
void rem12(Node** root)
{
    int n = getAmount6(*root);
    for (int i = 0; i < n; i++)
        rm12(root, getLastNode(root));
}
void insert12(Node** root)
{
    int val = -99;
    while (val < 100)
    {
        if (sqr(val)) insert(root, val);
        val++;
    }
}
void runProblem12(Node** root)
{
    cout << "Finding items" << endl;
    searchEl12(*root);
    cout << "Removing items" << endl;
    rem6(root);
    print(*root);
    cout << "inserting items" << endl;
    insert12(root);
    print(*root);
    
}



