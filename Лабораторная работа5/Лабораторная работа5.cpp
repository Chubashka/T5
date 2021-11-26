#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int arr_sort(int *arr, int n); // прототип функции сортировки

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, size; // размер массива
	bool f;
	char t;
	do
	{
		system("cls");
		do
		{
			cout << "Введите длину массива: ";
			cin >> n;
		} while (n <= 0);
		size = 0;
		int* arr = new int[n];
		int* arr2 = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; ++i)// заполнение массива случайными числами
		{
			arr[i] = rand() % (10 - 0 + 1) + 0;
		}
		cout << "Созданный массив: ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << " " << endl;
		for (int i = 0; i < n; i++)// обнулили массив где будут храниться элементы которые повторялись
		{
			arr2[i] = 0;
		}
		int k = 0;
		int k1 = 0;
		for (int l = 0; l < n; ++l)// проверка есть ли повторения
		{
			for (int l1 = l + 1; l1 < n; l1++)
			{
				if (arr[l] == arr[l1]) ++k;
			}
		}
		if (k == 0)// если в массиве нет повторений
		{
			for (int i = 0; i < n; i++)
			{
				f = true;
				for (int j = i + 1; j < n; j++)
				{
					if (arr[i] > arr[j])
					{
						f = false;
					}
				}
				if (f == false)
				{
					++k;
				}
			}
			if (k > 0) // массив не отсортирован 
			{
				cout << "В этом массиве нет повторений" << endl;
				arr_sort(arr, n);
				cout << "Отсортированный массив: ";
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				cout << " " << endl;
			}
			else // массив отсортирован
			{
				cout << "В этом массиве нет повторений" << endl;
			}
		}
		else// если в массиве есть повторения
		{
			for (int i = 0; i < n; i++) // заполнение 2 массива элементами которые повторяются
			{
				f = false;
				for (int j = i + 1; j < n; j++)
				{
					if (arr[i] == arr[j])
						f = true;
				}
				if (f == true)
				{
					++size;
					arr2[size - 1] = arr[i];
				}
			}
			// проверка есть ли повторения 
			for (int i = 0; i < size; i++)// дубликаты перемещаем в конец массива и удаляем
			{
				for (int j = i + 1; j < size; j++)
				{
					if (arr2[i] == arr2[j])
					{
						for (int cout = j; cout < size - 1; cout++)
						{
							arr2[cout] = arr2[cout + 1];
						}
						--size;
						if (arr2[i] == arr2[j]) //если >2 дубликатов находятся рядом
						{
							--j;
						}
					}
				}
			}
			if (size == 1) // если 1 элемент в массиве
			{
				cout << "Mассив состоящий из элементов которые повторялись: ";
				for (int i = 0; i < size; i++)
				{
					cout << arr2[i] << " ";
				}
				cout << " " << endl;
			}
			else // >1 элемента в массиве
			{
				for (int i = 0; i < size; i++)
				{
					f = true;
					for (int j = i + 1; j < size; j++)
					{
						if (arr2[i] > arr2[j])  f = false;
					}
					if (f == false)
					{
						++k1;
					}

				}
				if (k1 > 0) // если массив не отсортирован
				{
					cout << "Неотсортированный массив состоящий из элементов которые повторялись: ";
					for (int i = 0; i < size; i++)
					{
						cout << arr2[i] << " ";
					}
					cout << " " << endl;
					arr_sort(arr2, size);
					cout << "Отсортированный массив состоящий из элементов которые повторялись: ";
					for (int i = 0; i < size; i++)
					{
						cout << arr2[i] << " ";
					}
					cout << " " << endl;
				}
				else// если массив отсортирован
				{
					cout << "Массив состоящий из элементов которые повторялись: ";
					for (int i = 0; i < size; i++)
					{
						cout << arr2[i] << " ";
					}
					cout << " " << endl;
				}
			}
		}
		delete[]arr;
		delete[]arr2;
		cout << "Хотите еще раз запустить программу?(y/n)";
		cin >> t;
	} while (t == 'y');
	system("pause");
}

int arr_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int nMin = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[nMin]) nMin = j;
		}
		if (nMin != i)
		{
			int c = arr[i];
			arr[i] = arr[nMin];
			arr[nMin] = c;
		}
	}
	return(*arr);
}