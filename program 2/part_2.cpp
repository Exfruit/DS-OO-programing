#include <iostream>
#include <cstdlib>
#include <deque>
#include <algorithm>

using namespace std;

struct node{
	char character;
	int freq;
	node *lchild;
	node *rchild;
	int HuffmanCode[200];
	int length;
};

bool comp(node *a, node *b){
	return a->freq < b->freq;
}

deque<node*> forest;
node *ptr;
unordered_map<char, int> freq;

void getHuffmanCode(node *root, int code[], int top){
	if(root->lchild){
		code[top] = 0;
		ptr = root->lchild;
		ptr->length = top + 1;
		for (int i = 0; i <= top; i++){
			ptr->HuffmanCode[i] = code[i];
		}
		root->lchild = ptr;
		getHuffmanCode(root->lchild, code, top + 1);
	}
	if(root->rchild){
		code[top] = 1;
		ptr = root->rchild;
		ptr->length = top + 1;
		for (int i = 0; i <= top; i++){
			ptr->HuffmanCode[i] = code[i];
		}
		root->rchild = ptr;
		getHuffmanCode(root->rchild, code, top + 1);
	}
}

int main()
{
	char c;
    while((c = getchar()) != EOF){
        if(c == '\n'){
        	continue;
        }
        if(freq.count(c)){
        	freq[c]++;
        }
        else
        	freq[c] = 1;
    }

	for(auto it = freq.begin(); it != freq.end(); it++){
		ptr = new node;
		ptr->character = it->first;
		ptr->freq = it->second;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		forest.push_back(ptr);
	}

	//Use the forest to construct the huffman tree
	for(int i = 0; i < freq.size() - 1; i++){
		sort(forest.begin(), forest.end(), comp);
		ptr = new node;
		ptr->freq = (forest[0]->freq) + (forest[1]->freq);
		ptr->lchild = forest[0];
		ptr->rchild = forest[1];
		forest.pop_front();
		forest.pop_front();
		forest.push_back(ptr);
	}

	int code[200];	//huffman code
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
