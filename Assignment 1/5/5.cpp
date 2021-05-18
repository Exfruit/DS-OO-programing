#include <iostream>
using namespace std;

class Quadratic
{
public:
	Quadratic(){}
	Quadratic(int a1, int a2, int a3) : a(a1), b(a2), c(a3){}
	Quadratic operator+(const Quadratic& g){
		Quadratic temp;
		temp.a = this->a + g.a;
		temp.b = this->b + g.b;
		temp.c = this->c + g.c;

		return temp;
	}
	void print_poly(){
		cout << "(" << a << "x^2) + " << "(" << b << "x) + " << "(" << c << ")" << '\n';
	}
private:
	int a;
	int b;
	int c;
	
};
int main(int argc, char const *argv[])
{
	Quadratic f1(1, 2, 3), f2(4, 5, 6), f3;
	f3 = f1 + f2;
	f3.print_poly();

	return 0;
}