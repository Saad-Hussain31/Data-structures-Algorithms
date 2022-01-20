#include <iostream>
using std::cout; using std::cin; using std::endl;

int sum(int n) 
{
	if( n == 1)
		return 1;
	return (n + sum(n-1));
}

int main() 
{	int x;
	cin  >> x;
	cout << "sum of first " << x <<  " number is " << sum(x) << endl;
}
