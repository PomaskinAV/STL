#include<iostream>
#include<conio.h>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include<fstream>
using namespace std;

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
	string& get_place()
	{
		return place;
	}
	Crime(){}
	Crime(int crime_id, const string& place)
	{
		this->crime_id = crime_id;
		this->place = place;
	}
	~Crime()
	{

	}
	ostream& print(ostream& os)const
	{
		return os << crimes.at(crime_id) << ", " << place;
	}
	ofstream& print(ofstream& os)const
	{
		os << crime_id /*<< " "*/ << place;
		return os;
	}
	istream& scan(istream& is)
	{
		is.ignore(); //Игнорирует 1 символ из буфера ввода (в данном случае '\n').
		//getline(is, crime_id, ',');
		cin >> crime_id;
		getline(is, place);
		return is;
	}
	ifstream& scan(ifstream& is)
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
ofstream& operator<<(ofstream& os, const Crime& obj)
{
	return obj.print(os);
}
istream& operator>>(istream& is, Crime& obj)
{
	return obj.scan(is);
}

void print(const map<string, list<Crime>>& base);
void save(const map<string, list<Crime>>& base);
void load(map<string, list<Crime>>& base);

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, list<Crime>> base /*=
	{
		pair<string, list<Crime>>("m777ko", list<Crime>{Crime(1, "Улица Ленина"), Crime(2, "Улица Октябрьская")}),
		pair<string, list<Crime>>("b510ma", list<Crime>{Crime(3, "ТЦ Экватор")}),
		pair<string, list<Crime>>("a213bb", list<Crime>{Crime(4, "Красная площадь")})
	}*/;
	
	//load(base);

	/*for (list<Crime>::iterator it = base["m777ko"].begin(); it != base["m777ko"].end(); ++it)
	{
		cout << *it << endl;
	}*/

	/*string licence_place;
	Crime crime;
	cout << "Введите номер автомобиля: "; cin >> licence_place;
	cout << "Введите правонарушение: "; cin >> crime;
	base[licence_place].push_back(crime);*/
	//print(base);
	//save(base);

	int action;
	do
	{
		system("CLS");
		cout << "Выберите действие: " << endl;
		cout << "1. Загрузить базу: " << endl;
		cout << "2. Сохранить базу: " << endl;
		cout << "3. Вывести базу: " << endl;
		cout << "4. Добавить запись: " << endl;
		action = _getch();
		cout << action << endl;
		switch (action)
		{
		case '1': load(base); break;
		case '2': save(base); break;
		case '3': print(base); break;
		case '4':
		{
			string licence_place;
			Crime crime;
			cout << "Введите номер автомобиля: "; cin >> licence_place;
			cout << "Введите правонарушение: "; cin >> crime;
			base[licence_place].push_back(crime);
		}
		break;
		}
		//_getch();
		system("PAUSE");
	} while (action != 27);
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

void save(const map<string, list<Crime>>& base)
{
	ofstream fout("base.txt");
	for (map<string, list<Crime>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		fout << it->first << ":";
		for (list<Crime>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			fout << *l_it << ", ";
		}
		fout.seekp(-2, ios_base::cur);
		fout << ";\n";
	}
	fout.close();
	system("start notepad base.txt");
}

void load(map<string, list<Crime>>& base)
{
	ifstream fin("base.txt");
	if (fin.is_open())
	{
		string key;
		string value;
		while (!fin.eof())
		{
			getline(fin, key, ':');
			base[key];
			getline(fin, value);
			if (value.find(',') == string::npos)
			{
				base[key].push_back(Crime(stoi(value), value));
				base[key].back().get_place().erase(0, 1);
			}
			else
			{
				char* all_crimes = new char[value.size() + 1];
				strcpy(all_crimes, value.c_str());
				for (char* pch = strtok(all_crimes, ",;"); pch; pch = strtok(NULL, ",;"))
				{
					int crime_id = atoi(pch);
					while(*pch == ' ')pch++;
					base[key].push_back(Crime(crime_id, pch+1));
				}
			}
				/*for (size_t start = -1, end = 0; value.find(',', start+1) != string::npos; start = end)
			{
				end = value.find(',', start + 1);
				string buffer = value.substr(start+1, end - start);
				if(buffer.find_first_not_of(' ')!=string::npos)
					buffer.erase(0, buffer.find_first_not_of(' '));
				int crime_id = stoi(buffer);
				buffer.erase(0, 1);
				base[key].push_back(Crime(crime_id, buffer));
			}*/
		}
		fin.close();
	}
	else
	{
		cerr << "Error: file not found!" << endl;
	}
}