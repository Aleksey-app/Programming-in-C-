// ПрактическаяРабота№2.cpp 
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
int main()
{
	const int a = 100;
	short A[a];
M1:
	auto start = std::chrono::system_clock::now();
	int q, max = A[0], min = A[0], ser = 0, o = 0, n;
	auto srand(time(0));
	for (int i = 0; i < a; i++)
		A[i] = rand() % (199 - 1) - 99;
	auto end = std::chrono::system_clock::now();
	for (int i = 0; i < a; i++)
		cout << "A[" << i << "]=" << A[i] << "\n";
	std::chrono::duration<double> diff = end - start;
	cout << "\n" << "Time: " << diff.count() << "s";
	cout << "\n" << "Create data array: 1 " << "\n" << "Start sorting: 2" << "\n" << "Start searching for max and min element: 3" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	default:	cout << "ERROR \n";
	}
M2:
	start = chrono::system_clock::now();
	for (int i = 1; i < a; i++)
	{
		int x = A[i];
		int j = i;
		while ((j > 0) && (x < A[j - 1]))
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = x;
	}
	end = chrono::system_clock::now();
	for (int i = 0; i < a; i++)
	{
		cout << setw(5) << left << A[i];

	}
	chrono::duration<double> set = end - start;
	cout << "\n" << "Time: " << set.count() << "s";
	cout << "\n" << "Create data array: 1 " << "\n" << "Start sorting: 2" << "\n" << "Start searching for max and min element: 3" << "\n Mean: 4" << "\n Item: 5" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	default:	cout << "ERROR \n";
	}
M3:
	start = chrono::system_clock::now();
	for (int i = 0; i < a; i++)
		if (A[i] > max)
			max = A[i];
	for (int i = 0; i < a; i++)
		if (A[i] < min)
			min = A[i];
	end = chrono::system_clock::now();
	cout << "Min: " << min << "\n" << "Max: " << max << "\n";
	std::chrono::duration<double> tide = end - start;
	cout << "\n" << "Time sorted data array: " << tide.count() << "s";
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	default:	cout << "ERROR \n";
	}
M4:
	ser = (max + min) / 2;
	cout << "\n" << ser << " Mean" << "\n";
	for (int i = 0; i < a; i++)
	{
		if (A[i] == ser)
		{
			cout << "A[" << i << "]" << " number " << "\n";
			++o;
		}
	}
	cout << "number of array elements = " << ser << "= " << o;
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n Next: 5" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	default:	cout << "ERROR \n";
	}
M5:
	int e = 0;
	cout << "\n Enter the number ";
	cin >> n;
	cin.sync();
	for (int i = 0; i < a; i++)
	{
		if (A[i] < n)
		{
			++e;
		}
	}
	cout << "The number of elements is less  " << n << "= " << e;
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n Back: 5" << "\n Next: 6" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	case 6: goto M6;
	default:	cout << "ERROR \n";
	}
M6:
	int p = 0;
	cout << "\n Enter the number ";
	cin >> n;
	cin.sync();
	for (int i = 0; i < a; i++)
	{
		if (A[i] > n)
		{
			++p;
		}
	}
	cout << "The number of elements is greater  " << n << "= " << p;
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n Item: 5" << "\n Repeat: 6" << "\n Next: 7" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	case 6: goto M6;
	case 7: goto M7;
	default:	cout << "ERROR \n";
	}
M7:
	cout << "\n Enter the number ";
	cin >> n;
	cin.sync();
	int h = 0;
	int s = -1;
	int l = a;
	start = chrono::system_clock::now();
	while (h <= l)
	{
		int mid = (h + l) / 2;
		if (n == A[mid])
		{
			s = mid;
			break;
		}
		if (n < A[mid])
			l = mid - 1;
		else
			h = mid + 1;
	}
	end = chrono::system_clock::now();
	if (s == -1)
		cout << "The element not found!\n";
	else
		cout << "Yes\n";
	std::chrono::duration<double> xz = end - start;
	cout << "\n" << "Time sorted data array: " << xz.count() << "s";
	start = chrono::system_clock::now();
	int r = 0;
	for (int i = 0; i < a; i++)
	{
		if (A[i] == n)
		{
			++r;
		}
	}
	end = chrono::system_clock::now();
	cout << "\n Search by brute force  " << n << " coincidences = " << r;
	std::chrono::duration<double> acdc = end - start;
	cout << "\n" << "Time sorted data array: " << acdc.count() << "s";
	cout << "\n Difference:" << "Brute force -" << " binary search " << acdc.count() - xz.count() << " s";
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n Item: 5" << "\n Item: 6" << "\n Repeat: 7" << "\n Next: 8" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	case 6: goto M6;
	case 7: goto M7;
	case 8: goto M8;
	default:	cout << "ERROR \n";
	}
M8:
	for (int i = 0; i < a; i++)
		cout << "A[" << i << "]=" << A[i] << " WAS" << "\n";
	int w;
	cout << "Write 0 < A  & B < 99 : \n";
	cin >> n >> w;
	cin.sync();
	start = chrono::system_clock::now();
	int tmp;
	tmp = A[n];
	A[n] = A[w];
	A[w] = tmp;
	end = chrono::system_clock::now();
	for (int i = 0; i < a; i++)
		cout << "A[" << i << "]=" << A[i] << " Became" << "\n";
	std::chrono::duration<double> yo = end - start;
	cout << "\n" << "Time sorted data array: " << yo.count() << "s";
	cout << "\n" << "\n Create data array: 1 " << "\n Start sorting: 2" << "\n Start searching for max and min element: 3" << "\n Mean: 4" << "\n Item: 5 " << "\n Item: 6" << "\n Item: 7" << "\n Repeat: 8" << "\n";
	cin >> q;
	cin.sync();
	switch (q)
	{
	case 1: goto M1;
	case 2: goto M2;
	case 3: goto M3;
	case 4: goto M4;
	case 5: goto M5;
	case 6: goto M6;
	case 7: goto M7;
	case 8: goto M8;
	default:	cout << "\n the project is over \n";
	}
	return 0;
}