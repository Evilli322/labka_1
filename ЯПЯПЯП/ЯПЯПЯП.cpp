#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include<filesystem>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	vector <string> logs;
	string result;
	string d_name;
	
	cout << "ВВЕДИТЕ ИМЯ ДЕВАЙСА:" << " ";
	cin >> d_name;
	if (cin.fail())//контроль правильности ввода
	{	
		std::cout << "ОШИБКА ВВОДА!!!";	
		return 0;
	}
	cout << endl << "\tДАТА:\t\tРЕЗУЛЬТАТ:" << endl;

	for (auto& p : experimental::filesystem::directory_iterator("C:/Users/Evilli322/Desktop/logs"))
	{
		logs.push_back(p.path().string());
	}
		for (int i = 0; i < logs.size(); i++) // возвращает длину строки
		{
			auto path = logs[i];
			auto file = fstream(path);
			string filek;
			
			while (!file.eof())
			{
				auto res = filek.find(':');
				string name_result = filek.substr(res + 1, filek.size() - res - 1);//позиция после секунды и двоеточия
				res = name_result.find(':');
				string dev_name = name_result.substr(0, res);//имя девайса без двоеточий
				
				if(d_name == dev_name && filek.find("garbage") == -1)
				{
					auto res = filek.find(':');
					string sec = filek.substr(0, res);
				
					res = name_result.find(':');
					string result = name_result.substr(res + 1, filek.size() - res - 1);//позиция после девайса и двоеточия
					
					auto d = path.find('(');
					auto b = path.find(')');
					string date = path.substr(d + 1, b - d - 1);

					cout << date << ":0";
					cout << sec << "\t" << result << endl;
				}
				filek = "";
				getline(file, filek);				
			}
			file.close();
		}
}
