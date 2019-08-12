//序列化二叉树
#include <vector>
#include <stack>
#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/*
class Solution {
public:
	ostringstream oss;
	ostream &stream1=oss;
	istream stream2;
	void Serialize(TreeNode* pRoot,ostream& stream){
		if(pRoot==NULL){
			stream<<"$,";
			return;
		}
		stream<<pRoot->val<<",";
		Serialize(pRoot->left,stream);
		Serialize(pRoot->right,stream);
	}
    char* Serialize(TreeNode *root) {    
        Serialize(root,stream1);
        //ostream转string然后转char*
		return const_cast<char*>(oss.str().c_str());
    }
    bool ReadStream(istream& stream,int* number){
    	if(stream.eof()) return false;
    	char buf[32];
    	buf[0]='\0';
    	char ch;
    	stream>>ch;
    	int i=0;
    	while(!stream.eof()&&ch!=','){
    		buf[i++]=ch;
    		stream>>ch;
		}
		bool isNumeric=false;
		if(i>0&&buf[0]!='$'){
			*number=atoi(buf);
			isNumeric=true;
		}
		return isNumeric;
 	}
 	TreeNode* Deserialize(TreeNode** pRoot,istream& stream){
 		int number;
 		if(ReadStream(stream,&number)){
 			*pRoot=new TreeNode(number);
 			(*pRoot)->val=number;
			 (*pRoot)->left=NULL;
			 (*pRoot)->right=NULL; 
		 }
		 
		 Deserialize(&((*pRoot)->left),stream);
		 Deserialize(&((*pRoot)->right),stream);
	}
};*/



class Solution {  
public:
    char* Serialize(TreeNode *root) {
       if(root == NULL)
           return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
     
    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        TreeNode *ret = Deserialize(&str);
 
        return ret;
    }
    TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
        if(**str == '#'){  //所以一定要用**str,
            ++(*str);         //以保证得到递归后指针str指向未被读取的字符
            return NULL;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};
