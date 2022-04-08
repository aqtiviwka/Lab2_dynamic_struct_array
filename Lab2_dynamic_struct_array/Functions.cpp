#include "Functions.h"

void ProductEntry(Product* (&p), int& n) {
	cout << "������� ���������� ������: ";
	cin >> n;

	p = new Product[n];

	for (int i = 0; i < n; i++)
	{
		cout << "������� ������������ ���������: ";
		cin >> p[i].name;

		cout << "������� ����������: ";
		cin >> p[i].amount;

		cout << "������� ����� ����: ";
		cin >> p[i].workshop;

		cout << "_____________________________________" << endl;
	}
}
void ReadingProduct(Product* (&p), int& n, char filename[]) {
	ifstream reading(filename);

	if (reading)
	{
		reading >> n;
		p = new Product[n];

		for (int i = 0; i < n; i++)
		{
			reading >> p[i].name;
			reading >> p[i].amount;
			reading >> p[i].workshop;
		}
		cout << "������ �������!" << endl;
	}
	else
	{
		cout << "������ �������� �����!" << endl;
	}
	reading.close();
}
void Print(Product* p, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "������ �" << i + 1 << ":" << endl;
		cout << "������������ �������: " << p[i].name << endl;
		cout << "����������: " << p[i].amount << endl;
		cout << "����� ����: " << p[i].workshop << endl;
		cout << "_________________________________" << endl;
	}
}
void ProductChange(Product* (&p), int n) {
	int _n;
	cout << "������� ����� ��������(�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		cout << "������� ������������ ���������: ";
		cin >> p[_n].name;

		cout << "������� ����������: ";
		cin >> p[_n].amount;

		cout << "������� ����� ����: ";
		cin >> p[_n].workshop;

		system("cls");
		cout << "������ ��������!" << endl;
	}
	else {
		cout << " ����� ������ �� �����!" << endl;
	}
}
void DeleteProduct(Product*(&p),int&n) {
	int _n;
	cout << "������� ����� ��������(�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		Product* buf = new Product[n];

		Copy(buf, p, n);

		--n;
		p = new Product[n];
		
		int q = 0;

		for (int  i = 0; i < n; i++)
		{
			if (i != _n) {
				p[q] = buf[i];
				++q;
			}	
		}
		delete[]buf;
		system("cls");
		cout << "������ ��������!" << endl;
	}
	else {
		cout << "����� ������ �������!" << endl;
	}
}
void Copy(Product* (p_new), Product* (&p_old), int n) {
	for (int i = 0; i < n; i++)
	{
		p_new[i] = p_old[i];
	}
}
void SwapElement(Product& p_new, Product& p_old) {
	memcpy(p_new.name, p_old.name, sizeof p_old.name);
	p_new.amount = p_old.amount;
	p_new.workshop = p_old.workshop;
}
void AddProduct(Product* (&p), int& n) {
	Product* buf;
	buf = new Product[n];

	Copy(buf, p, n);

	n++;
	p = new Product[n];
	Copy(p, buf, --n);

	cout << "������� ������������ ���������: ";
	cin >> p[n].name;

	cout << "������� ����������: ";
	cin >> p[n].amount;

	cout << "������� ����� ����: ";
	cin >> p[n].workshop;
	cout << "������ ���������!" << endl;
	delete[]buf;
}
void SavingProduct(Product* p, int n, char filename[]) {
	ofstream record(filename, ios::out);
	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << p[i].name << endl;
			record << p[i].amount << endl;
			if (i < n - 1) {
				record << p[i].workshop << endl;
			}
			else {
				record << p[i].workshop;
			}
			
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	record.close();
}
void ProductSort(Product* p, int n) {
	Product buf;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (p[i].amount > p[j].amount) {
				SwapElement(buf, p[j]);
				SwapElement(p[j], p[i]);
				SwapElement(p[i], buf);

			}
		}
	}
	cout << "������ �������������!" << endl;
}
void LinearSearch(Product* p, int n) {
	int new_n = 0;
	int getWorkshop;
	cout << "������� ����� ����:";
	cin >> getWorkshop;
	for (int i = 0; i < n; i++)
	{
		if (getWorkshop == p[i].workshop) {
			new_n++;
		}
	}
	Product* WorkshopProduct = new Product[new_n];
	if (new_n > 0) {
		
		int q = 0;
		for (int i = 0; i < n; i++)
		{
			if (getWorkshop == p[i].workshop) {
				WorkshopProduct[q] = p[i];
				++q;
			}
		}
	}
	else {
		cout << "������ ���� �� ����������!" << endl;
	}

	QuickSortProduct(WorkshopProduct, 0, new_n-1);
	char resultname[15];
	cout << "������� �������� �����: ";
	cin >> resultname;
	SavingProduct(WorkshopProduct, new_n, resultname);
	delete[]WorkshopProduct;	
}
void SelectionSortProduct(Product* p, int n) {
	Product buf;
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i; 
		for (int j = i + 1; j < n; j++) 
		{
			if (p[j].amount > p[min].amount) 
				min = j;       
		}
		SwapElement(buf,p[i]);
		SwapElement(p[i], p[min]);
		SwapElement(p[min], buf);
		
	}
	cout << "������ �������������!" << endl;
}
void QuickSortProduct(Product* p, int first, int last) {
	if (first < last) {
		int left = first;
		int right = last;
		int middle = p[(left + right) / 2].amount;
		do {
			while (p[left].amount > middle)
			{
				left++;
			}
			while (p[right].amount < middle)
			{
				right--;
			}
			if (left <= right) {
				Product buf;
				SwapElement(buf, p[left]);
				SwapElement(p[left], p[right]);
				SwapElement(p[right], buf);
				left++;
				right--;
			}
		} while (left < right);
		QuickSortProduct(p, first, right);
		QuickSortProduct(p, left, last);
	}

}
void BinarySearchProduct(Product* p, int n) {
	SelectionSortProduct(p, n);
	int average_index = 0;
	int first_index = 0;
	int last_index = n - 1;
	cout << "������� ������� ��������� ������� ����� �������� ����������: ";
	int search_value;
	cin >> search_value;
	if (last_index == -1) cout << "��� ������ � �����" << endl;

	while (first_index < last_index) {
		average_index = first_index + (last_index - first_index) / 2;
		if (search_value >= p[average_index].amount) {
			last_index = average_index;
		}
		else {
			first_index = average_index + 1;
		}
	}
	if (p[last_index].amount == search_value) {
		cout << "������������ �������: " << p[last_index].name << endl;
		cout << "����������: " << p[last_index].amount << endl;
		cout << "����� ����: " << p[last_index].workshop << endl;
	}
	else {
		cout << "�������� � ����� ����������� ���������� ������� �� ����������" << endl;
	}


}
