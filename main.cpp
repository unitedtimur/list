#include "List.h"
#include "Node.h"

int main()
{
	list t1;
	list t2(3, 3, 2, 1);
	list t3(t2);

	cout << t2 << endl << t1 << endl << t3 << endl;

	t3.clear();

	t3.set(3);

	cout << "Set1: " << t3 << endl;

	t3.clear();

	int arr[5]{ 1, 2, 3, 4, 5 };

	t3.set(arr, 5);

	cout << "Set2: " << t3 << endl;

	t3.clear();

	t3.set("test.dat");

	cout << "Set3: " << t3 << endl;

	t3.push_front(35);

	cout << "Push Front: " << t3 << endl;

	t3.push_back(45);

	cout << "Push Back: " << t3 << endl;

	t3.push_index(1, 1252155);

	cout << "Push Index: " << t3 << endl;

	t3.push_key(666, 75987);

	cout << "Push Key: " << t3 << endl;

	t3.pop_front();

	cout << "Pop front: " << t3 << endl;

	t3.pop_back();

	cout << "Pop back: " << t3 << endl;

	t3.pop_key(75987);

	cout << "Pop key: " << t3 << endl;

	t3.pop_index(0);

	cout << "Pop index: " << t3 << endl;

	t3.find(1).set_value(12412);

	cout << "Find: " << t3 << endl;

	t3.copy();

	cout << "Copy: " << t3 << endl;

	cout << "Size: " << t3.size() << endl;

	t3.add(4, 125215, 547754, 967967, -125215);

	cout << "Add: " << t3 << endl;

	t3.del(3, 125215, 547754, -125215);

	cout << "Del: " << t3 << endl;

	t2.set(10, 24);

	t3 = t2;

	cout << "Operator=: " << t3 << endl;

	t1.set("test.dat");

	t3 += t1;
	
	cout << "Operator+=: " << t3 << endl;

	t3 -= t1;

	cout << "Operator-=: " << t3 << endl;

	t3[5].set_value(666666);

	cout << "Operator[]: " << t3 << endl;

	t3 = t2 + t3;

	cout << "Operator+: " << t3 << endl;

	t3 = t3 - t2;

	cout << "Operator-: " << t3 << endl;

	system("pause");
	return 0;
}