#include "tree.h"
using namespace std; 



int main()
{
    srand(time(0));
    Node* root = nullptr;
    createTree(&root);
    print(root);
//    runProblem6(&root);
     runProblem12(&root);
    empty(root);
    system("pause");
    return 0;
}


