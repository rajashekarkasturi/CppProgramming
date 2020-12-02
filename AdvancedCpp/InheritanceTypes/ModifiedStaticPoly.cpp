#include<iostream>
using std::cout;
using std::endl;

struct TreeNode {  TreeNode *left, *right;};

//TMP : Template Metaprogramming (Moves some part run time to compile time)
template <typename T> class A {
    public:
        void preorder(TreeNode* node) {
            if(node) {
                process(node);
                preorder(node->left);
                preorder(node->right);
            }
        }
    void process(TreeNode* node) {
        static_cast<T*>(this)->process(node);
    }
};

class B : public A<B> {
    void process(TreeNode* node) {
        cout << "Cutomized process_node() of B" << endl;
    }
};

int main(void) {
    B b;
    b.preorder(root);
    return 1;
}

/* Note :
 * Curiously recurring template pattern(static polymorphism, simulated polymorphism)
 */