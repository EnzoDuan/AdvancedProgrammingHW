#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList<int> * A = new LinkedList<int>();
	/* Insert number form head. */
	for (int i = 0; i < 5; i++)
		A->insertToHead(i);
	/* Insert number from tail.*/
	for (int i = 10; i > 5; i--)
		A->insertToTail(i);
	/* Print all 10 numbers to check rhe two functions. */
	A->print();

	/* Delete number from head. */
	int _first = A->deleteFromHead();
	cout << "The first number is : " << _first << endl;
	A->print();
	/* Delete number from tail. */
	int _last = A->deleteFromTail();
	cout << "The last number is : " << _last << endl;
	A->print();

	return 0;
}