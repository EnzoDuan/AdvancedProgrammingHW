#include "Queue.h"
using namespace std;

int main() {
	Queue<int> *A = new Queue<int>();
	/* Enqueue */
	for (int i = 0; i < 5; i++)
		A->enqueue(i);
	/* Dequeue */
	while (!A->isEmpty()) {
		int ans = A->dequeue();
		cout << ans << " ";
	}
	cout << endl;

	return 0;
}