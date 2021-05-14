#include <iostream>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

struct node{
	char character;
	int freq;
	node *lchild;
	node *rchild;
	string HuffmanCode;
	int length;
};

bool comp(node *a, node *b){
	return a->freq < b->freq;
}

deque<node*> forest, Alphabets;
node *ptr;

void getHuffmanCode(node *root, string code, int length){
	if(root->lchild){
		code = "0" + code;
		ptr = root->lchild;
		ptr->length = length + 1;
		ptr->HuffmanCode = code;
		root->lchild = ptr;
		getHuffmanCode(root->lchild, code, length + 1);
	}
	if(root->rchild){
		code = "1" + code;
		ptr = root->rchild;
		ptr->length = length + 1;
		ptr->HuffmanCode = code;
		root->rchild = ptr;
		getHuffmanCode(root->rchild, code, length + 1);
	}
}

int main()
{
	int Alphabets_freq[26] = {7, 2, 2, 3, 11, 2, 2, 6, 6, 1, 1, 4, 3,
							7, 9, 2, 1, 6, 6, 8, 4, 1, 2, 1, 2, 1};
	//Construct a forest for Alphabets
	for(int i = 0; i < 26; i++){
		ptr = new node;
		ptr->freq = Alphabets_freq[i];
		ptr->character = i + 'A';
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		Alphabets.push_back(ptr);
		forest.push_back(ptr);
	}
	//Use the forest to construct the huffman tree
	for(int i = 0; i < 25; i++){
		sort(forest.begin(), forest.end(), comp);
		ptr = new node;
		ptr->freq = (forest[0]->freq) + (forest[1]->freq);
		ptr->lchild = forest[0];
		ptr->rchild = forest[1];
		forest.pop_front();
		forest.pop_front();
		forest.push_back(ptr);
	}

	string code = "";	//huffman code
	ptr = forest.front();	//root
	getHuffmanCode(ptr, code, 0);	

	//output
	int WPL = 0;
	cout << "code list{" << '\n';
	for(int i = 0; i < 26; i++){
		cout << '\t' << Alphabets[i]->character << ":";
		for(int j = 0; j < Alphabets[i]->length; j++){		
			cout << Alphabets[i]->HuffmanCode[j];
		}	
		cout << '\n';
		WPL += (Alphabets[i]->length) * (Alphabets[i]->freq);
	}
	cout << '}' << '\n';
	cout << "WPL: " << WPL << '\n';

	return 0;
}
