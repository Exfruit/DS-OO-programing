/*input
5
3
6
7
8
*/

#include <iostream>
using namespace std;
#define MAX 1000

template <class T>
class Bag
{ 
public:
	

	Bag(int s = 0){
		size = s;
		array = new T[MAX];
	}
	void init(){
		size = 0;
		array = new T[MAX];
	}
	void set_size(int i){
		size = i;
	}
	int get_size(){
		return size;
	}
	void size_increase(){
		size++;
	}
	void size_decrease(){
		size--;
	}
	void set_value(T val, int idx){
		array[idx] = val;
	}
	T get_value(int idx){
		return array[idx];
	}
	T operator[](T idx) {
        return array[idx];
    }
protected:
	T* array;
	int size;

};

template <class T>
class Queue : public Bag<T>
{
public:
	Queue(){
		this->init();
	}
	void push_back(T val){
		this->set_value(val, this->get_size());
		this->size_increase();
	}
	void pop_back(){
		for(int i = 0; i < this->get_size() - 1; i++){
			this->set_value(this->get_value(i + 1), i);
		}
		this->set_value(0, this->get_size() - 1);
		this->size_decrease();
	}

};

int main(int argc, char const *argv[])
{
	Bag<int> b;
	for(int i = 0; i < 5; i++){
		int temp;
		cin >> temp;
		b.set_value(temp, i);
	}
	for(int i = 0; i < 5; i++){
		cout << b[i] << ' ';
	}
	cout << '\n';
	Queue<int> q;
	for(int i = 0; i < 5; i++){
		q.push_back(b[i]);
	}
	cout << "size : " << q.get_size() << '\n';
	for(int i = 0; i < 5; i++){
		cout << q[i] << ' ';
	}
	cout << '\n';
	for(int i = 4; i >= 0; i--){
		q.pop_back();
		cout << "size : " << q.get_size() << '\n';
		for(int j = 0; j < i; j++){
			cout << q[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
