
#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void GenerateRandomData(int a[], int n)// Hàm phát sinh mảng dữ liệu ngẫu nhiên
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
//
void GenerateSortedData(int a[], int n)// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
//
void GenerateReverseData(int a[], int n)// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
//
void GenerateNearlySortedData(int a[], int n)// Hàm phát sinh mảng dữ liệu gần như có thứ tự
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void sapXepChon(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int viTriNhoNhat = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[viTriNhoNhat])
				viTriNhoNhat = i;
		}
		swap(a[viTriNhoNhat], a[i]);
	}
}

void sapXepChen(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}

void sapXepVo(int a[], int n)
{
	for (int loTrong = n / 2; loTrong > 0; loTrong /= 2)
	{
		for (int i = loTrong; i < n; i++)
		{
			int tam = a[i];
			int j;
			for (j = i; j >= loTrong && a[j - loTrong] > tam; j -= loTrong)
				a[j] = a[j - loTrong];
			a[j] = tam;
		}
	}
}

int timKiemNhiPhan(int a[], int vat, int trai, int phai)
{
	if (phai <= trai)
		if (vat > a[trai])
			return trai + 1;
		else
			return trai;
	int giua = (trai + phai) / 2;
	if (vat == a[giua])
		return timKiemNhiPhan(a, vat, giua + 1, phai);
	return timKiemNhiPhan(a, vat, trai, giua - 1);
}
void sapXepChenNhiPhan(int a[], int n)
{
	int i, tam, j, k, chon;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		chon = a[i];

		tam = timKiemNhiPhan(a, chon, 0, j);

		while (j >= tam)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = chon;
	}
}

void sapXepNoi(int mang[], int n)
{
	int i, j;
	bool daHoanVi = false;
	for (i = 0; i < n - 1; i++)
	{

		daHoanVi = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (mang[j] > mang[j + 1])
			{
				swap(mang[j], mang[j + 1]);
				daHoanVi = true;
			}
		}
		if (daHoanVi == false)
		{
			break;
		}
	}
}

void sapXepLac(int mang[], int m)
{
	int i, j, k;
	for (i = 0; i < m;) {
		for (j = i + 1; j < m; j++) {
			if (mang[j] < mang[j - 1])
				swap(mang[j], mang[j - 1]);
		}
		m--;
		for (k = m - 1; k > i; k--) {
			if (mang[k] < mang[k - 1])
				swap(mang[k], mang[k - 1]);
		}
		i++;
	}
}


//void inMang(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//}

int main()
{
	int mang[10000];
	int n = 10000;
	clock_t t1, t2;
	t1 = clock();
	GenerateRandomData(mang, n);
	sapXepLac(mang, n);
	t2 = clock() - t1;
	cout << endl << "Time: " << (float)t2 / CLOCKS_PER_SEC << endl;
	return 0;
}