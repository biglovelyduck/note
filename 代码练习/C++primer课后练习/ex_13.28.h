#ifndef _EX_13.28_H_
#define _EX_13.28_H_

#include <string>
using namespace std;

class TreeNode{
public://自己实现构造函数则默认的无参构造函数就没有了 
	TreeNode():value(string()),count(new int(1)),left(nullptr),right(NULL){}
	TreeNode(const TreeNode &rhs):value(rhs.value),count(rhs.count),left(rhs.left),right(rhs.right){++*count;}
	TreeNode& operator=(const TreeNode &rhs);
	~TreeNode(){
		if (--*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }
            if (right) {
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
		}
	}
private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree& operator=(const BinStrTree &bst);
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};

#endif
