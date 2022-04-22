// Практическая Работа №3.cpp 

#include <iostream>
#include <string> //отличная библиотека работы со строками
#include <windows.h> // разобрался это библиотека подключает функционал ОС Windows
#include <fstream> // читать и писать файлы
using namespace std;

struct stck // структура стека на основе односвязного списка
{
	char y;
	stck *next;
} *sip;
int menu(int xz) {
	int qwe = 0;
	HANDLE O = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(O, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n#####*****@@@@@*****#####\n";
	cout << "\n ОСНОВНОЕ МЕНЮ\n";
	SetConsoleTextAttribute(O, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "1. Преобразование введенного с клавиатуры выражения и вычисления результата.\n";
	cout << "2. Преобразование из файла (prakt3.txt) выражения и вычисления результата.\n";
	cout << "3. Генерирует несколько (на выбор пользователя) вариантов по польской натации (прямой <префиксная запись> и обратной <постфиксная запись>).\n";
	cout << "4. Выход \n";
	while (true)
	{
		cout << "Выберите необходимые действия:" << endl;
		cin >> qwe;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (qwe <= 0)
		{
			cout << " Значение должно быть положительным" << endl;
			continue;
		}
		if (qwe > 4)
		{
			cout << " Возможное значение <В диапозоне от 1-4>" << endl;
			continue;
		}
		else break;
	}
	system("cls");
	return qwe;
}
int znac(char a) // приоритет операций
{
	switch (a)
	{
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(':return 1;
	}
	return 0;
}
stck *inSpi(stck *q, char out) // входящий стек лексем
{
	stck *z = new stck;
	z->y = out;
	z->next = q;
	return z;
}
stck *outSpi(stck *q, char& x) 
{
	stck *z = q;
	x = q->y;
	q = q->next;
	delete z;
	return q;
}
double shet(char *str) // имитация стека опрераций 
{
	int i;
	char ss, ss1, ss2, ss3 = 'z' + 1;
	double aa1, aa2, res = 0, mas[200];
	cout << " Введите значение переменных" << endl;
	for (i = 0; str[i] != '\0'; ++i)
	{
		ss = str[i];
		if (ss >= 'a' && ss <= 'z')
		{
			while (str[i] != '\0')
			{
				cout << ss << " = ";
				cin >> mas[int(ss)];
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cout << "Ввидите числовое значение <в диапозоне от -543 до 345>" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (mas[int(ss)] > 345 || mas[int(ss)] < -543)
				{
					cout << "Ввидите числовое значение <в диапозоне от -543 до 345>" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				else break;
			}
		}
	}
	for (i = 0; str[i] != '\0'; ++i)
	{
		ss = str[i];
		if (!(ss == '+' || ss == '-' || ss == '*' || ss == '/'))
		{
			sip = inSpi(sip, ss);
		}
		else
		{
			sip = outSpi(sip, ss2);
			sip = outSpi(sip, ss1);
			aa2 = mas[int(ss2)];
			aa1 = mas[int(ss1)];
			switch (ss)
			{
			case '+':res = aa1 + aa2; break;
			case '-':res = aa1 - aa2; break;
			case '*':res = aa1 * aa2; break;
			case '/':res = aa1 / aa2; break;
			}
			mas[int(ss3)] = res;
			sip = inSpi(sip, ss3);
			ss3++;
		}
	}
	return res;
}
int shetSt(int strok) //функция подсчёта строк 
{
	ifstream file("prakt3.txt");
	if (!file)
	{
		cout << " Error!!! \n";
	}
	else
	{
		while (true)
		{
			string v;
			getline(file, v);
			if (!file.eof())
				strok++;
			else
				break;
		}
		cin.get();
	}
	file.close();
	return strok;
}

char proverka()
{
	char zu;
	cin >> zu;
	if (zu >= 'a'&& zu <= 'z')
	{
		return zu;
		return proverka();
	}
	if (zu == '(' || zu == ')')
	{
		return zu;
	}
	if (zu == '+' || zu == '-' || zu == '*' || zu == '/')
	{
		return zu, proverka();
	}
	else
	{
		cout << "Ошибка ввода!" << endl;
		return 0;
	}
	return '\0';
}

int main()
{
	int xz = 0;
	setlocale(LC_ALL, "Russian");
	int lab = menu(xz);
	if (lab == 1) {
		cout << "1. Преобразование введенного с клавиатуры выражения и вычисления результата.\n";
		cout << "####@@@@!!!!$$$$Prakt3SemII%%%%^^^^&&&&****~~~~" << endl;
		cout << " Ввидите формулу в инфиксной форме используя переменные формат <a+c/d>: ";
		cout << " Ввидите формулу в инфиксной форме используя буквенные <a-z> прееменные: " << endl;
		cout << " Формата a*f-r/d+c" << endl;
		cout << " Или формата (a+b*c)/(d-f)" << endl;
		stck *zu, *tmp = NULL;
		char a;
		char in[41], out[41];
		int ind = 0, i = 0;
		cin >> in;
		while (in[ind] != '\0')
		{
			if (in[ind] >= 'a'&& in[ind] <= 'z')
			{
				out[i++] = in[ind];
			}
			if (in[ind] == '(')
			{
				tmp = inSpi(tmp, in[ind]);
			}
			if (in[ind] == ')')
			{
				while ((tmp->y) != '(')
				{
					tmp = outSpi(tmp, a);
					out[i++] = a;
					if (!tmp)
					{
						a = '\0';
						out[i++] = a;
					}
				}
				zu = tmp;
				tmp = tmp->next;
				delete zu;
			}
			if (in[ind] == '+' || in[ind] == '-' || in[ind] == '*' || in[ind] == '/')
			{
				while (tmp != NULL && znac(tmp->y) >= znac(in[ind]))
				{
					tmp = outSpi(tmp, a);
					out[i++] = a;
				}
				tmp = inSpi(tmp, in[ind]);
			}
			ind++;
		}
		while (tmp != NULL)
		{
			tmp = outSpi(tmp, a);
			out[i++] = a;
		}
		out[i] = '\0';
		cout << " Формула в постфиксной записи = " << out << endl;
		string prefix = out;
		reverse(prefix.begin(), prefix.end());
		cout << " Формула в префиксном виде = " << prefix << endl;
		cout << " Результат вычислений = " << shet(out) << endl;
		cout << " ПОВТОРНОЕ СОСТАВЛЕНИЯ ФОРМУЛ И ВЫЧИСЛЕНИЕ РЕЗУЛЬТА ВОЗМОЖНО ТОЛЬКО ПОСЛЕ ПРЕЗАПУСКА ПРОГРАММЫ" << endl;
		cout << " Согласно заданию." << endl;
		return 0;
	}
	if (lab == 2) {
		cout << "2. Преобразование из файла (prakt3.txt) выражения и вычисления результата.\n";
		cout << "####@@@@!!!!$$$$Prakt3SemII%%%%^^^^&&&&****~~~~" << endl;
		int statist = 0, wid = 1;
		statist = shetSt(wid);
		char in[41];
		ifstream run;
		run.open("prakt3.txt");
		if (!run)
		{
			cout << " Ошибка файл не загружен или отсутствует." << endl;
			return 0;
		}
		else
		{
			cout << " Всё работает. Файл открыт." << endl;
		}
		string kid;
		while (!run.eof())
		{
			kid = "";
			getline(run, kid);
			cout << kid << endl;
		}
		int ux = 0;
		for (int i = 0; i < kid.length(); i++)
		{
			in[i] = kid[ux++];
		}
		cout << " В файле всего " << statist << " строк " << endl;
		cout << " Работаем с последней выведенной строчкой" << endl;
		run.close();
		stck *ruu, *tmp = NULL;
		char a;
		char out[41];
		int  i = 0, ind = 0;
		while (in[ind] != '\0')
		{
			if (in[ind] >= 'a'&& in[ind] <= 'z')
			{
				out[i++] = in[ind];
			}
			if (in[ind] == '(')
			{
				tmp = inSpi(tmp, in[ind]);
			}
			if (in[ind] == ')')
			{
				while ((tmp->y) != '(')
				{
					tmp = outSpi(tmp, a);
					out[i++] = a;
					if (!tmp)
					{
						a = '\0';
						out[i++] = a;
					}
				}
				ruu = tmp;
				tmp = tmp->next;
				delete ruu;
			}
			if (in[ind] == '+' || in[ind] == '-' || in[ind] == '*' || in[ind] == '/')
			{
				while (tmp != NULL && znac(tmp->y) >= znac(in[ind]))
				{
					tmp = outSpi(tmp, a);
					out[i++] = a;
				}
				tmp = inSpi(tmp, in[ind]);
			}
			ind++;
		}
		while (tmp != NULL)
		{
			tmp = outSpi(tmp, a);
			out[i++] = a;
		}
		out[i] = '\0';
		cout << " Формула в постфиксной записи = " << out << endl;
		string prefix = out;
		reverse(prefix.begin(), prefix.end());
		cout << " Формула в префиксном виде = " << prefix << endl;
		cout << " Результат вычислений = " << shet(out) << endl;
		cout << " ПОВТОРНОЕ СОСТАВЛЕНИЯ ФОРМУЛ И ВЫЧИСЛЕНИЕ РЕЗУЛЬТА ВОЗМОЖНО ТОЛЬКО ПОСЛЕ ПРЕЗАПУСКА ПРОГРАММЫ" << endl;
		cout << " Согласно заданию." << endl;
		return 0;
	}
	if (lab == 3) {
		cout << "3. Генерирует несколько (на выбор пользователя) вариантов по обратной польской натации.\n";
		cout << "####@@@@!!!!$$$$Prakt3SemII%%%%^^^^&&&&****~~~~" << endl;
		char in[41], out[41];
		int y, strok = 1, t = 0;
		t = shetSt(strok);
		while (true)
		{
			cout << "Выберите необходимое количество вариантов по польской натации:" << endl;
			cout << "ДАННЫЙ ПУНКТ МЕНЮ РАБОТАЕТ ТОЛЬКО С ПОДКЛЮЧЕННЫМ ФАЙЛОМ С ДАННЫМИ!!" << endl;
			cout << "Для выхода введите 54321" << endl;
			cin >> y;
			if (y == 54321)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (y <= 0)
			{
				cout << "Количество вариантов не может быть равен nullus — никакой или быть отрицательным " << endl;
				continue;
			}
			if (y > t)
			{
				cout << "К сожалению количество вариантов ограничено " << t << endl;
				continue;
			}
			else break;
		}
		system("cls");
		ifstream s;
		s.open("prakt3.txt");
		if (!s)
		{
			cout << " Ошибка файл не загружен или отсутствует." << endl;
			return 0;
		}
		else
		{
			cout << " Всё работает. Файл открыт." << endl;
		}
		string tot;
		for (int i = 0; i < y; i++)
		{
			getline(s, tot);
			s.close();
			int ux = 0;
			for (int lop = 0; lop < tot.length(); lop++)
			{
				in[lop] = tot[ux++];
			}
			stck *malyn, *tmp = NULL;
			char a;
			int  pov = 0, ind = 0;
			while (in[ind] != '\0')
			{
				if (in[ind] >= 'a'&& in[ind] <= 'z')
				{
					out[pov++] = in[ind];
				}
				if (in[ind] == '(')
				{
					tmp = inSpi(tmp, in[ind]);
				}
				if (in[ind] == ')')
				{
					while ((tmp->y) != '(')
					{
						tmp = outSpi(tmp, a);
						out[pov++] = a;
						if (!tmp)
						{
							a = '\0';
							out[pov++] = a;
						}
					}
					malyn = tmp;
					tmp = tmp->next;
					delete malyn;
				}
				if (in[ind] == '+' || in[ind] == '-' || in[ind] == '*' || in[ind] == '/')
				{
					while (tmp != NULL && znac(tmp->y) >= znac(in[ind]))
					{
						tmp = outSpi(tmp, a);
						out[pov++] = a;
					}
					tmp = inSpi(tmp, in[ind]);
				}
				ind++;
			}
			while (tmp != NULL)
			{
				tmp = outSpi(tmp, a);
				out[pov++] = a;
			}
			out[pov] = '\0';

			ofstream d;
			d.open("out.txt", ios::app);
			if (!d)
			{
				cout << "Файл не открыт!!!\n";
			}
			else
			{
				cout << "Всё работает. Файл открыт в режиме дозаписи!\n";
			}
			d << "\n";
			d << out;
			d.close();
		}
		return 0;
	}
	if (lab == 4) {
		cout << "\n GEME OVER \n";
		return 0;
	}
	return 0;
}