// Практическая Работа №2.

#include <iostream>
#include <iomanip>
#include <string> //отличная библиотека работы со строками
#include <chrono> //для определения классов и функций, которые представляют и обрабатывают длительность и время ожидания.
#include <windows.h> // разобрался это библиотека подключает функционал ОС Windows
#include <fstream> // читать и писать файлы

using namespace std;
struct Data //создал отдельную структуру чисто под данные
{
	int a;
}qwerty;
struct b //только для пункта б где что-то там автоматически 
{
	int ch;
	b *nextb;
};
struct list //структура для описания двусвязного списка
{
	Data z; // информационная часть
	list *next; // адресная часть на следующий элемент
	list *prev; // адресная часть на предыдущий элемент

}listok;
double t, vstavka, udalenie, poluchenie; //это для массива
double tim, vsta, iuda, policay; //это для списков
int *arr; // указатель для выделения памяти под массив
list *head = NULL;
list *last;
int strok = 1;
int menu(int xz) {
	int qwe = 0;
	HANDLE O = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(O, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n#####*****@@@@@*****#####\n";
	cout << "\n ОСНОВНОЕ МЕНЮ\n";
	SetConsoleTextAttribute(O, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << setw(4) << "1. Формирование целочисленного одномерного массива размерности N,\n";
	cout << setw(4) << "2. Определение скорости создания динамического массива п.1.\n";
	cout << setw(4) << "3. Вставка, удаление и получение элемента массива.\n";
	cout << setw(4) << "4. Определение скорости вставки, удаления и получения элемента массива п.3.\n";
	cout << setw(4) << "5. Формирование двусвязного списка размерностьи N," << endl;
	cout << setw(4) << "6. Определение скорости создания двусвязного списка п.5.\n";
	cout << setw(4) << "7. Вставка, удаление и получение элемента двусвязного списка.\n";
	cout << setw(4) << "8. Определение скорости вставки, удаления и получения элемента двусвязного списка п.7.\n";
	cout << setw(4) << "9. Выход" << endl;
	while (true)
	{
		cout << setw(4) << "Выберите необходимые действия:" << endl;
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
		if (qwe > 9)
		{
			cout << " Возможное значение <В диапозоне от 1-9>" << endl;
			continue;
		}
		else break;
	}
	system("cls");
	return qwe;
}
int podmenu(int qw) {
	int zx = 0;
	cout << "=====*****=====*****=====" << endl;
	cout << setw(24) << " !!!=ПОДМЕНЮ=!!!" << endl;
	if (qw == 1)
	{
		cout << setw(4) << "1. Пользователь вводит количество элементов в массиве, который будет автоматически заполнятся случайными числами (0 до 99);" << endl;
		cout << setw(4) << "2. Пользователь вводит в консоль элементы массива, N определяется автоматически по количеству введенных элементов;" << endl;
		cout << setw(4) << "3. Массив считывается с файла, (file.txt) N определяется как количество элементов массива в файле;" << endl;
		while (true)
		{
			cout << setw(4) << "Выберите необходимые действия:" << endl;
			cin >> zx;
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (zx <= 0)
			{
				cout << " Значение должно быть положительным" << endl;
				continue;
			}
			if (zx > 3)
			{
				cout << " Возможное значение <В диапозоне от 1-3>" << endl;
				continue;
			}
			else break;
		}
		system("cls");
		return zx;
	}
	if (qw == 2)
	{
		cout << setw(4) << "1. Вставка элемента массива." << endl;
		cout << setw(4) << "2. Удаление элементов массива по индексу." << endl;
		cout << setw(4) << "3. Удаление элемента массива по значению." << endl;
		cout << setw(4) << "4. Получение элемента массива по ндексу." << endl;
		cout << setw(4) << "5. Получение элемента массива по значению." << endl;
		while (true)
		{
			cout << setw(4) << "Выберите необходимые действия:" << endl;
			cin >> zx;
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (zx <= 0)
			{
				cout << " Значение должно быть положительным" << endl;
				continue;
			}
			if (zx > 5)
			{
				cout << " Возможное значение <В диапозоне от 1-5>" << endl;
				continue;
			}
			else break;
		}
		system("cls");
		return zx;
	}
	if (qw == 3)
	{
		cout << setw(4) << "1. Пользователь вводит количество элементов в списке, который будет автоматически заполнятся случайными числами (0 до 99);" << endl;
		cout << setw(4) << "2. Пользователь вводит в консоль элементы списка, N определяется автоматически по количеству введенных элементов;" << endl;
		cout << setw(4) << "3. Двусвязный список считывается с файла, (file.txt) N определяется как количество элементов списка в файле;" << endl;
		while (true)
		{
			cout << setw(4) << "Выберите необходимые действия:" << endl;
			cin >> zx;
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (zx <= 0)
			{
				cout << " Значение должно быть положительным" << endl;
				continue;
			}
			if (zx > 3)
			{
				cout << " Возможное значение <В диапозоне от 1-3>" << endl;
				continue;
			}
			else break;
		}
		system("cls");
		return zx;
	}
	if (qw == 4)
	{
		cout << setw(4) << "1. Вставка элемента двусвязного списка." << endl;
		cout << setw(4) << "2. Удаление элемента списка по (индексу хз что это значит сделал по счёту)." << endl;
		cout << setw(4) << "3. Удаление элемента списка по значению." << endl;
		cout << setw(4) << "4. Получение элемента списка по (индексу хз что это значит сделал по счёту)." << endl;
		cout << setw(4) << "5. Получение элемента списка по значению." << endl;
		while (true)
		{
			cout << setw(4) << "Выберите необходимые действия:" << endl;
			cin >> zx;
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (zx <= 0)
			{
				cout << " Значение должно быть положительным" << endl;
				continue;
			}
			if (zx > 5)
			{
				cout << " Возможное значение <В диапозоне от 1-5>" << endl;
				continue;
			}
			else break;
		}
		system("cls");
		return zx;
	}
	return zx;
}
int shet(int strok) //функция подсчёта строк 
{
	ifstream file("test.txt");
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
	/*cout << "\n Техданные  :" << strok;*/
	return strok;
}
int ReadFileA(int kol)
{
	cout << "\n Загрузка файла test.txt \n";
	ifstream file("test.txt");
	if (!file)
	{
		cout << "Файл не открыт!!!" << endl;
		return 0;
	}
	else
	{
		cout << "Всё работает. Файл открыт!" << endl;
	}
	arr = new int[kol]; // выделение памяти под массив
	auto start = chrono::system_clock::now();
	for (int i = 0; i < kol; i++) {
		arr[i] = 0;
		while (true)
		{
			file >> arr[i];
			if (!file)
			{
				cout << "Ошибка чтения, проверьте данные в файле." << endl;
				return 0;
			}
			else break;
		}
	}
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	t = diff.count();
	cout << "\n" << "Скорость создания одномерного динамического массива= " << diff.count() << "сек." << endl;
	file.close();
	return kol;
}
void ReadFileS(int kol) //открытие файла и заполнение списка
{
	last = head;
	int num;
	cout << "\n Загрузка файла test.txt \n";
	ifstream file("test.txt");
	if (!file)
	{
		cout << "Файл не открыт!!!" << endl;
		return;
	}
	else
	{
		cout << "Всё работает. Файл открыт!" << endl;
	}
	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < kol; i++)
	{
		while (true)
		{
			file >> num;
			if (!file)
			{
				cout << "Ошибка чтения, проверьте данные в файле." << endl;
				return;
			}
			else break;
		}
		if (head == NULL)
		{
			head = new list;
			head->z.a = num;
			head->next = NULL;
			head->prev = NULL;
			last = head;
		}
		else
		{
			list *tmp = last;
			last->next = new list;
			last->next->z.a = num;
			last->next->next = NULL;
			last->next->prev = tmp;
			last = last->next;
		}
		file.get();
	}
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	tim = diff.count();
	cout << "\n" << "Скорость создания двусваязного списка= " << diff.count() << "сек." << endl;
	file.close();
}
void outA(int *q,int kol)
{
	if (kol == 0)
	{
		cout << " В массиве нет элементов " << endl;
		return;
	}
	for (int i = 0; i < kol; i++) {
		cout << q[i] << " ";
	}
	cout << endl;
}
void outS(list *head)
{
	list *out = head;
	if (head == NULL)
	{
		cout << "Двусвязный список пуст!" << endl;
		return;
	}
	while (out)
	{
		cout << out->z.a << " ";
		out = out->next;
	}
	cout << endl;
}
int a1(int ar)
{
	auto srand(time(0));
	arr = new int[ar]; // выделение памяти под массив
	auto start = chrono::system_clock::now();
	for (int i = 0; i < ar; i++) {
		arr[i] = rand() % (199 - 1) - 99;
	}
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	t = diff.count();
	cout << "\n" << "Скорость создания одномерного динамического массива= " << diff.count() << "сек." << endl;
	return ar;
}
int a3(int ar, int a)
{
	int q = ar + a;
	int *tmp;
	int *news;
	news = new int[a];
	int x = 0;
	for (int i = 0; i < a; i++)
	{
		while (true)
		{
			cout << " Введите значение элементов  массива " << endl;
			cin >> x;
			if (cin.fail())
			{
				cout << "Это должно быть число" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				continue;
			}
			if (x > 999 || x < -999)
			{
				cout << " Значение элемента массива задано <В диапозоне от -999 до 999 > " << endl;
				continue;
			}
			else break;
		}
		news[i] = x;
	}
	tmp = new int[q];
	for (int i = 0; i < ar; i++)
	{
		tmp[i] = arr[i];
	}
	int j = 0;
	auto start = chrono::system_clock::now();
	for (int i = ar ; i < q; i++)
	{
		tmp[i] = news[j];
		j++;
	}
	auto end = chrono::system_clock::now();
	delete [] arr;
	delete[] news;
	arr = tmp;
	chrono::duration<double> diff = end - start;
	vstavka = diff.count();
	return q;
}
bool auxiliary(int q[], int len, int val)
{
	for (int i = 0; i < len; i++)
	{
		if (val == q[i])
			return true;
	}
	return false;
}
int *delA3(int w,int *q,int e)
{
	int tmp;
	for (int i = 0; i < e - 1; i++) {
		for (int j = 0; j < e - i - 1; j++) {
			if (q[j] > q[j + 1]) {
				tmp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = tmp;
			}
		}
	}
	auto start = chrono::system_clock::now();
	int *temp = new int[w - e];
	int j = 0;
	for (int i = 0; i < w; i++)
	{
		if (!auxiliary(q, e, i))
		{
			temp[j++] = arr[i];
		}
	}
	delete[] arr;
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	udalenie = diff.count();
	return temp;
}
int delznak(int *q, int s,int b)
{
	int j = 0;
	int z = 0;
	for (int i = 0; i < s; i++) {
		if (arr[i] != b) { 
			arr[j++] = arr[i]; 
		}
		else {
			z++;
		}
	}
	s = j;
	if (z == 0)
	{
		cout << " Нет элементов для удаления" << endl;
		return s;
	}
	int *tmp;
	tmp = new int[s];
	for (int i = 0; i < s; i++)
	{
		tmp[i] = arr[i];
	}
	delete[]arr;
	arr = tmp;
	return s;
}
int A4(int z,int q)
{
	for (int i = 0; i < q; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout <<"Значение элемента array["<<z<<"]="<< arr[z] << endl;
	return q;
}
int A5(int z, int q)
{
	int s = 0;
	auto start = chrono::system_clock::now();
	for (int i = 0; i < z; i++) {
		if (arr[i] == q) {
			cout << " Элемент найден " << "array[" << i << "]=" << q << endl;
			s++;
		}
	}
	if (s == 0)
	{
		cout << " В массиве нет элемента имеющего значение = " << q << endl;
	}
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	poluchenie = diff.count();
	return z;
}
void creat(int kol)
{
	auto srand(time(NULL));
	auto start = chrono::system_clock::now();
	for (int i = 0; i < kol; i++)
	{
		if (head == NULL)
		{
			head = new list;
			head->z.a = rand() % (199 - 1) - 99;
			head->next = NULL;
			head->prev = NULL;
			last = head;
		}
		else
		{
			list *tmp = last;
			last->next = new list;
			last->next->z.a = rand() % (199 - 1) - 99;
			last->next->next = NULL;
			last->next->prev = tmp;
			last = last->next;
		}
	}
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	tim = diff.count();
}
void DelSpisok(int x, int raz)
{
	auto start = chrono::system_clock::now();
	if (x == 1 && head->next) //если удаляем первый НО есть и другие зараза забыл с 1 семестра эту конструкцию
	{
		list *temp = head;	      // указываем что нам нужно начало списка
		head = head->next;        // сдвигаем начало на следующий за началом элемент
		head->prev = NULL;		// делаем так чтоб предыдущий началу элемент был пустым
		delete temp;			// удаляем удаляемое начало
		raz--;	 //счетчик 
		return;
	}
	else if (x == 1 && head == last)  // если удаляем первый НО в списке только 1 элемент
	{
		head->next = NULL;
		head = NULL;
		delete head;	  // удаляем указатель на начало
		raz = 0;
		return;
	}
	if (x == raz) // вот нафига нужено знать ко-во удаляемый элемент является последним элементом списка
	{
		list *temp = last;	  // указываем что нужен хвост
		last = last->prev;  // отодвигаем хвост немного назад
		last->next = NULL; // обозначаем что впереди за хвостом пусто
		delete temp;	// очищаем память от бывшего хвоста
		raz--;
		return;
	}
	list *tmp = head, *tmp2;    // если удаляемый элемент где-то в середине списка самое простое                   
	//tmp-Удаляемый элемент tmp2 нужен 
	for (int i = 0; i < x - 1; i++)
	{
		tmp = tmp->next;  // идем к адресу удаляемого элемента
	}
	tmp2 = tmp;	          // временно запоминаем адрес удаляемого элемента
	tmp2->prev->next = tmp->next; // записываем данные что следующий за перед сейчас удаляемым элементом это следующий от удаляемого
	tmp2->next->prev = tmp->prev;  //а предыдущий для следующего - это предыдущий для удаляемого
	delete tmp;
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	iuda = diff.count();
}
void quest(int raz, int a)
{
	auto start = chrono::system_clock::now();
	list *q = head;
	int i = 0;
	int net = 0;
	while (q)
	{
		if (q->z.a == a)
		{
			++i;
			cout << "Элемент " << a << " найден в списке " << i << " раз." << endl;
		}
		q = q->next;
		++net;
	}
	if (raz == net)
	{
		cout << "Элемента " << a << " в списке отсутствует." << endl;
	}
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	policay = diff.count();
}
int main()
{
Mem1:
	int ar;
	int xz = 0;
	setlocale(LC_ALL, "Russian");
	int lab = menu(xz);
	if (lab == 1) {
		cout << setw(4) << "1. Формирование целочисленного одномерного массива размерности N," << endl;
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		int pod1 = 1;
		int znak = podmenu(pod1);
		if (znak == 1)
		{
			int a;
			while (true)
			{
				cout << " Введите количество элементов в массиве " << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Количество элементов должно быть положительным" << endl;
					continue;
				}
				if (a > 77)
				{
					cout << " ХЗ я так решил максиум элементов 77" << endl;
					continue;
				}
				else break;
			}
			ar = 0;
			ar = a1(a);
			outA(arr, ar);
		}
		if (znak == 2)
		{
			b *xz = NULL;
			b *zx;
			zx = xz;
			cout << " Ввидите значение элементов массива окончания ввода буква или знак" << endl;
			while (true)
			{
				int a;
				cout << " Продолжайте ввод элементов" << endl;
				cin >> a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					break;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				if (xz == NULL) 
				{
					xz = new b; 
					xz->ch = a; 
					xz->nextb = NULL;
					zx = xz; 
				}
				else
				{
					zx->nextb = new b; 
					zx->nextb->ch = a; 
					zx->nextb->nextb = NULL; // Элемент после него пустой 
					zx = zx->nextb; // Теперь этот эл-т является последним
				}
			}
			auto start = chrono::system_clock::now();
			if (xz == NULL)
			{
				cout << "  Вы действительно можете набирать текст со скоростью 600 символов в минуту?  " << endl;
				cout << "  Да! Но такая ерунда получается..." << endl;
				return 0;
			}
			int poi = 0;
			b *tak = xz;
			while (tak)
			{
				++poi;
				tak = tak->nextb;
			}
			cout << " Ввод " << poi << " элементов закончен" << endl;
			int i = 0;
			arr = new int[poi];
			while (xz)
			{
				arr[i++] = xz->ch;
				xz = xz->nextb;
			}
			auto end = chrono::system_clock::now();
			chrono::duration<double> diff = end - start;
			t = diff.count();
			ar = 0;
			outA(arr, poi);
			ar = poi;
		}
		if (znak == 3)
		{
			ar = 0;
			strok = shet(strok);
			ar = ReadFileA(strok);
			outA(arr, ar);
			strok = 1;
		}
		goto Mem1;
	}
	if (lab == 2) {
		cout << setw(4) << "2. Определение скорости создания динамического массива п.1.\n";
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~";
		cout << "\n" << "Скорость создания одномерного динамического массива = " << t << "сек." << endl;
		goto Mem1;
	}
	if (lab == 3) {
		cout << setw(4) << "3. Вставка, удаление и получение элементов массива." << endl;
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		int pod2 = 2;
		int znak = podmenu(pod2);
		if (znak == 1)
		{
			if (arr == NULL)
			{
				cout << " Создайте динамический массив" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			int a;
			while (true)
			{
				cout << " Ввидите количество элементов необходимых для вставки в массив" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Количество элементов должно быть положительным" << endl;
					continue;
				}
				if (a > 14)
				{
					cout << " Проблематично вводить такое количество элементов" << endl;
					continue;
				}
				else break;
			}
			cout << " Было..." << endl;
			outA(arr, ar);
			int q = a3(ar, a);
			cout << " Через несколько сотых сек..." << endl;
			outA(arr, q);
			ar = q;
		}
		if (znak == 2)
		{
			if (arr == NULL)
			{
				cout << " Создайте динамический массив" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			int a;
			while (true)
			{
				cout << " Ввидите количество элементов для удаления" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Количество элементов должно быть положительным" << endl;
					continue;
				}
				if (a > ar)
				{
					cout << " Максимально возможное количество элементов для удаления = " << ar << endl;
					continue;
				}
				else break;
			}
			int *tmp;
			tmp = new int[a]; // выделение памяти под массив
			for (int i = 0; i < a; i++)
			{
				int b;
				while (true)
				{
					cout << " Ввидите индекс элементов для удаления" << endl;
					cin >> b;
					if (cin.fail())
					{
						cout << "Это должно быть число" << endl;
						cin.clear();
						cin.ignore(32767, '\n');
						continue;
					}
					if (b < 0)
					{
						cout << " Индекс элемента должен быть положительным" << endl;
						continue;
					}
					if (b >= ar)
					{
						cout << " Максимально возможный индекс для удаления = " << ar - 1 << endl;
						continue;
					}
					else break;
				}
				tmp[i] = b;
			}
			cout << " Было..." << endl;
			outA(arr, ar);
			arr = delA3(ar, tmp, a);
			ar -=a;
			cout << " Через несколько сотых сек..." << endl;
			outA(arr, ar);
		}
		if (znak == 3)
		{
			if (arr == NULL)
			{
				cout << " Создайте динамический массив" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Было..." << endl;
			outA(arr, ar);
			int b;
			while (true)
			{
				cout << " Ввидите значение элемента для удаления" << endl;
				cin >> b;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (b > 999 || b < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				else break;
			}
			int xz = delznak(arr, ar, b);
			ar = 0;
			ar = xz;
			cout << " Времени нет. Сделать удаления нескольких элементов увы по заданию..." << endl;
			outA(arr, ar);
		}
		if (znak == 4)
		{
			if (arr == NULL)
			{
				cout << " Создайте динамический массив" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Было..." << endl;
			outA(arr, ar);
			int a;
			while (true)
			{
				cout << " Ввидите индекс элемента для получения значений" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a < 0)
				{
					cout << " Индекс должен быть положительным" << endl;
					continue;
				}
				if (a > ar)
				{
					cout << " Максимально возможное значение индекса = " << ar-1 << endl;
					continue;
				}
				else break;
			}
			int v = A4(a, ar);
			ar = 0;
			ar = v;
			cout << " Через несколько сотых сек..." << endl;
			outA(arr, ar);
		}
		if (znak == 5)
		{
			if (arr == NULL)
			{
				cout << " Создайте динамический массив" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Было..." << endl;
			outA(arr, ar);
			int a;
			while (true)
			{
				cout << " Ввидите значение элемента для поиска в массиве" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				else break;
			}
			int xo = A5(ar, a);
			ar = 0;
			ar = xo;
			cout << " Через несколько сотых сек..." << endl;
			outA(arr, ar);
		}
		goto Mem1;
	}
	if (lab == 4) {
		cout << setw(4) << "4. Определение скорости вставки, удаления и получения элемента массива п.3." << endl;
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		cout << "Скорость вставки элементов одномерного динамического массива = " << vstavka << "сек." << endl;
		cout << "Скорость удаления элементов одномерного динамического массива = " << udalenie << "сек." << endl;
		cout << "Скорость получения элементов одномерного динамического массива = " << poluchenie << "сек." << endl;
		goto Mem1;
	}
	if (lab == 5) {
		cout << setw(4) << "5. Формирование двусвязного списка размерностьи N," << endl;
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		int pod3 = 3;
		int znak=podmenu(pod3);
		cout << znak << endl;
		if (znak == 1)
		{
			int a;
			while (true)
			{
				cout << " Введите количество элементов в двусвязном списке" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Количество элементов должно быть положительным" << endl;
					continue;
				}
				if (a > 77)
				{
					cout << " ХЗ я так решил максиум элементов 77" << endl;
					continue;
				}
				else break;
			}
			creat(a);
			outS(head);
		}
		if (znak == 2)
		{
			cout << " Ввидите значение элементов двусвязного списка окончания ввода буква или знак" << endl;
			while (true)
			{
				int a;
				cout << " Продолжайте ввод элементов" << endl;
				cin >> a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					break;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				if (head == NULL)
				{
					head = new list;
					head->z.a = a;
					head->next = NULL;
					head->prev = NULL;
					last = head;
				}
				else
				{
					list *tmp = last;
					last->next = new list;
					last->next->z.a = a;
					last->next->next = NULL;
					last->next->prev = tmp;
					last = last->next;
				}
			}
			auto start = chrono::system_clock::now();
			if (head == NULL)
			{
				cout << "  Вы действительно можете набирать текст со скоростью 600 символов в минуту?  " << endl;
				cout << "  Да! Но такая ерунда получается..." << endl;
				return 0;
			}
			int poi = 0;
			list *tak = head;
			while (tak)
			{
				++poi;
				tak = tak->next;
			}
			auto end = chrono::system_clock::now();
			chrono::duration<double> diff = end - start;
			tim = diff.count();
			cout << endl;
			cout << " Ввод " << poi << " элементов закончен" << endl;
			outS(head);
		}
		if (znak == 3)
		{
			strok = shet(strok);
			ReadFileS(strok);
			outS(head);
			strok = 1;
		}
		goto Mem1;
	}
	if (lab == 6) {
		cout << setw(4) << "6. Определение скорости создания двусвязного списка п.5.\n";
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		cout << "\n" << "Скорость создания двусвязного списка = " << tim << "сек." << endl;
		goto Mem1;
	}
	if (lab == 7) {
		cout << setw(4) << "7. Вставка, удаление и получение элемента двусвязного списка." << endl;
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		int pod4 = 4;
		int znak = podmenu(pod4);
		if (znak == 1)
		{
			if (head == NULL)
			{
				cout << " Создайте двусвязный список" << endl;
			}
			cout << " Было..." << endl;
			outS(head);
			cout << " Ввидите значение элементов двусвязного списка для вставки в конец списка, окончание ввода буква или знак" << endl;
			while (true)
			{
				int a;
				cout << " Продолжайте ввод элементов" << endl;
				cin >> a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					break;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				auto start = chrono::system_clock::now();
				if (head == NULL)
				{
					head = new list;
					head->z.a = a;
					head->next = NULL;
					head->prev = NULL;
					last = head;
				}
				else
				{
					list *tmp = last;
					last->next = new list;
					last->next->z.a = a;
					last->next->next = NULL;
					last->next->prev = tmp;
					last = last->next;
				}
				auto end = chrono::system_clock::now();
				chrono::duration<double> diff = end - start;
				vsta = diff.count();
			}
			if (head == NULL)
			{
				cout << "  Вы действительно можете набирать текст со скоростью 600 символов в минуту?  " << endl;
				cout << "  Да! Но такая ерунда получается..." << endl;
				return 0;
			}
			cout << " Ввод элементов закончен" << endl;
			outS(head);
		}
		if (znak == 2)
		{
			if (head == NULL)
			{
				cout << " Создайте двусвязный список" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Было..." << endl;
			outS(head);
			int raz = 0;
			list *tak = head;
			while (tak)
			{
				++raz;
				tak = tak->next;
			}
			int a;
			while (true)
			{
				cout << " Ввидите индекс двусвязного списка для удаления" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Индекс элемента должен быть положительным" << endl;
					continue;
				}
				if (a > raz)
				{
					cout << " Индекс элемента не может быть больше " << raz << endl;
					continue;
				}
				break;
			}
			DelSpisok(a, raz);
			cout << " Результат удаления " << endl;
			outS(head);
		}
		if (znak == 3)
		{
			if (head == NULL)
			{
				cout << " Создайте двусвязный список" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Было..." << endl;
			outS(head);
			int raz = 0;
			list *tak = head;
			while (tak)
			{
				++raz;
				tak = tak->next;
			}
			int a;
			while (true)
			{
				cout << " Ввидите значение элемента двусвязного списка для удаления" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				break;
			}
			list *tu = head;
			int el = 0;
			while (tu)
			{
				if (tu->z.a != a)
				{
					++el;
				}
				else
				{
					++el;
					break;
				}
				tu = tu->next;
			}
			if (raz == el && last->z.a != a)
			{
				cout << " Элемент со значением " << a << " в двусвязном списке отсутсвует" << endl;
				/*cout << " last->z.a=" << last->z.a << "!=a" << a << endl;*/
				goto Mem1;
			}
			DelSpisok(el, raz);
			cout << " Элемент "<< a <<" удален из списка."<< endl;
			outS(head);
		}
		if (znak == 4)
		{
			if (head == NULL)
			{
				cout << " Создайте двусвязный список" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Оригинал..." << endl;
			outS(head);
			int raz = 0;
			list *tak = head;
			while (tak)
			{
				++raz;
				tak = tak->next;
			}
			int a;
			while (true)
			{
				cout << " Ввидите индекс двусвязного списка для получения элемента <Индексы с 1-ы>" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a <= 0)
				{
					cout << " Индекс элемента должен быть положительным <Индексы с 1-ы>" << endl;
					continue;
				}
				if (a > raz)
				{
					cout << " Индекс элемента не может быть больше " << raz << endl;
					continue;
				}
				break;
			}
			list *gh = head;
			int ele=1;
			while (gh)
			{
				if(ele==a)
				{
					cout << "Значение элемента list[" << a << "]=" << gh->z.a <<" найдено в списке"<< endl;
					goto Mem1;
				}
				else
				{
					++ele;
				}
				gh = gh->next;
			}
		}
		if (znak == 5)
		{
			if (head == NULL)
			{
				cout << " Создайте двусвязный список" << endl;
				cout << " ERROR!" << endl;
				return 0;
			}
			cout << " Оригинал..." << endl;
			outS(head);
			int raz = 0;
			list *tak = head;
			while (tak)
			{
				++raz;
				tak = tak->next;
			}
			int a;
			while (true)
			{
				cout << " Ввидите значение элемента для поиска в списке" << endl;
				cin >> a;
				if (cin.fail())
				{
					cout << "Это должно быть число" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
					continue;
				}
				if (a > 999 || a < -999)
				{
					cout << " Возможные значения <В диапозоне от -999 до 999> " << endl;
					continue;
				}
				else break;
			}
			quest(raz, a);
		}
		goto Mem1;
	}
	if (lab == 8) {
		cout << setw(4) << "8. Определение скорости вставки, удаления и получения элемента двусвязного списка п.7.\n";
		cout << "####@@@@!!!!$$$$Prakt2SemII%%%%^^^^&&&&****~~~~" << endl;
		cout << "Скорость вставки элементов двусвязного списка = " << vsta << "сек." << endl;
		cout << "Скорость удаления элементов двусвязного списка = " << iuda << "сек." << endl;
		cout << "Скорость получения элементов двусвязного списка = " << policay << "сек." << endl;
		goto Mem1;
	}
	if (lab == 9) {
		cout << "\n GEME OVER \n";
		return 0;
	}
	return 0;
}




// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
