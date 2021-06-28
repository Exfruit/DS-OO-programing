/*input
Dear TA, please let me pass this course. 
The loading of the assignment is toooooooooo much QQ
*/
#include <iostream>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct node{
	char character;
	int freq;
	node *lchild;
	node *rchild;
	char HuffmanCode[100000];
	int length;
};

bool comp1(node *a, node *b){
	return a->freq < b->freq;
}

bool comp2(node *a, node *b){
	return a->character < b->character;
}
deque<node*> forest, Alphabets;
unordered_map<char, int> freq;

void getHuffmanCode(node *root, char *code, int length){
	node *ptr;
	if(root->lchild){
        code[length] = '0';
        ptr = root->lchild;
        ptr->length = length + 1;
        for(int i = 0; i <= length; i++){
            ptr->HuffmanCode[i] = code[i];
        }
        root->lchild = ptr;
        getHuffmanCode(root->lchild, code, length + 1);
    }
    
    if(root->rchild){
        code[length] = '1';
        ptr = root->rchild;
        ptr->length = length + 1;
        for(int i = 0; i <= length; i++){
            ptr->HuffmanCode[i] = code[i];
        }
        root->rchild = ptr;
        getHuffmanCode(root->rchild, code, length + 1);
    }
}
int main(){
	cout << "Enter character: " << '\n';
	char c, input_length = 0;
	string input = "";
    while((c = getchar()) != EOF){
    	input_length++;
    	input = input + c;
        if(c == '\n'){
        	continue;
        }
        if(freq.count(c)){
        	freq[c]++;
        }
        else
        	freq[c] = 1;
    }

    //Construct the forest
    node *ptr;
	for(auto it = freq.begin(); it != freq.end(); it++){
		ptr = new node;
		ptr->character = it->first;
		ptr->freq = it->second;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		forest.push_back(ptr);
		Alphabets.push_back(ptr);
	}

	//Use the forest to construct the huffman tree
	for(int i = 0; i < freq.size() - 1; i++){
		sort(forest.begin(), forest.end(), comp1);
		ptr = new node;
		ptr->freq = (forest[0]->freq) + (forest[1]->freq);
		ptr->lchild = forest[0];
		ptr->rchild = forest[1];
		forest.pop_front();
		forest.pop_front();
		forest.push_back(ptr);
	}


	char code[100000];	//huffman code
	ptr = forest.front();	//root
	getHuffmanCode(ptr, code, 0);	

	//encoding output
	vector<char> Encoding_result;
	cout << "Encoding result: ";
	for(int i = 0; i < input_length; i++){
		for(int j = 0; j < Alphabets.size(); j++){
			if(input[i] == Alphabets[j]->character){
				for(int k = 0; k < Alphabets[j]->length; k++){
					Encoding_result.push_back(Alphabets[j]->HuffmanCode[k]);
				}
				break;
			}
		}
	}
	for(int i = 0; i < Encoding_result.size(); i++){
		cout << Encoding_result[i];
	}
	cout << '\n';

	//code_list output
	int WPL = 0;
	sort(Alphabets.begin(), Alphabets.end(), comp2);	//output by order
	cout << "code list{" << '\n';
	for(int i = 0; i < Alphabets.size(); i++){
		cout << '\t' << Alphabets[i]->character << ":";
		for(int j = 0; j < Alphabets[i]->length; j++){		
			cout << Alphabets[i]->HuffmanCode[j];
		}	
		cout << '\n';
		WPL += (Alphabets[i]->length) * (Alphabets[i]->freq);
	}
	cout << '}' << '\n';
	cout << "WPL: " << WPL << '\n';

	//Decoding result
	cout << "Decoding_result: ";
	vector<char> Decoding_result, tmp;
	bool do_break = 0;
	// cout << Encoding_result.size() << '\n';
	for(int i = 0; i < Encoding_result.size(); i++){
		tmp.push_back(Encoding_result[i]);
		for(int j = 0; j < Alphabets.size(); j++){
			if(tmp.size() == Alphabets[j]->length){
				for(int k = 0; k < tmp.size(); k++){
					if(tmp[k] != Alphabets[j]->HuffmanCode[k]){
						break;
					}
					if(k == tmp.size() - 1){
						Decoding_result.push_back(Alphabets[j]->character);
						tmp.clear();
						break;
					}
				}
			}

		}
		
	}
	// cout << Decoding_result.size() << '\n';
	for(int i = 0; i < Decoding_result.size(); i++){
		cout << Decoding_result[i];
	}
	cout << '\n';
	
	return 0;
}
