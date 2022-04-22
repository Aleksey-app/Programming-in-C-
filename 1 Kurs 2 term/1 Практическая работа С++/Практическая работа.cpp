#include <iostream> // стандартный
#include <iomanip> // для выравнивания setw и т.д
#include <string>  // для обработки текста
#include <windows.h>  // хз препод рассказал 1 курс 1 семестр 3 лаба
#include <fstream>  // читать и писать файлы
#include <cmath>  // для округления  работет с round 
using namespace std;
int kol;
struct student  //создание структуры студент
{
	int num_gr; //номер группы
	int num_list; //номер в списке группы
	int ocenki[8];  // оценки 
	string forma; // форма обучения
	string fio[20]; //ФИО
	char sex; // пол
	int date[40]; //дата год месяц день час мин сек
}mstudent[45];
int info(int a) //основное меню
{
	int b = 0;
	HANDLE O = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(O, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n#####*****@@@@@*****#####\n";
	cout << "\n ОСНОВНОЕ МЕНЮ ВВОД ДАННЫХ С КЛАВИАТУРЫ.\n";
	SetConsoleTextAttribute(O, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << setw(4) << "Выберите необходимые действия:" << "\n";
	cout << setw(4) << "1.  Создание новой записи о студенте.\n";
	cout << setw(4) << "2.  Внесение изменений в уже имеющуюся запись.\n";
	cout << setw(4) << "3.  Вывод всех данных о студентах.\n";
	cout << setw(4) << "4.  Вывод информации обо всех студентах группы N.N - иницилизируется пользователем.\n";
	cout << setw(4) << "5.  Вывод топа самых успешных студентов с наивысшим по рейтингу средним балом за прошедшую сессию.\n";
	cout << setw(4) << "6.  Вывод количества студентов мужского и женского пола.\n";
	cout << setw(4) << "7.  Определение количества студентов, которые будут получать стипендию(степендия начисляется,если у студента нет троек и очная форма обучения).\n";
	cout << setw(4) << "8.  Вывод данных о студентах, которые не получают стипендию; учатся только на `хорошо` и `отлично`; учатся только на `отлично`.\n";
	cout << setw(4) << "9.  Вывод данных о студентах, имеющих номер в списке - k.\n";
	cout << setw(4) << "10. Вывод всех записей, сделанных в день, который введёт пользователь.\n";
	cout << setw(4) << "11. EXIT...\n";
	cout << setw(4) << "12. Загрузить данные из файла.\n";
	cin >> b;
	cin.sync();
	system("cls");
	return b;
}
int shet(int ras) //функция подсчёта строк в файле Text.txt 
{
	ifstream file("Text.txt");
	if (!file)
	{
		cout << " Error!!! \n";
	}
	else
	{
		int ras = 1;
		while (true)
		{
			string v;
			getline(file, v);
			if (!file.eof())
				ras++;
			else
				break;
		}
		kol = ras / 7;
		cin.get();
	}
	file.close();
	cout << "\n Техданные  :" << kol;
	return kol;
}
void vvod() //создание новой записи о студенте. Геморойная функция замучился допиливать и переделовать
{
	SetConsoleCP(1251);          // незнаю как работает это русский
	SetConsoleOutputCP(1251);    // это тоже для русских букв тестил на винде без руссого это не работает
	cout << "\nВведите количество студентов.\n" << endl;
	/*int nu = dva + 1;*/
	int za;
	cin >> za;
	/*da = nu + za;*/
	for (int i = 0; i < za; i++) {
		cout << "Введите номер группы.\n" << endl;
		cin >> mstudent[i].num_gr;
		cout << "Введите номер в списке группы.\n" << endl;
		cin >> mstudent[i].num_list;
		cout << "Введите оценки за прошедшую сесию.\n (Физика История Алгебра Программирование МатАнализ Информатика Философия Экономика.\n" << "(Форма ввода 5 4 4 3 5 4 5 2).\n" << endl;
		int raz;
		cin >> raz;
		cin.sync();
		while (raz > 5 || raz < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> raz;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[0] = raz;
		int dva;
		cin >> dva;
		cin.sync();
		while (dva > 5 || dva < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> dva;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[1] = dva;
		int tri;
		cin >> tri;
		cin.sync();
		while (tri > 5 || tri < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> tri;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[2] = tri;
		int che;
		cin >> che;
		cin.sync();
		while (che > 5 || che < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> che;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[3] = che;
		int piy;
		cin >> piy;
		cin.sync();
		while (piy > 5 || piy < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> piy;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[4] = piy;
		int six;
		cin >> six;
		cin.sync();
		while (six > 5 || six < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> six;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[5] = six;
		int sem;
		cin >> sem;
		cin.sync();
		while (sem > 5 || sem < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> sem;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[6] = sem;
		int eil;
		cin >> eil;
		cin.sync();
		while (eil > 5 || eil < 2)
		{
			cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
			cin >> eil;
			cin.sync();
			continue;
		}
		mstudent[i].ocenki[7] = eil;
		cout << "Введите форму обучения(Дневная, Вечерняя, Заочная (Соблюдайте регистр!)).\n" << endl;
		cin >> mstudent[i].forma;
		cout << "Введите ФИО (Форма Фамилию Имя Отчество ).\n" << endl;
		for (int j = 0; j < 3; ++j) {
			cin >> mstudent[i].fio[j];
		}
		cout << "Введите пол(M,Ж).\n" << endl;
		cin >> mstudent[i].sex;
		cout << "Дата (Год) формат(xxxx).\n";
		cin >> mstudent[i].date[0];
		cin.sync();
		while (mstudent[i].date[0] > 2021 || mstudent[i].date[0] < 2020)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[0];
			cin.sync();
			continue;
		}
		cout << "Дата (Месяц) формат(xx).\n";
		cin >> mstudent[i].date[1];
		cin.sync();
		while (mstudent[i].date[1] > 12 || mstudent[i].date[1] < 1)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[1];
			cin.sync();
			continue;
		}
		cout << "Дата (День) формат(xx).\n";
		cin >> mstudent[i].date[2];
		cin.sync();
		while (mstudent[i].date[2] > 31 || mstudent[i].date[2] < 0)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[2];
			cin.sync();
			continue;
		}
		cout << "Дата (Час) формат(xx).\n";
		cin >> mstudent[i].date[3];
		cin.sync();
		while (mstudent[i].date[3] > 23 || mstudent[i].date[3] < 0)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[3];
			cin.sync();
			continue;
		}
		cout << "Дата (Мин) формат(xx).\n";
		cin >> mstudent[i].date[4];
		cin.sync();
		while (mstudent[i].date[4] > 59 || mstudent[i].date[4] < 0)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[4];
			cin.sync();
			continue;
		}
		cout << "Дата (Сек) формат(xx).\n";
		cin >> mstudent[i].date[5];
		cin.sync();
		while (mstudent[i].date[5] > 59 || mstudent[i].date[5] < 0)
		{
			cout << "\n Проверьте правильность данных \n";
			cin >> mstudent[i].date[5];
			cin.sync();
			continue;
		}
	}
	ofstream d;
	d.open("Text.txt", ios::app);
	if (!d)
	{
		cout << "Файл не открыт!!!\n";
	}
	else
	{
		cout << "Всё работает. Файл открыт в режиме дозаписи!\n";
	}
	for (int i = 0; i < za; i++) {
		d << "\n";
		d << mstudent[i].num_gr;
		d << "\n";
		d << mstudent[i].num_list;
		d << "\n";
		for (int j = 0; j < 8; ++j) {
			d << mstudent[i].ocenki[j] << " ";
		}
		d << "\n";
		d << mstudent[i].forma;
		d << "\n";
		for (int j = 0; j < 3; ++j) {
			d << mstudent[i].fio[j] << " ";
		}
		d << "\n";
		d << mstudent[i].sex;
		d << "\n";
		for (int j = 0; j < 6; ++j) {
			d << mstudent[i].date[j] << " ";
		}
	}
	d.close();
}
int izmena(int kol) // изменение в имеющуюся запись
{
	cout << " 1. Поиск по фамилии студента." << endl;

	SetConsoleCP(1251);          // незнаю как работает это русский
	SetConsoleOutputCP(1251);    // это тоже для русских букв тестил на винде без руссого это не работает
X2:
	cout << "\n Ввидите фамилию студента cоблюдая регистр по <форме Фамилия >" << endl;
	string x;
	cin >> x;
	cin.sync();
	int uff = 0;
	for (int i = 0; i < kol; i++) {
		if (mstudent[i].fio[0] == x) {
			cout << "\nВы искали: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << "?" << endl;
			cout << "1. Да" << endl;
			cout << "2. Нет" << endl;
			int nem;
			cin >> nem;
			cin.sync();
			while (nem > 2 || nem < 1)
			{
				cout << "\n Проверьте правильность данных <Возможен ответ 1.да или 2.нет \n";
				cin >> nem;
				cin.sync();
				continue;
			}
			if (nem == 2) {
				goto X2;
			}
			if (nem == 1) {
				cout << "\nВ данный момент запись имеет данные" << endl;
				cout << "\nНомер группы: " << mstudent[i].num_gr << "Номер в списке (порядковый номер) " << mstudent[i].num_list << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
				cout << "Форма обучения: " << mstudent[i].forma << endl;
				cout << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[i].ocenki[0] << "\n" << "История. " << mstudent[i].ocenki[1] << "\n" << "Алгебра. " << mstudent[i].ocenki[2] << endl;
				cout << "Программирование. " << mstudent[i].ocenki[3] << "\n" << "МатАнализ. " << mstudent[i].ocenki[4] << "\n" << "Информатика. " << mstudent[i].ocenki[5] << endl;
				cout << "Философия. " << mstudent[i].ocenki[6] << "\n" << "Экономика. " << mstudent[i].ocenki[7] << endl;
				cout << "Дата формата (год месяц день час мин сек).\n " << "Год: " << mstudent[i].date[0] << " Месяц: " << mstudent[i].date[1] << " День: " << mstudent[i].date[2];
				cout << " Час: " << mstudent[i].date[3] << " Мин: " << mstudent[i].date[4] << " Сек: " << mstudent[i].date[5] << endl;
				cout << "Что требуется изминить? выбирите варианты." << endl;
				cout << "1. Номер группы:" << endl;
				cout << "2. ФИО:" << endl;
				cout << "3. Пол:" << endl;
				cout << "4. Номер в списке:" << endl;
				cout << "5. Оценки за прошедшую сесию:" << endl;
				cout << "6. Форму обучения:" << endl;
				int izi;
				cin >> izi;
				cin.sync();
				while (izi > 6 || izi < 1)
				{
					cout << "\n Проверьте правильность данных <Ввидите цифру варианта 1-6> \n";
					cin >> izi;
					cin.sync();
					continue;
				}
				if (izi == 1) {
					cout << "\nМеняем номер группы" << endl;
					cout << "\nВведите номер группы формат(xxxx).\n" << "Диапазон возможных групп от 1-9999" << endl;
					int xzi = 0;
					cin >> xzi;
					cin.sync();
					while (xzi > 9999 || xzi < 1)
					{
						cout << "\n Проверьте правильность данных таких групп не существует \n";
						cin >> xzi;
						cin.sync();
						continue;
					}
					mstudent[i].num_gr = xzi;
					cout << "\nВнесены изменения теперь номер группы " << mstudent[i].num_gr << endl;
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
				if (izi == 2) {
					cout << "\nФамилию Имя Отчество" << endl;
					cout << "Введите ФИО (Форма Фамилию Имя Отчество ).\n" << endl;
					for (int j = 0; j < 3; ++j) {
						cin >> mstudent[i].fio[j];
					}
					cout << "\nВнесены изменения теперь ФИО " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
				if (izi == 3) {
					cout << "\nМеняем пол" << endl;
					cout << "\nВведите пол студента формат <M или Ж>.\n";
					char xzi;
					cin >> xzi;
					cin.sync();
					mstudent[i].sex = xzi;
					cout << "\nВнесены изменения пол студента  " << mstudent[i].sex << endl;
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
				if (izi == 4) {
					cout << "Ввидите номер в списке группы. <формат(xx) в диапазоне от 1 до 7>\n" << endl;
					int uff;
					cin >> uff;
					cin.sync();
					while (uff > 7 || uff < 1)
					{
						cout << "\n Проверьте правильность данных студента с таким номером в списке пока не существует \n";
						cin >> uff;
						cin.sync();
						continue;
					}
					mstudent[i].num_list = uff;
					cout << "\nВнесены изменения номер студента в списке группы  " << mstudent[i].num_list << endl;
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
				if (izi == 5) {
					cout << "Введите оценки за прошедшую сесию.\n (Физика История Алгебра Программирование МатАнализ Информатика Философия Экономика.\n" << "(Форма ввода 5 4 4 3 5 4 5 2).\n" << endl;
					int raz;
					cin >> raz;
					cin.sync();
					while (raz > 5 || raz < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> raz;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[0] = raz;
					int dva;
					cin >> dva;
					cin.sync();
					while (dva > 5 || dva < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> dva;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[1] = dva;
					int tri;
					cin >> tri;
					cin.sync();
					while (tri > 5 || tri < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> tri;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[2] = tri;
					int che;
					cin >> che;
					cin.sync();
					while (che > 5 || che < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> che;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[3] = che;
					int piy;
					cin >> piy;
					cin.sync();
					while (piy > 5 || piy < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> piy;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[4] = piy;
					int six;
					cin >> six;
					cin.sync();
					while (six > 5 || six < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> six;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[5] = six;
					int sem;
					cin >> sem;
					cin.sync();
					while (sem > 5 || sem < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> sem;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[6] = sem;
					int eil;
					cin >> eil;
					cin.sync();
					while (eil > 5 || eil < 2)
					{
						cout << "\n Проверьте правильность данных <Оценки в диапазоне от 5-2> \n";
						cin >> eil;
						cin.sync();
						continue;
					}
					mstudent[i].ocenki[7] = eil;
					cout << "\nВнесены изменения у студента " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
					cout << setw(10) << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[i].ocenki[0] << "\n" << "История. " << mstudent[i].ocenki[1] << "\n" << "Алгебра. " << mstudent[i].ocenki[2] << endl;
					cout << setw(10) << "Программирование. " << mstudent[i].ocenki[3] << "\n" << "МатАнализ. " << mstudent[i].ocenki[4] << "\n" << "Информатика. " << mstudent[i].ocenki[5] << endl;
					cout << setw(10) << "Философия. " << mstudent[i].ocenki[6] << "\n" << "Экономика. " << mstudent[i].ocenki[7] << endl;
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
				if (izi == 6) {
					cout << "Введите форму обучения(Дневная, Вечерняя, Заочная (Соблюдайте регистр!)).\n" << endl;
					string xzi = "Дневная";
					string xzy = "Вечерняя";
					string xzz = "Заочная";
					string six;
					cin >> six;
					cin.sync();
					if (six == xzi) {
						mstudent[i].forma = six;
					cout << "\nВнесены изменения теперь студент " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
					cout << "Имеет форму обучения " << mstudent[i].forma << endl;
					}
					if (six == xzy) {
						mstudent[i].forma = six;
					cout << "\nВнесены изменения теперь студент " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
					cout << "Имеет форму обучения " << mstudent[i].forma << endl;
					}
					if (six == xzz) {
						mstudent[i].forma = six;
					cout << "\nВнесены изменения теперь студент " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
					cout << "Имеет форму обучения " << mstudent[i].forma << endl;
					}
					cout << "\n Проверьте правильность данных таких форм обучения не существует\n";
					ofstream d;
					d.open("Text.txt", ios::out);
					if (!d)
					{
						cout << "Файл не открыт!!!\n";
					}
					else
					{
						cout << "Всё работает. Файл открыт в режиме полной перезаписи данных!\n";
					}
					for (int i = 0; i < kol; i++) {
						d << "\n";
						d << mstudent[i].num_gr;
						d << "\n";
						d << mstudent[i].num_list;
						d << "\n";
						for (int j = 0; j < 8; ++j) {
							d << mstudent[i].ocenki[j] << " ";
						}
						d << "\n";
						d << mstudent[i].forma;
						d << "\n";
						for (int j = 0; j < 3; ++j) {
							d << mstudent[i].fio[j] << " ";
						}
						d << "\n";
						d << mstudent[i].sex;
						d << "\n";
						for (int j = 0; j < 6; ++j) {
							d << mstudent[i].date[j] << " ";
						}
					}
					d.close();
					return 0;
				}
			}
		}
		else {
			uff++;
		}
		if (uff == kol) {
			cout << "\nК сожалению студента " << x << " нет в списках " << endl;
		}
	}
	return 0;
}
void vivod(int kol) //функция вывода 
{
	for (int i = 0; i < kol; i++)
	{
		cout << "\nНомер группы " << mstudent[i].num_gr << endl;
		cout << "Номер в списке (порядковый номер) " << mstudent[i].num_list << endl;
		cout << "ФИО " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
		cout << "Пол " << mstudent[i].sex << endl;
		cout << "Форма обучения " << mstudent[i].forma << endl;
		cout << setw(10) << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[i].ocenki[0] << "\n" << "История. " << mstudent[i].ocenki[1] << "\n" << "Алгебра. " << mstudent[i].ocenki[2] << endl;
		cout << setw(10) << "Программирование. " << mstudent[i].ocenki[3] << "\n" << "МатАнализ. " << mstudent[i].ocenki[4] << "\n" << "Информатика. " << mstudent[i].ocenki[5] << endl;
		cout << setw(10) << "Философия. " << mstudent[i].ocenki[6] << "\n" << "Экономика. " << mstudent[i].ocenki[7] << endl;
		cout << setw(10) << "Дата формата (год месяц день час мин сек).\n " << "Год: " << mstudent[i].date[0] << " Месяц: " << mstudent[i].date[1] << " День: " << mstudent[i].date[2];
		cout << " Час: " << mstudent[i].date[3] << " Мин: " << mstudent[i].date[4] << " Сек: " << mstudent[i].date[5];
	}
}
void num_gr(int kol) //поиск по группе 
{
	cout << "\nВведите номер группы формат(xxxx).\n" << endl;
	int xz = 0;
	cin >> xz;
	cin.sync();
	while (xz > 9999 || xz < 1)
	{
		cout << "\n Проверьте правильность данных таких групп не существует \n";
		cin >> xz;
		cin.sync();
		continue;
	}
	int q = 0;
	for (int i = 0; i < kol; i++)
	{
		if (mstudent[i].num_gr != xz) {
			q++;
		}
		else
		{
			cout << "\nНомер группы " << mstudent[i].num_gr << endl;
			cout << "Номер в списке (порядковый номер) " << mstudent[i].num_list << endl;
			cout << "ФИО " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
			cout << "Пол " << mstudent[i].sex << endl;
			cout << "Форма обучения " << mstudent[i].forma << endl;
			cout << setw(10) << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[i].ocenki[0] << "\n" << "История. " << mstudent[i].ocenki[1] << "\n" << "Алгебра. " << mstudent[i].ocenki[2] << endl;
			cout << setw(10) << "Программирование. " << mstudent[i].ocenki[3] << "\n" << "МатАнализ. " << mstudent[i].ocenki[4] << "\n" << "Информатика. " << mstudent[i].ocenki[5] << endl;
			cout << setw(10) << "Философия. " << mstudent[i].ocenki[6] << "\n" << "Экономика. " << mstudent[i].ocenki[7] << endl;
			cout << setw(10) << "Дата формата (год месяц день час мин сек).\n " << "Год: " << mstudent[i].date[0] << " Месяц: " << mstudent[i].date[1] << " День: " << mstudent[i].date[2];
			cout << " Час: " << mstudent[i].date[3] << " Мин: " << mstudent[i].date[4] << " Сек: " << mstudent[i].date[5] << endl;
		}

	}
	if (kol == q) {
		cout << "Записей о таких группах пока нет.\n";
	}
}
void sex(int kol) // М&Ж
{
	int a = 0, b = 0;
	for (int i = 0; i < kol; i++) {
		if (mstudent[i].sex == mstudent[0].sex) {
			a++;
		}
		else {
			b++;
		}
	}
	cout << "\n В списках групп всего : " << a << " студентов мужского пола";
	cout << "\n В списках групп всего : " << b << " студентов женского пола";
}
void topchik(int kol) //топ студентов с Наивысшим по рейтингу среднем баллом
{
	float Xmax[360];
	for (int i = 0; i < kol; i++) {
		Xmax[i] = ((mstudent[i].ocenki[0] + mstudent[i].ocenki[1] + mstudent[i].ocenki[2] + mstudent[i].ocenki[3] + mstudent[i].ocenki[4] + mstudent[i].ocenki[5] + mstudent[i].ocenki[6] + mstudent[i].ocenki[7]) / 8);
	}
	float Ymax = Xmax[0];
	for (int i = 0; i < kol; i++) {
		if (Xmax[i] > Ymax) {
			Ymax = Xmax[i];
		}
	}
	for (int i = 0; i < kol; i++) {
		if (Xmax[i] == Ymax) {
			cout << "\nНомер группы: " << mstudent[i].num_gr << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << " Средний балл: " << round(Xmax[i] * 100) / 100 << endl;
		}
	}
}
void stipuxa(int kol) // степендия 1 нет троек 2 очная форма (у меня Дневная)
{
	string x = "Дневная";
	int qwer = 0;
	for (int i = 0; i < kol; i++) {
		if (mstudent[i].forma == x) {
			int x = 3, y = 0;
			for (int j = 0; j < 8; ++j) {
				if (mstudent[i].ocenki[j] > x) {
					y++;
				}
				if (y == 8) {
					qwer++;
					HANDLE Q = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(Q, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "\nНомер группы: " << mstudent[i].num_gr << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << " Стипендия начисляется " << endl;

				}
			}
		}
	}
	cout << " Общее количесво студентов получающих стипендию = " << qwer << endl;
	/*return qwer;*/
}
void netu(int kol) //8 пукт нечего сложного но повозится пришлось 
{
	HANDLE J = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(J, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
	cout << "Учатся только на ОТЛИЧНО" << endl;
	float Xmax[360];
	for (int i = 0; i < kol; i++) {
		Xmax[i] = ((mstudent[i].ocenki[0] + mstudent[i].ocenki[1] + mstudent[i].ocenki[2] + mstudent[i].ocenki[3] + mstudent[i].ocenki[4] + mstudent[i].ocenki[5] + mstudent[i].ocenki[6] + mstudent[i].ocenki[7]) / 8);
	}
	float Ymax = Xmax[0];
	for (int i = 0; i < kol; i++) {
		if (Xmax[i] > Ymax) {
			Ymax = Xmax[i];
		}
	}
	int otl = 0;
	for (int i = 0; i < kol; i++) {
		if (Xmax[i] == Ymax) {
			otl++;
			cout << "\nНомер группы: " << mstudent[i].num_gr << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << " Форма обучения: " << mstudent[i].forma << endl;
		}
	}
	cout << "Учатся на <хорошо> и <отлично>" << endl; // запутался в циклах =( 
	int x = 3, y = 5, v = 0;
	for (int i = 0; i < kol; i++) {
		int z = 0, w = 0;
		for (int j = 0; j < 8; ++j) {
			if (mstudent[i].ocenki[j] > x) {
				z++;
			}
			if (z == 8)
			{
				for (int j = 0; j < 8; ++j) {
					if (mstudent[i].ocenki[j] != y) {
						w++;
					}
				}
			}
		}
		if (w >= 1) {
			v++;
			cout << "\nНомер группы: " << mstudent[i].num_gr << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << " Форма обучения: " << mstudent[i].forma << endl;
		}
	}
	HANDLE A = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(A, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n Студенты которые не получают стипендию <Есть тройки или ниже>" << endl;
	int tri = 0;
	for (int i = 0; i < kol; i++) {
		int x = 3, y = 0;
		for (int j = 0; j < 8; ++j) {
			if (mstudent[i].ocenki[j] <= x) {
				y++;
			}
		}
		if (y > 0) {
			tri++;
			cout << "\nНомер группы: " << mstudent[i].num_gr << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << " Форма обучения: " << mstudent[i].forma << endl;
		}
	}
	cout << "\n Списочный состав студентов: " << kol << " Учатся тоько на отлично: " << otl << " Учатся на <хорошо> и <отлично>: " << v << " Остальные не получают стипендию: " << tri << endl;
}
void list(int kol) // поиск по номеру <у меня номер в списке не сквозной это усложняет задачу> 
{
	cout << "\nВведите номер группы формат(xxxx).\n" << endl;
	int xz = 0;
	cin >> xz;
	cin.sync();
	while (xz > 9999 || xz < 0)
	{
		cout << "\n Проверьте правильность данных таких групп не существует \n";
		cin >> xz;
		cin.sync();
		continue;
	}
	int q = 0, kostili = 0;
	for (int i = 0; i < kol; i++)
	{
		if (mstudent[i].num_gr == xz) {
			cout << "\n Номер группы: " << xz << endl;
			cout << "Ввидите номер в списке группы. <формат(xx) в диапазоне от 1 до 7>\n" << endl;
			int uff;
			cin >> uff;
			cin.sync();
			while (uff > 7 || uff < 1)
			{
				cout << "\n Проверьте правильность данных студента с таким номером в списке пока не существует \n";
				cin >> uff;
				cin.sync();
				continue;
			}
			if (mstudent[i].num_list == uff) {
				cout << "\nНомер группы: " << mstudent[i].num_gr << "Номер в списке (порядковый номер) " << mstudent[i].num_list << " ФИО: " << mstudent[i].fio[0] << " " << mstudent[i].fio[1] << " " << mstudent[i].fio[2] << endl;
				cout << "Форма обучения: " << mstudent[i].forma << endl;
				cout << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[i].ocenki[0] << "\n" << "История. " << mstudent[i].ocenki[1] << "\n" << "Алгебра. " << mstudent[i].ocenki[2] << endl;
				cout << "Программирование. " << mstudent[i].ocenki[3] << "\n" << "МатАнализ. " << mstudent[i].ocenki[4] << "\n" << "Информатика. " << mstudent[i].ocenki[5] << endl;
				cout << "Философия. " << mstudent[i].ocenki[6] << "\n" << "Экономика. " << mstudent[i].ocenki[7] << endl;
				cout << "Дата формата (год месяц день час мин сек).\n " << "Год: " << mstudent[i].date[0] << " Месяц: " << mstudent[i].date[1] << " День: " << mstudent[i].date[2];
				cout << " Час: " << mstudent[i].date[3] << " Мин: " << mstudent[i].date[4] << " Сек: " << mstudent[i].date[5];
				goto kostili;
			}
			else {
				kostili = i;
			}
			for (kostili; kostili < kostili + 7, kostili <= kol; kostili++)
			{
				if (mstudent[kostili].num_list == uff) {
					cout << "\nНомер группы: " << mstudent[kostili].num_gr << "Номер в списке (порядковый номер) " << mstudent[kostili].num_list << " ФИО: " << mstudent[kostili].fio[0] << " " << mstudent[kostili].fio[1] << " " << mstudent[kostili].fio[2] << endl;
					cout << "Форма обучения: " << mstudent[kostili].forma << endl;
					cout << "		ОЦЕНКИ.\n" << "Физика. " << mstudent[kostili].ocenki[0] << "\n" << "История. " << mstudent[kostili].ocenki[1] << "\n" << "Алгебра. " << mstudent[kostili].ocenki[2] << endl;
					cout << "Программирование. " << mstudent[kostili].ocenki[3] << "\n" << "МатАнализ. " << mstudent[kostili].ocenki[4] << "\n" << "Информатика. " << mstudent[kostili].ocenki[5] << endl;
					cout << "Философия. " << mstudent[kostili].ocenki[6] << "\n" << "Экономика. " << mstudent[kostili].ocenki[7] << endl;
					cout << "Дата формата (год месяц день час мин сек).\n " << "Год: " << mstudent[kostili].date[0] << " Месяц: " << mstudent[kostili].date[1] << " День: " << mstudent[kostili].date[2];
					cout << " Час: " << mstudent[kostili].date[3] << " Мин: " << mstudent[kostili].date[4] << " Сек: " << mstudent[kostili].date[5];
					goto kostili;
				}
			}
			cout << "Записей о студентах с номером в списке " << uff << " пока нет.\n";
			goto kostili;
		}
		else {
			q++;
		}
	}
	if (kol == q) {
		cout << "Записей о таких группах пока нет.\n";
	}
kostili:
	cout << "\nПоиск закончен...\n";
}
void PM(int kol) // поиск по дате
{
	cout << "Ввидите дату по которой начнем поиск данных <Дата (День) формат(xx)>." << endl;
	int I;
	cin >> I;
	cin.sync();
	while (I > 31 || I < 0)
	{
		cout << "\n Проверьте правильность данных \n";
		cin >> I;
		cin.sync();
		continue;
	}
	int raz = 0, p = 0;
	struct MyStruct
	{
		int gr;
		int num;
		int oce[8];
		string form;
		string name[20];
		char s;
		int d[40];
	}uffMy[50];
	for (int i = 0; i < kol; i++)
	{
		if (mstudent[i].date[2] == I)
		{
			p++;
			uffMy[p].gr = mstudent[i].num_gr;
			uffMy[p].num = mstudent[i].num_list;
			uffMy[p].oce[0] = mstudent[i].ocenki[0];
			uffMy[p].oce[1] = mstudent[i].ocenki[1];
			uffMy[p].oce[2] = mstudent[i].ocenki[2];
			uffMy[p].oce[3] = mstudent[i].ocenki[3];
			uffMy[p].oce[4] = mstudent[i].ocenki[4];
			uffMy[p].oce[5] = mstudent[i].ocenki[5];
			uffMy[p].oce[6] = mstudent[i].ocenki[6];
			uffMy[p].oce[7] = mstudent[i].ocenki[7];
			uffMy[p].form = mstudent[i].forma;
			uffMy[p].name[0] = mstudent[i].fio[0];
			uffMy[p].name[1] = mstudent[i].fio[1];
			uffMy[p].name[2] = mstudent[i].fio[2];
			uffMy[p].s = mstudent[i].sex;
			uffMy[p].d[0] = mstudent[i].date[0];
			uffMy[p].d[1] = mstudent[i].date[1];
			uffMy[p].d[2] = mstudent[i].date[2];
			uffMy[p].d[3] = mstudent[i].date[3];
			uffMy[p].d[4] = mstudent[i].date[4];
			uffMy[p].d[5] = mstudent[i].date[5];
		}
		else {
			raz++;
		}
	}
	if (raz == kol) {
		cout << " К сожелению " << I << " числа записи о студентах не вносились" << endl;
	}
	for (int i = 1; i <= p; i++)
	{
		if (uffMy[i].d[3] <= 11)
		{
			HANDLE R = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(R, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "Данные о студентах внесённые " << I << " числа до полудня" << endl;
			cout << "\nНомер группы: " << uffMy[i].gr << "Номер в списке (порядковый номер) " << uffMy[i].num << " ФИО: " << uffMy[i].name[0] << " " << uffMy[i].name[1] << " " << uffMy[i].name[2] << endl;
			cout << "Форма обучения: " << uffMy[i].form << endl;
			cout << "		ОЦЕНКИ.\n" << "Физика. " << uffMy[i].oce[0] << "\n" << "История. " << uffMy[i].oce[1] << "\n" << "Алгебра. " << uffMy[i].oce[2] << endl;
			cout << "Программирование. " << uffMy[i].oce[3] << "\n" << "МатАнализ. " << uffMy[i].oce[4] << "\n" << "Информатика. " << uffMy[i].oce[5] << endl;
			cout << "Философия. " << uffMy[i].oce[6] << "\n" << "Экономика. " << uffMy[i].oce[7] << endl;
			cout << "Пол " << uffMy[i].s << endl;
			cout << "Дата формата (год месяц день час мин сек).\n " << "Год: " << uffMy[i].d[0] << " Месяц: " << uffMy[i].d[1] << " День: " << uffMy[i].d[2];
			cout << " Час: " << uffMy[i].d[3] << " Мин: " << uffMy[i].d[4] << " Сек: " << uffMy[i].d[5] << endl;
		}
		if (uffMy[i].d[3] > 12)
		{
			HANDLE my = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(my, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Данные о студентах внесённые " << I << " числа после полудня" << endl;
			cout << "\nНомер группы: " << uffMy[i].gr << "Номер в списке (порядковый номер) " << uffMy[i].num << " ФИО: " << uffMy[i].name[0] << " " << uffMy[i].name[1] << " " << uffMy[i].name[2] << endl;
			cout << "Форма обучения: " << uffMy[i].form << endl;
			cout << "		ОЦЕНКИ.\n" << "Физика. " << uffMy[i].oce[0] << "\n" << "История. " << uffMy[i].oce[1] << "\n" << "Алгебра. " << uffMy[i].oce[2] << endl;
			cout << "Программирование. " << uffMy[i].oce[3] << "\n" << "МатАнализ. " << uffMy[i].oce[4] << "\n" << "Информатика. " << uffMy[i].oce[5] << endl;
			cout << "Философия. " << uffMy[i].oce[6] << "\n" << "Экономика. " << uffMy[i].oce[7] << endl;
			cout << "Пол " << uffMy[i].s << endl;
			cout << "Дата формата (год месяц день час мин сек).\n " << "Год: " << uffMy[i].d[0] << " Месяц: " << uffMy[i].d[1] << " День: " << uffMy[i].d[2];
			cout << " Час: " << uffMy[i].d[3] << " Мин: " << uffMy[i].d[4] << " Сек: " << uffMy[i].d[5] << endl;
		}
	}
	/*cout << "тест подсчёта " << p << endl;*/
}
void ReadFile(int kol) //работа с файлом Text.txt я знаю что по заданию название students
{
	cout << "\n Загрузка файла Text.txt \n";
	ifstream file("Text.txt");
	if (!file)
	{
		cout << "Файл не открыт!!!\n";
	}
	else
	{
		cout << "Всё работает. Файл открыт!\n";
	}
	for (int i = 0; i < kol; i++)
	{
		file >> mstudent[i].num_gr;
		file >> mstudent[i].num_list;
		for (int j = 0; j < 8; ++j) {
			file >> mstudent[i].ocenki[j];
		}
		file >> mstudent[i].forma;
		for (int j = 0; j < 3; ++j) {
			file >> mstudent[i].fio[j];
		}
		file >> mstudent[i].sex;
		for (int j = 0; j < 6; ++j) {
			file >> mstudent[i].date[j];
		}
		file.get();
	}
	file.close();
}
int main()
{
M1:
	int xz = 0;
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "Russian");
	int lab = info(xz);
	if (lab == 1) {
		cout << setw(4) << "1.  Создание новой записи о студенте.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		vvod();
		goto M1;
	}
	if (lab == 2) {
		cout << setw(4) << "2.  Внесение изменений в уже имеющуюся запись.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		izmena(kol);
		goto M1;
	}
	if (lab == 3) {
		cout << setw(4) << "3.  Вывод всех данных о студентах.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		vivod(kol);
		goto M1;
	}
	if (lab == 4) {
		cout << setw(4) << "4.  Вывод информации обо всех студентах группы N.N - иницилизируется пользователем.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		num_gr(kol);
		goto M1;
	}
	if (lab == 5) {
		cout << setw(4) << "5.  Вывод топа самых успешных студентов с наивысшим по рейтингу средним балом за прошедшую сессию.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		topchik(kol);
		goto M1;
	}
	if (lab == 6) {
		cout << setw(4) << "6.  Вывод количества студентов мужского и женского пола.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		sex(kol);
		goto M1;
	}
	if (lab == 7) {
		cout << setw(4) << "7.  Определение количества студентов, которые будут получать стипендию(степендия начисляется,если у студента нет троек и очная форма обучения).\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		stipuxa(kol);
		goto M1;
	}
	if (lab == 8) {
		cout << setw(4) << "8.  Вывод данных о студентах, которые не получают стипендию; учатся только на `хорошо` и `отлично`; учатся только на `отлично`.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		netu(kol);
		goto M1;
	}
	if (lab == 9) {
		cout << setw(4) << "9.  Вывод данных о студентах, имеющих номер в списке - k.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		list(kol);
		goto M1;
	}
	if (lab == 10) {
		cout << setw(4) << "10. Вывод всех записей, сделанных в день, который введёт пользователь.\n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		PM(kol);
		goto M1;
	}
	if (lab == 11) {
		cout << "\n GEME OVER \n";
		return 0;
	}
	if (lab == 12) {
		cout << setw(4) << "12. Загрузить данные из файла. \n";
		cout << "####@@@@!!!!$$$$___%%%%^^^^&&&&****~~~~";
		shet(kol);
		ReadFile(kol);
		goto M1;
	}
	return 0;
}
