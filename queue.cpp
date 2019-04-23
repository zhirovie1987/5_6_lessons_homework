#include <iostream>

using namespace std;

struct my_queue {
	int16_t data[10];
	int16_t *head = begin (data);
	int16_t *tail = end(data);
};

bool Add (my_queue *q, int16_t d) {
	
	if (q->tail > q->head) {
		
		*q->tail = d;
		q->tail--;
		
		return true;
	}
	else {
		//tail = end(data) - 1;
		return false;
	}
}

bool Get (my_queue *q, int16_t &d) {
	if (q->tail <= end(q->data)) {
		q->tail++;
		d = *q->tail;
		return true;
	}
	else {
		d = 0;
		return false;
	}	
}

size_t Get_Size (my_queue *q) {
	return end(q->data)- q->tail;
}

int main () {
	int16_t data = 0;
	my_queue simple_queue;
	for (auto i = 0; i < 11; i++) {
		Add (&simple_queue, i);
	}

	for (auto i = 0; i < 7; i++) {
		Get (&simple_queue, data);
		cout<<data<<endl;
	}

cout<<endl<<Get_Size(&simple_queue);
	return 0;
}
