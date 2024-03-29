
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<deque>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node *left, *right;

        Node(T data)
        {
            this->data = data;
            this->left = this->right = NULL;
        }
};

template<class T>
void printBinaryTree(vector<T> res){
    int n = res.size();
    for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void printBinaryTreeLevelWise(vector<vector<T> > res){
    int n = res.size();
    for(int i = 0; i < n; i++){
        int m = res[i].size();
        for(int j = 0; j < m; j++){
            cout<<res[i][j]<<" ";
        }
    }
    cout<<endl;
}

/* Pre-Order Traversal */
template <class T>
void preOrderTraversalUtil(Node<T> *node, vector<T> &res){
    if(node == NULL){
        return;
    }
    res.push_back(node->data);
    preOrderTraversalUtil(node->left, res);
    preOrderTraversalUtil(node->right, res);
}

template <class T>
vector<T> preOrderTraversal(Node<T> *root){
    vector<T>res;
    preOrderTraversalUtil(root, res);
    return res;
}

template <class T>
vector<T> iPreOrderTraversal(Node<T> *root){
    vector<T>res;
    if(root == NULL){
        return res;
    }
    stack<Node<T> *> stk;
    stk.push(root);
    while(!stk.empty()){
        Node<T> *curr = stk.top();
        res.push_back(curr->data);
        stk.pop();
        if(curr->right){
            stk.push(curr->right);
        }
        if(curr->left){
            stk.push(curr->left);
        }
    }
    return res;
}

template <class T>
void postOrderTraversalUtil(Node<T> *node, vector<T> &res){
    if(node == NULL){
        return;
    }
    postOrderTraversalUtil(node->left, res);
    postOrderTraversalUtil(node->right, res);
    res.push_back(node->data);
}

template <class T>
vector<T> postOrderTraversal(Node<T> *root){
    vector<T>res;
    postOrderTraversalUtil(root, res);
    return res;
}

template <class T>
vector<T>iPostOrderTraversal(Node<T> *root){
    vector<T>res;
    if(root == NULL){
        return res;
    }
    stack<Node<T> *>stk1;
    stack<T>stk2;
    stk1.push(root);
    while(!stk1.empty()){
        Node<T> *curr = stk1.top();
        stk1.pop();
        stk2.push(curr->data);
        if(curr->left){
            stk1.push(curr->left);
        }
        if(curr->right){
            stk1.push(curr->right);
        }
    }
    while(!stk2.empty()){
        res.push_back(stk2.top());
        stk2.pop();
    }
    return res;
}

template<class T>
void inOrderTraversalUtil(Node<T> *node, vector<T> &res){
    if(node == NULL){
        return;
    }
    inOrderTraversalUtil(node->left, res);
    res.push_back(node->data);
    inOrderTraversalUtil(node->right, res);
}

template<class T>
vector<T> inOrderTraversal(Node<T> *root){
    vector<T>res;
    inOrderTraversalUtil(root, res);
    return res;
}

template<class T>
vector<T> iInOrderTraversal(Node<T> *root){
    vector<T> res;
    if(root == NULL){
        return res;
    }
    stack<Node<T> *>stk;
    Node<T> *curr = root;
    while(curr != NULL || !stk.empty()){
        while(curr != NULL){
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        res.push_back(curr->data);
        curr = curr->right;
    }
    return res;
}

template<class T>
void levelOrderTraversalUtil(Node<T> *node, int level, map<int, vector<T> > &resMap){
    if(node == NULL){
        return;
    }
    resMap[level].push_back(node->data);
    levelOrderTraversalUtil(node->left, level+1, resMap);
    levelOrderTraversalUtil(node->right, level+1, resMap);
}

template<class T>
vector<vector<T> > levelOrderTraversal(Node<T> *root){
    vector<vector<T> > res;
    map<int, vector<T> > resMap;
    levelOrderTraversalUtil(root, 0, resMap);
    int n = resMap.size();
    for(int i = 0; i < n; i++){
        res.push_back(resMap[i]);
    }
    return res;
}

template<class T>
vector<vector<T> > iLevelOrderTraversal(Node<T> *root){
    vector<vector<T> >res;
    if(root == NULL){
        return res;
    }
    queue<Node<T> *>q;
    q.push(root);
    while(!q.empty()){
        int q_size = q.size();
        vector<T>levelVector;
        while(q_size--){
            Node<T> *curr = q.front();
            levelVector.push_back(curr->data);
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        res.push_back(levelVector);
    }
    return res;
}

template<class T>
vector<T> reverseLevelOrderTraversal(Node<T> *root){
    vector<T>res;
    if(root == NULL){
        return res;
    }
    queue<Node<T> *>q;
    stack<T>stk;
    q.push(root);
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            Node<T> *curr = q.front();
            stk.push(curr->data);
            q.pop();
            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
        }
    }
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

template<class T>
bool isIdentical(Node<T> *root1, Node<T> *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if((root1 == NULL || root2 == NULL) || (root1->data != root2->data)){
        return false;
    }
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

template<class T>
int height(Node<T> *root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right))+1;
}

template<class T>
vector<T> spiralOrderTraversal(Node<T> *root){
    vector<T> res;
    if(root == NULL){
        return res;
    }
    deque<Node<T> *> dq;
    dq.push_back(root);
    bool flag = 0;
    while(!dq.empty()){
        if(flag == 0){
            int dq_size = dq.size();
            while(dq_size--){
                Node<T> *curr = dq.front();
                res.push_back(curr->data);
                dq.pop_front();
                if(curr->left){
                    dq.push_back(curr->left);
                }
                if(curr->right){
                    dq.push_back(curr->right);
                }
            }
            flag = 1;
        }else{
            int dq_size = dq.size();
            while(dq_size--){
                Node<T> *curr = dq.back();
                res.push_back(curr->data);
                dq.pop_back();
                if(curr->right){
                    dq.push_front(curr->right);
                }
                if(curr->left){
                    dq.push_front(curr->left);
                }
            }
            flag = 0;
        }
    }
    return res;
}

template<class T>
void leftViewOfBinaryTreeUtil(Node<T> *node, int level, map<int, T> &resMap){
    if(node == NULL){
        return;
    }
    if(resMap.find(level) == resMap.end()){
        resMap[level] = node->data;
    }
    leftViewOfBinaryTreeUtil(node->left, level+1, resMap);
    leftViewOfBinaryTreeUtil(node->right, level+1, resMap);
}

template<class T>
vector<T> leftViewOfBinaryTree(Node<T> *root){
    vector<T>res;
    if(root == NULL){
        return res;
    }
    map<int, T> resMap;
    leftViewOfBinaryTreeUtil(root, 0, resMap);
    int n = resMap.size();
    for(int i = 0; i < n; i++){
        res.push_back(resMap[i]);
    }
    return res;
}
template<class T>
vector<T> iLeftViewOfBinaryTree(Node<T> *root){
    vector<T>res;
    if(root == NULL){
        return res;
    }
    queue<Node<T> *>q;
    q.push(root);
    int level = -1;
    while(!q.empty()){
        level++;
        int q_size = q.size();
        bool flag = true;
        while(q_size--){
            Node<T> *curr = q.front();
            q.pop();
            if(flag == true){
                res.push_back(curr->data);
                flag = false;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return res;
}

template<class T>
void bottomViewOfBinaryTreeUtil(Node<T> *node, int position, map<int, T> &resMap){
    if(node == NULL){
        return;
    }
    resMap[position] = node->data;
    bottomViewOfBinaryTreeUtil(node->left, position - 1, resMap);
    bottomViewOfBinaryTreeUtil(node->right, position + 1, resMap);
}

template<class T>
vector<T> bottomViewOfBinaryTree(Node<T> *root){
    vector<T> res;
    if(root == NULL){
        return res;
    }
    map<int, T> resMap;
    bottomViewOfBinaryTreeUtil(root, 0, resMap);
    typename map<int, T>::iterator it = resMap.begin();
    while(it!=resMap.end()){
        res.push_back(it->second);
        it++;
    }
    return res;
}



