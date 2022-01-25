#include<iostream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<fstream>
using namespace std;

#define tab "\t"

const map<int, string>& crimes =
{
	pair<int, string>(1, "Превышение скорости"),
	pair<int, string>(2, "Проезд на красный"),
	pair<int, string>(3, "Парковка в не положенном месте"),
	pair<int, string>(4, "Оскорбление офицера"),
	pair<int, string>(5, "Пересечение сплошной линии")
};

class Crime
{
	int crime_id;
	string place;
public:
	int get_crime()const
	{
		return crime_id;
	}
	const string& get_place()const
	{
		return place;
	}
	Crime()
	{

	}
	Crime(int crime, const string& place)
	{
		this->crime_id = crime;
		this->place = place;
	}
	~Crime()
	{

	}
	ostream& print(ostream& os)const
	{
		return os << crimes.at(crime_id) << " " << place;
	}
	istream& scan(istream& is)
	{
		is.ignore(); //Игнорирует 1 символ из буфера ввода (в данном случае '\n').
		//getline(is, crime_id, ',');
		cin >> crime_id;
		getline(is, place);
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

const string base_name = "base.txt";

void save_base(const map<string, list<Crime>>& base);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, list<Crime>> base =
	{
		pair<string, list<Crime>>("m777ko", list<Crime>{Crime(1, "Улица Ленина"), Crime(2, "Улица Октябрьская")}),
		pair<string, list<Crime>>("b510ma", list<Crime>{Crime(3, "ТЦ Экватор")}),
		pair<string, list<Crime>>("a213bb", list<Crime>{Crime(4, "Красная площадь")})
	};
	
	/*for (list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it << endl;
	}*/

	string licence_place;
	Crime crime;
	cout << "Введите номер автомобиля: "; cin >> licence_place;
	cout << "Введите правонарушение: "; cin >> crime;
	base[licence_place].push_back(crime);
	print(base);
	save_base(base);
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

void save_base(const map<string, list<Crime>>& base)
{
	ofstream fout(base_name);
	for (map<string, list<Crime>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		fout << it->first << ":";
		for (list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			fout << *l_it;
			if (l_it != --(it->second.end()))fout << ",";
		}
		fout << ";\n";
	}
	fout.close();
	string command = "start notepad " + base_name;
	system(command.c_str());
}