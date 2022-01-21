#include<iostream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
using namespace std;

#define tab "\t"

const map<int, string>& crimes =
{
	pair<int, string>(1, "���������� ��������"),
	pair<int, string>(2, "������ �� �������"),
	pair<int, string>(3, "�������� � �� ���������� �����"),
	pair<int, string>(4, "����������� �������"),
	pair<int, string>(5, "����������� �������� �����")
};

class Crime
{
	string crime;
	string place;
public:
	const string& get_crime()const
	{
		return crime;
	}
	const string& get_place()const
	{
		return place;
	}
	Crime()
	{

	}
	Crime(const string& crime, const string& place)
	{
		this->crime = crime;
		this->place = place;
	}
	~Crime()
	{

	}
	ostream& print(ostream& os)const
	{
		return os << crime << " " << place;
	}
	istream& scan(istream& is)
	{
		is.ignore(); //���������� 1 ������ �� ������ ����� (� ������ ������ '\n').
		getline(is, crime, ',');
		getline(is, place, '.');
		return is;
	}
};

ostream& operator<<(ostream& os, const Crime& obj)
{
	return obj.print(os);
}
istream& operator>>(istream& is, Crime& obj)
{
	return obj.scan(is);
}

void print(const map<string, list<Crime>>& base);

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, list<Crime>> base =
	{
		pair<string, list<Crime>>("m777ko", list<Crime>{Crime("���������� ��������", "����� ������"), Crime("������ �� �������", "����� �����������")}),
		pair<string, list<Crime>>("b510ma", list<Crime>{Crime("�������� � ������������ �����", "�� �������")}),
		pair<string, list<Crime>>("a213bb", list<Crime>{Crime("����������� �������", "������� �������")})
	};
	
	/*for (list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it << endl;
	}*/

	string licence_place;
	Crime crime;
	cout << "������� ����� ����������: "; cin >> licence_place;
	cout << "������� ��������������: "; cin >> crime;
	base[licence_place].push_back(crime);
	print(base);
}

void print(const map<string, list<Crime>>& base)
{
	for (map<string, list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first << ":\n";
		for (list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); ++l_it)
		{
			cout << *l_it << endl;
		}
	}
}