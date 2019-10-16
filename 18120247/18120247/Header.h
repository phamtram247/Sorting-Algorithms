#include <iostream>
#include <time.h>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void swap(int& a, int& b);
void inMang(int a[], int n);
void sapXepChon(int a[], int n);
void sapXepChen(int a[], int n);
void sapXepVo(int a[], int n);
int timKiemNhiPhan(int a[], int vat, int trai, int phai);
void sapXepChenNhiPhan(int a[], int n);
void sapXepNoi(int mang[], int n);
void sapXepLac(int mang[], int m);
int partition(int mang[], int trai, int phai);
void sapXepNhanh(int mang[], int trai, int phai);
