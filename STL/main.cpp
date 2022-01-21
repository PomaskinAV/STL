#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
using namespace std;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define STL_VECTOR_ERASE
//#define STL_VECTOR_INSERT2
//#define STL_VECTOR_INSERT3
//#define STL_VECTOR_ERASE2
//#define STL_DEQUE
//#define STL_LIST_INSERT
//#define STL_LIST_ERASE
#define FORWARD_LIST

template<typename T>void print(const vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector  - это последовательный контейнер, который хранит данные в виде динамического массива
	vector<int> vec={0,1,1,2,3,5,8,13,21,34,55,89,144,232};
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
	//int* data = vec.data();
	vec.push_back(55);
	//data = vec.data();
	vec.push_back(89);
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << tab;
			//cout << *(data + i) << tab;
			//cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //есть только у вектора
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
#endif // STL_VECTOR
	
#ifdef STL_VECTOR_INSERT
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	int index;
	int value;
	do
	{
		cout << "Введите индекс добавляемого значения: "; cin >> index;
		if (index > vec.size())cout << "Введите другое значение\n";
	} while (index > vec.size());
	cout << "Введите добавляемое значение: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, value);
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
#endif // STL_VECTOR_INSERT

#ifdef STL_VECTOR_ERASE
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	int index;
	do
	{
		cout << "Введите индекс удаляемого значения: "; cin >> index;
		if (index > vec.size())cout << "Введите другое значение\n";
	} while (index >= vec.size());
	vec.erase(vec.begin() + index);
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
#endif // STL_VECTOR_ERASE

#ifdef STL_VECTOR_INSERT2
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range" << endl;
	print(vec);
#endif // STL_VECTOR_INSERT2

#ifdef STL_VECTOR_INSERT3
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	int index;
	int value;
	int count;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	if (index < vec.size())vec.insert(vec.begin() + index, count, value);
	else cout << "Error: out of range" << endl;
	print(vec);

	std::vector<int> powers = { 1024, 2048, 4096, 8192, 16384 };

	//vec.insert(vec.begin() + 3, powers.begin(), powers.end());
	vec.insert(vec.begin() + 8, { 256, 384, 512, 768 });
	for (int i : vec)cout << i << tab; cout << endl;

	/*vec.insert(vec.begin() + 4, vec.begin()+15, vec.begin()+17);
	for (int i : vec)cout << i << tab; cout << endl;*/
#endif // STL_VECTOR_INSERT3

#ifdef STL_VECTOR_ERASE2
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	int index;
	int value;
	int count;

	cout << "Введите индекс удобавляемого элемента: "; cin >> index;
	cout << "Введите количество удобавлений: "; cin >> count;
	vec.erase(vec.begin() + index, vec.begin() + index + count);
	print(vec);

	std::vector<int> powers = { 1024, 2048, 4096, 8192, 16384 };

	vec.swap(powers);
	print(vec);
	print(powers);
#endif // STL_VECTOR_ERASE2

#ifdef STL_DEQUE
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(79);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << tab;
	}
	cout << endl;

	std::deque<int> d_powers = { 256,512,768 };
	//deque.push_back(*d_powers.begin() + 1);
	for (int i : deque)cout << i << tab; cout << endl;
	for (int i : d_powers)cout << i << tab; cout << endl;
#endif // STL_DEQUE

#ifdef STL_LIST_INSERT
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	int index;
	int value;
	int count;
	do
	{
		cout << "Введите индекс добавляемого значения: "; cin >> index;
		if (index > list.size())cout << "Введите другое значение\n";
	} while (index > list.size());
	cout << "Введите количество добавлений: "; cin >> count;
	cout << "Введите добавляемое значение: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.insert(position, count, value);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST_INSERT

#ifdef STL_LIST_ERASE
	std::list<int> list = { 3,5,8,13,21 };
	for (int i : list)cout << i << tab; cout << endl;
	int index;
	do
	{
		cout << "Введите индекс удаляемого значения: "; cin >> index;
		if (index >= list.size())cout << "Введите другое значение\n";
	} while (index >= list.size());
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.erase(position);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_LIST_ERASE

#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };
	list.push_front(123);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	list.reverse();
	list.push_front(1024);
	for (int i : list)cout << i << tab; cout << endl;

	std::list<int> list2;

	cout << "ForwardList max size:\t" << list.max_size() << endl;
	cout << "List max size:\t\t" << list2.max_size() << endl;

#endif // FORWARD_LIST

}