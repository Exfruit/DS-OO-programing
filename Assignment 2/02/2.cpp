#include <iostream>
#include <stack>
using namespace std;

template <class T>
struct TreeNode{
	T data;
	TreeNode<T> *lchild;
	TreeNode<T> *rchild;
	TreeNode<T>(T val):data(val), lchild(NULL), rchild(NULL){};
};

template <class T>
class BinaryTree
{
public:
	TreeNode<T> *root;
	BinaryTree<T>():root(0){};
	BinaryTree<T>(TreeNode<T> *node):root(node){};

	void Postorder(){
		int i = 1;
		T tmp;
		stack<TreeNode<T>* > s;
		stack<T> result;
		TreeNode<T> *currentNode;
		currentNode = root;
		s.push(currentNode);
		while(!s.empty()){
			currentNode = s.top();
			s.pop();
			result.push(currentNode->data);
			if(currentNode->lchild != NULL)
				s.push(currentNode->lchild);
  		    if(currentNode->rchild != NULL)
  		    	s.push(currentNode->rchild);
		}
		while(!result.empty()){
			tmp = result.top();
			result.pop();
			cout << i++ << ": " << tmp << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	TreeNode<char> *A = new TreeNode<char>('A'),
						*B = new TreeNode<char>('B'),
							*C = new TreeNode<char>('C'),
								*D = new TreeNode<char>('D'),
									*E = new TreeNode<char>('E'),
										*F = new TreeNode<char>('F'),
											*G = new TreeNode<char>('G'),
												*H = new TreeNode<char>('H'),
													*I = new TreeNode<char>('I');
	A->lchild = B;
	A->rchild = C;
	B->lchild = D;
	B->rchild = E;
	C->lchild = F;
	E->lchild = G;
	E->rchild = H;
	F->rchild = I;
/*		 A
       /   \
	 B       C
    / \     /
   D   E   F
      / \  \
      G H   I
*/
	// cout << "FUCK" << endl;
	BinaryTree<char> Tree(A);
	Tree.Postorder();


	return 0;
}