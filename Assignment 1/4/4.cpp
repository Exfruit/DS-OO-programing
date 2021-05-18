#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int i = 0, int r = 0) : inumber(i), rnumber(r){}
	void print_number(){
		cout << rnumber << " + " << "(" << inumber << "i)" << '\n';
	}

private:
	int inumber;
	int rnumber;
};
int main(int argc, char const *argv[])
{
	Complex num;
	num.print_number();
	return 0;
}