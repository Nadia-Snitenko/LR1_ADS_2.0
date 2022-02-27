// ASD_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;


    class Node
    {
        int key;
        int height;
        Node* left;
        Node* right;
        

    public:
        Node* newNode(int const _key)
        {
            Node* node = new Node();
            node->key = _key;
            node->left = NULL;
            node->right = NULL;
            node->height = 1; 
            return(node);
        }

        int _height(Node* N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

   
        Node* rightRotate(Node* y)
        {
            Node* x = y->left;
            Node* T2 = x->right;

          
            x->right = y;
            y->left = T2;

            // Update heights
            y->height = max(_height(y->left),
                _height(y->right)) + 1;
            x->height = max(_height(x->left),
                _height(x->right)) + 1;

            return x;
        }

        Node* leftRotate(Node* x)
        {
            Node* y = x->right;
            Node* T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;

            // Update heights
            x->height = max(_height(x->left),
                _height(x->right)) + 1;
            y->height = max(_height(y->left),
                _height(y->right)) + 1;

            return y;
        }

        // Get Balance factor of node N
        int getBalance(Node* N)
        {
            if (N == NULL)
                return 0;
            return _height(N->left) - _height(N->right);
        }

        Node* insert(int _key)
        {
            return insert(set, _key);
        }

        Node* insert(Node* node, int key)
        {
            /* 1. Perform the normal BST insertion */
            if (node == NULL)
                return(newNode(key));

            if (key < node->key)
                node->left = insert(node->left, key);
            else if (key > node->key)
                node->right = insert(node->right, key);
            else // Equal keys are not allowed in BST
                return node;

            /* 2. Update height of this ancestor node */
            node->height = 1 + max(_height(node->left),
                _height(node->right));

            /* 3. Get the balance factor of this ancestor
                node to check whether this node became
                unbalanced */
            int balance = getBalance(node);

            if (balance > 1 && key < node->left->key)
                return rightRotate(node);

           
            if (balance < -1 && key > node->right->key)
                return leftRotate(node);

           
            if (balance > 1 && key > node->left->key)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            if (balance < -1 && key < node->right->key)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }
       

        Node* minValueNode(Node* node)
        {
            Node* current = node;
            while (current->left != NULL)
                current = current->left;

            return current;
        }

        bool find(int key)
        {
            return((find(set,key))==NULL)?0:1;
        }

        Node* find(Node* root, int key) {
            
            if (root == NULL)
                return root;

            if (key == root->key)
                return root;

            if (key < root->key)
                root->left = find(root->left, key);
            else if (key > root->key)
                root->right = find(root->right, key);
        }

        // Recursive function to delete a node
        
        Node* erase( int _key)
        {
            return erase(set, _key);

        }

        Node* erase(Node* root, int key)
        {
            
            if (root == NULL)
                return root;

            if (key < root->key)
                root->left = erase(root->left, key);

            else if (key > root->key)
                root->right = erase(root->right, key);

            // if key is same as root's key, then
            // This is the node to be deleted
            else
            {
                // node with only one child or no child
                if ((root->left == NULL) ||
                    (root->right == NULL))
                {
                    Node* temp = root->left ?
                        root->left :
                        root->right;

                    // No child case
                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else // One child case
                        *root = *temp; // Copy the contents of
                                       // the non-empty child
                    free(temp);
                }
                else
                {
                    // node with two children: Get the inorder
                    // successor (smallest in the right subtree)
                    Node* temp = minValueNode(root->right);

                    // Copy the inorder successor's
                    // data to this node
                    root->key = temp->key;

                    // Delete the inorder successor
                    root->right = erase(root->right,
                        temp->key);
                }
            }

            // If the tree had only one node
            // then return
            if (root == NULL)
                return root;

            // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
            root->height = 1 + max(_height(root->left),
                _height(root->right));

            // STEP 3: GET THE BALANCE FACTOR OF
            // THIS NODE (to check whether this
            // node became unbalanced)
            int balance = getBalance(root);

           
            if (balance > 1 &&
                getBalance(root->left) >= 0)
                return rightRotate(root);

            
            if (balance > 1 &&
                getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            if (balance < -1 &&
                getBalance(root->right) <= 0)
                return leftRotate(root);

            if (balance < -1 &&
                getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        void print()
        {
            if (set != NULL)
            {
                print(set->left);
                cout << set->key << " ";
                print(set->right);
            }
        }

        void print(Node* branch)
        {
            if (branch)
            {
                print(branch->left);
                cout << branch->key << " ";
                print(branch->right);
            }
        }
        /*void clear(Node* branch)
        {
            if (branch)
            {
                print(branch->left);
                cout << branch->key << " ";
                print(branch->right);
            }
        }*/

        

}*set = NULL;
    




int main()
{
    
    set=set->insert(1111);
    set = set->insert(22);
    set = set->insert(498);
    set = set->insert(55);
    set = set->insert(55);
    set = set->insert(55);
    set = set->insert(7908);
    
    cout << "Your set: ";
    set->print();
    cout << endl;

    int n1,n2 = 0;
    cout << "What number you want to find?\n";
    cin >> n1;
    if (set->find(n1)) cout << "Super! Your number is in the set)\n"; else cout<< "Your number is not in the set\n";
   

    cout << "What number you want to delete?\n";
    cin >> n2;
    set = set->erase(n2);
    cout << "Result set: ";
    set->print();

    cout << endl;
    if (set->find(n1)) cout << "Wow! Yournumber is still in the set\n"; else cout << "Your number is not in the set\n";
    
    return 0;
}


