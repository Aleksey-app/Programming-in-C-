// ПрактическаяРабота№4.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void Removing(char *strs) {
	int t = 0;
	string str = string(strs);

	for (int i = 0; i < size(str); i++) { // удаление повторных символов
		t = 0;
		for (int j = 0; j < size(str); j++) {
			if (!isalpha((unsigned char)str[j])) {
				if (str[j] == str[j + 1]) {
					if (str[j] == '.') {
						t++;
						if (t >= 3)
							str.erase(j, 1);
					}
					else
						str.erase(j, 1);

				}
			}
		}
	}
	strcpy(strs, str.c_str());

	cout << str << endl << endl;
	setlocale(0, "RU");
}

void Register(char * str) {
	for (int i = 2; i < strlen(str); i++) // выравниваем регистр
	{
		str[0] = toupper(str[0]);

		if (str[i - 2] == '.' || str[i - 1] == '.' || str[i - 2] == '?' || str[i - 1] == '?') {
			str[i] = toupper(str[i]);
		}
		else {
			if (str[i - 1] != ' ')
				str[i] = tolower(str[i]);
			else
				str[i] = str[i];
		}
	}
	cout << str << endl << endl;
	setlocale(0, "RU");
}

void Task(char pch[500]) {				// знаю криво получилось только так прошу при оценке написать свой прмер
	char *pchh = new char(500);
	pchh = strtok(pch, " ,.-");			// самая большая проблемма в этойй строчке
	while (pchh != NULL) // пока есть лексемы
	{
		string str = string(pchh);
		for (int i = 1; i < size(str); i++) {
			if (str[0] == str[i])
				cout << pchh << "\n";
		}
		pchh = strtok(NULL, " ,.-)*");
	}
	cout << endl;
	setlocale(0, "RU");
}

void Number(char *ku)
{
	string kuk = string(ku);

	for (int i = 0; i < size(kuk); i++) {
		replace(kuk.begin(), kuk.end(), '1', 'a');
		replace(kuk.begin(), kuk.end(), '2', 'b');
		replace(kuk.begin(), kuk.end(), '3', 'c');
		replace(kuk.begin(), kuk.end(), '4', 'd');
		replace(kuk.begin(), kuk.end(), '5', 'e');
		replace(kuk.begin(), kuk.end(), '6', 'f');
		replace(kuk.begin(), kuk.end(), '7', 'g');
		replace(kuk.begin(), kuk.end(), '8', 'h');
		replace(kuk.begin(), kuk.end(), '9', 'i');
		replace(kuk.begin(), kuk.end(), '0', 'z');
	}
	cout << kuk << endl << endl;
	setlocale(0, "RU");
}

bool ReadFile(const char *FileName)
{
	char yes[500];
	char copy[500];
	char *S;

	ifstream File;
	File.open(FileName);

	if (!File.is_open())  //  Проверили удалось ли открыть файл
	{
		cout << "Открыть файл не удалось! \n";
		return 0;
	}

	while (!File.eof()) // Читаем все строки из файла и выводим их на экран
		File.getline(yes, 500);
	S = yes;
	cout << "Original:\n" << S << endl << endl;
	cout << "\n###***@@@***###\n";

	cout << "\nУдаление лишних знаков\n";
	Removing(S); // удаление повторных символов
	cout << "\n###***@@@***###\n";

	cout << "\nИсправление регистра букв\n";
	Register(S); // выравниваем регистр
	cout << "\n###***@@@***###\n";

	cout << "\nЗадание 3 вариант 5\n";
	strcpy(copy, S);
	Task(copy); // выводим слова, в которых есть буквы такие же как и первая буква слова
	cout << "\n###***@@@***###\n";

	cout << "\nЗадание 4 вариант 4\n";
	Number(S);
	cout << "\n GAME OVER\n";

	File.close();  // Закрываем файл
	return 1;
}

void WriteText() {
	cin.get();

	char yes[500];
	char copy[500];
	char *S;

	cout << "Введите текст содержащий от 1 до 50 слов, в каждом из которых от 1 до 10 строчных латинских букв и цифр. Между соседними словами произвольное количество пробелов. За последним символом стоит точка. \n";
	cin.getline(yes, 500);

	S = yes;
	cout << "\n###***@@@***###\n";

	cout << "\nУдаление лишних знаков\n";
	setlocale(0, ".866");
	Removing(S); // удаление повторных символов
	cout << "\n###***@@@***###\n";

	cout << "\nИсправление регистра букв\n";
	setlocale(0, ".866");
	Register(S); // выравниваем регистр
	cout << "\n###***@@@***###\n";

	cout << "\nЗадание 3 вариант 5\n";
	strcpy(copy, S);
	setlocale(0, ".866");
	Task(copy); // выводим слова, в которых есть буквы такие же как и первая буква слова
	cout << "\n###***@@@***###\n";

	cout << "\nЗадание 4 вариант 4\n";
	setlocale(0, ".866");
	Number(S);
	cout << "\n GAME OVER\n";
}

int main()
{
	setlocale(0, "RU");

	int vibor;
	cout << "Selecting a line of text:\n1 - Manual input\n2 - File\n";
	cin >> vibor;

	if (vibor == 1) {
		WriteText();
	}
	else if (vibor == 2) {
		ReadFile("text.txt");
	}

	system("pause");

	return 0;
}
