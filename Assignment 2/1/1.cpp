#include <iostream>
using namespace std;

template <class T>
struct QueueNode{
	T data;
	QueueNode *next;
	QueueNode():data(0), next(NULL){};
	QueueNode(T d):data(d), next(NULL){};
};
template <class T>
class LinkedQueue{
private:
	QueueNode<T> *front;
	QueueNode<T> *back;
	int size;
public:
	LinkedQueue():front(NULL), back(NULL), size(0){};
	bool IsEmpty(){
		return size == 0;
	}
	void push(T val){
		if(IsEmpty() == true){
			front = new QueueNode<T>(val);
			back = front;
			size++;
			return;
		}
		QueueNode<T> *tmp = new QueueNode<T>(val);
		back->next = tmp;
		back = tmp;
		size++;
	}
	void pop(){
		if(IsEmpty() == true){
			cout << "No element in the Queue" << '\n';
			return;
		}
		QueueNode<T> *tmp = front;
		front = front->next;
		delete tmp;
		size--;
		if(IsEmpty() == true){
			cout << "The queue is now Empty" << '\n';
		}
	}
	T getfront(){
		if(IsEmpty() == true){
			cout << "No element in the Queue" << '\n';
			return -1;
		}
		return front->data;
	}
	T getback(){
		if(IsEmpty() == true){
			cout << "No element in the Queue" << '\n';
			return -1;
		}
		return back->data;
	}
	int getsize(){
		return size;
	}
};
int main(int argc, char const *argv[])
{
	LinkedQueue<char> q;
    for(int i = 0; i < 10; i++){
    	q.push('A' + i);
    }
    for(int i = 0, j = 10; i < 10; i++, j++){
    	cout << "Front is: " << q.getfront() << ", Back is: " << q.getback() << '\n';
    	q.push('A' + j);
    	q.pop();
    }
    // cout << "Front is: " << q.getfront() << ", Back is: " << q.getback() << '\n';
	return 0;
}