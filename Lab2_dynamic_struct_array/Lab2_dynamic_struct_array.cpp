#include "Functions.h"

int key_menu;
void Menu() {
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Удаление" << endl
		<< "(5) Добавление" << endl
		<< "(6) Поиск и Сортировка" << endl
		<< "(7) Сохранение" << endl
		<< "Ваш выбор: ";
	cin >> key_menu;

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	int actions, amountOfProduct = 0;
	char filename[15];

	Product* p = new Product[amountOfProduct];

	while (key_menu !=0)
	{
		switch (key_menu) {
		case 1:
			system("cls");

			cout << "Ввод  выполнить:\n1. Вручную\n2. Из файла?: "<<endl;
			cin >> actions;

			system("cls");

			if (actions == 1) {
				ProductEntry(p,amountOfProduct);
			}
			else {
				cout << "Введите название файла: ";
				cin >> filename;
				ReadingProduct(p, amountOfProduct,filename);
			}
			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfProduct != 0) {
				Print(p, amountOfProduct);
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (amountOfProduct != 0) {
				ProductChange(p, amountOfProduct);
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");

			if (amountOfProduct != 0) {
				DeleteProduct(p, amountOfProduct);
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");

			if (amountOfProduct != 0) {
				AddProduct(p, amountOfProduct);
				amountOfProduct++;
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");

			if (amountOfProduct != 0) {
				cout << "Выберите действие:\n1. Линейный поиск и быстрая сортировка\n2. Бинарный поиск и сорбировка выбором" << endl;
				cin >> actions;
				if (actions == 1) {
					LinearSearch(p, amountOfProduct);
				}
				else if (actions == 2) {
					BinarySearchProduct(p, amountOfProduct);
				}
				else {
					cout << "Такого действия не существует" << endl;
				}
				
				
			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			cout << "Введите название файла: ";
			cin >> filename;
			if (amountOfProduct != 0) {
				SavingProduct(p, amountOfProduct,filename);

			}
			else {
				cout << "Данные пусты!" << endl;
			}
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Неверно введен номер действия" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	delete[]p;
	return 0;
}

