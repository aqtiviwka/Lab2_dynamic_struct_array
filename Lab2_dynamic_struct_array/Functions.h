#pragma once

#include<iostream>	
#include<fstream>
#include<Windows.h>
#include<memory.h>

using namespace std;

struct Product
{
	char name[30];
	int amount;
	int workshop;
};

void ProductEntry(Product* (&p), int& n);
void ReadingProduct(Product* (&p), int& n, char filename[]);
void Print(Product* p, int n);
void ProductChange(Product* (&p), int n);
void DeleteProduct(Product* (&p), int& n);
void Copy(Product* (p_new), Product* (&p_old), int n);
void SwapElement(Product& p_new, Product& p_old);
void AddProduct(Product* (&p), int& n);
void SavingProduct(Product* p, int n, char filename[]);
void ProductSort(Product* p, int n);
void LinearSearch(Product* p, int n);
void SelectionSortProduct(Product* p, int n);
void QuickSortProduct(Product* p, int first, int last);
void BinarySearchProduct(Product* p, int n);