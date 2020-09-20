//
//  main.cpp
//  TreeHeight
//
//  Created by Santiago Pelaez Rua on 19/09/20.
//
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

#include <iostream>
#include <vector>

using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    vector<Node *> children;
    
    Node() {
        this->parent = NULL;
    }
    
    void setParent(Node *parent) {
        this->parent = parent;
        parent->children.push_back(this);
    }
};

int treeHeight(Node *root) {
    if(root == NULL) {
        return 0;
    }
    
    int maxSize = 0;
    for(int i = 0; i < root->children.size(); i++) {
        int size = treeHeight(root->children[i]);
        
        if(size > maxSize) {
            maxSize = size;
        }
    }
    
    return 1 + maxSize;
}



int main(int argc, const char * argv[]) {
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;
    
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
    
#endif
    
    int n;
    cin >> n;
    
    vector<Node> nodes(n);
    Node *root = NULL;
    
    for(int i = 0; i < n; i++) {
        nodes[i].key = i;
    }
    
    int parent;
    for(int i = 0; i < n; i++) {
        cin >> parent;
        
        if(parent == -1) {
            root = &nodes[i];
        } else {
            nodes[i].setParent(&nodes[parent]);
        }
    }
    
    cout << treeHeight(root) << endl;
    return 0;
}
