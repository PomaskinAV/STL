#include<iostream>
#include<array>
#include<vector>
using namespace std;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_VECTOR_INSERT

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
	//vector  - ��� ���������������� ���������, ������� ������ ������ � ���� ������������� �������
	vector<int> vec={0,1,1,2,3,5,8,13,21,34,55,89,144,232};
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl; //���� ������ � �������
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
	cout << "Capacity: " << vec.capacity() << endl; //���� ������ � �������
	cout << "MaxSize:  " << vec.max_size() << endl;
	cout << sizeof(vec) << endl;
#endif // STL_VECTOR
	
#ifdef STL_VECTOR_INSERT
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34,55,89,144,232 };
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	int index;
	int value;
	do
	{
		cout << "������� ������ ������������ ��������: "; cin >> index;
		if (index > vec.size())cout << "������� ������ ��������\n";
	} while (index > vec.size());
	cout << "������� ����������� ��������: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, value);
	for (int i : vec)
		cout << i << tab;
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
#endif // STL_VECTOR_INSERT

}