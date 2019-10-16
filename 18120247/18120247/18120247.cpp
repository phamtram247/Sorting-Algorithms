#include "Header.h"

void testRandomArray(void (*fun[])(int[], int), int size[5], int a[])
{
	fstream fout;
	fout.open("damn.txt", ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			clock_t t1, t2;
			t1 = clock();
			fun[j](a, size[i]);
			//inMang(a, size[i]);
			t2 = clock() - t1;
			//cout << endl << "Time: " << (float)t2 / CLOCKS_PER_SEC;
			//fout << size[i];
			fout << (float)t2 / CLOCKS_PER_SEC << "\t";
		}
		fout << endl;
	}
	fout << "~~ \n";
	fout.close();
	cout << "Da sap xong" << endl;
}
void sxNhanh(int mang[], int n)
{
	sapXepNhanh(mang, 0, n - 1);
}
int main()
{
	int size[] = { 100,500,10000,30000,100000 };
	void (*fun[7])(int[], int) = {/*sapXepChon, sapXepChen, sapXepVo, sapXepChenNhiPhan,*/ sapXepNoi, sapXepLac, sxNhanh};
	int arr[100000];
	GenerateRandomData(arr, 100000);
	testRandomArray(fun, size, arr);
	//
	
	return 0;
}