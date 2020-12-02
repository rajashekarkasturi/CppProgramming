#include<iostream>
using std::cout;
using std::endl;

struct TreeNode {  TreeNode *left, *right;};

class A {
    public:
        void preorder(TreeNode* node) {
            if(node) {
                process(node);
                preorder(node->left);
                preorder(node->right);
            }
        }
    private:
    virtual void process(TreeNode* node) {}
};

class B : public A {
    private:
    void process(TreeNode* node) {
        cout << "Cutomized process_node() of B" << endl;
    }
};

int main(void) {
    B b;
    b.preorder(root);
    return 1;
}

/*
 * 1. is-a relationship between base class and derived class
 * 2. Base class defines a "generic" algorithm(process) that's used by derived class
 * 3. The "generic" algorithm is customized by the derived class.
 */