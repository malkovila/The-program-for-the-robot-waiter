#include <map>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <chrono>
#include <vector>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>
#pragma warning(disable : 4996)
using namespace std;


/*
k - kitchen
x - empty
f - fontan
tx - table and its number
c - children room
*/
class Cell {
public:
	string value = "X";
};

class Restaurant_field {
public:
	vector<vector<Cell>> field;
	vector<vector<int>> count_of_steps;
	map<string, vector<vector<int>>> tables = {
		{"t1", { {1, 2}, {1, 2}}},
		{"t2", { {1, 2}, {5, 6}}},
		{"t3", { {1, 2}, {9, 10}}},
		{"t4", { {1, 2}, {13, 14}}},
		{"t5", { {14, 19}, {1, 6}}},
		{"t6", { {4, 5}, {3, 4}}},
		{"t7", { {4, 5}, {7, 8}}},
		{"t8", { {4, 5}, {11, 12}}},
		{"t9", { {8, 10}, {11, 13}}},
		{"t10", { {14, 15}, {9, 10}}},
		{"t11", { {17, 18}, {9, 10}}},
		{"t12", { {14, 15}, {13, 14}}},
		{"t13", { {17, 18}, {13, 14}}},
	};
	string name;
	int size_x;
	int size_y;
	Restaurant_field(string name, int x, int y) {
		this->name = name;
		this->size_x = x;
		this->size_y = y;
	}
	void create_field(){
		for (int i = 0; i < size_y; i++){
			vector<Cell> a;
			vector<int> a1;
			for (int j = 0; j < size_x; j++)
			{ 
				Cell cell;
				a.push_back(cell);
				a1.push_back(999);
			}
			field.push_back(a);
			count_of_steps.push_back(a1);
		}
	}
	void change_field(int x, int y, string type) {
		field[x][y].value = type;
	}
	void change_fieldd() {
		for (int i = 16; i < 20; i++) {
			for (int j = 0; j < get_size_x() - 6; j++)
			{
				change_field(i, j, "K");
			}
		}
		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < 3; j++)
			{
				change_field(i, j, "t1");
			}
		}
		for (int i = 5; i < 7; i++) {
			for (int j = 1; j < 3; j++)
			{
				change_field(i, j, "t2");
			}
		}
		for (int i = 9; i < 11; i++) {
			for (int j = 1; j < 3; j++)
			{
				change_field(i, j, "t3");
			}
		}
		for (int i = 13; i < 15; i++) {
			for (int j = 1; j < 3; j++)
			{
				change_field(i, j, "t4");
			}
		}
		for (int i = 1; i < 7; i++) {
			for (int j = 14; j < 20 - 1; j++)
			{
				change_field(i, j, "t5");
			}
		}
		for (int i = 3; i < 8; i++) {
			for (int j = 7; j < 10; j++)
			{
				change_field(i, j, "F");
			}
		}
		for (int i = 3; i < 5; i++) {
			for (int j = 4; j < 6; j++)
			{
				change_field(i, j, "t6");
			}
		}
		for (int i = 7; i < 9; i++) {
			for (int j = 4; j < 6; j++)
			{
				change_field(i, j, "t7");
			}
		}
		for (int i = 11; i < 13; i++) {
			for (int j = 4; j < 6; j++)
			{
				change_field(i, j, "t8");
			}
		}
		for (int i = 11; i < 14; i++) {
			for (int j = 8; j < 11; j++)
			{
				change_field(i, j, "t9");
			}
		}
		for (int i = 9; i < 11; i++) {
			for (int j = 14; j < 16; j++)
			{
				change_field(i, j, "t10");
			}
		}
		for (int i = 9; i < 11; i++) {
			for (int j = 17; j < 19; j++)
			{
				change_field(i, j, "t11");
			}
		}
		for (int i = 13; i < 15; i++) {
			for (int j = 14; j < 16; j++)
			{
				change_field(i, j, "t12");
			}
		}
		for (int i = 13; i < 15; i++) {
			for (int j = 17; j < 19; j++)
			{
				change_field(i, j, "t13");
			}
		}
		for (int i = 17; i < 20; i++) {
			for (int j = 15; j < 19; j++)
			{
				change_field(i, j, "C");
			}
		}





	}//расставляем столы, детскую, фонтан 
	void count_steps(int start_x, int start_y){
		count_of_steps[start_x][start_y] = 0;
		for (int i = start_x; i < 20; i++)
		{
			for (int j = start_y; j < 20; j++)
			{
				if (i == start_x and j == start_y) {
					continue;					
				}
				if(field[i][j].value=="X")
				count_of_steps[i][j] = min(count_of_steps[i - 1][j], count_of_steps[i][j - 1]) + 1;

			}
		}
		for (int i = start_x; i >=0; i--)
		{
			for (int j = start_y; j < 20; j++)
			{
				if (i == start_x and j == start_y) {
					continue;
				}
				if (field[i][j].value == "X")
				count_of_steps[i][j] = min(count_of_steps[i + 1][j], count_of_steps[i][j - 1]) + 1;

			}
		}
		for (int i = start_x; i < 20; i++)
		{
			for (int j = start_y; j >= 0; j--)
			{
				if (i == start_x and j == start_y) {
					continue;
				}
				if (field[i][j].value == "X")
				count_of_steps[i][j] = min(count_of_steps[i - 1][j], count_of_steps[i][j + 1]) + 1;

			}
		}
		for (int i = start_x; i >= 0; i--)
		{
			for (int j = start_y; j >= 0; j--)
			{
				if (i == start_x and j == start_y) {
					continue;
				}
				if (field[i][j].value == "X")
				count_of_steps[i][j] = min(count_of_steps[i + 1][j], count_of_steps[i][j + 1]) + 1;

			}
		}


	}
	
	void show_field(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < size_y; i++) {
			for (int j = 0; j < size_x; j++)
			{
				if (field[i][j].value == "K") {
					SetConsoleTextAttribute(hConsole, 12);
					cout << std::setw(4) << field[i][j].value;
				}
				else if (field[i][j].value == "X") {
					SetConsoleTextAttribute(hConsole, 7);
					cout << std::setw(4) <<field[i][j].value;
				}
				else if (field[i][j].value == "O") {
					SetConsoleTextAttribute(hConsole, 14);
					cout << std::setw(4) << field[i][j].value;
				}
				else if (field[i][j].value == "C") {
					SetConsoleTextAttribute(hConsole, 13);
					cout << std::setw(4) << field[i][j].value;
				}
				else if (field[i][j].value == "F") {
					SetConsoleTextAttribute(hConsole, 9);
					cout << std::setw(4) << field[i][j].value;
				}
				else if (find(field[i][j].value.begin(), field[i][j].value.end(), 't') != field[i][j].value.end()) {
					SetConsoleTextAttribute(hConsole, 10);
					cout << std::setw(4) << field[i][j].value;
				}
			}
			cout << endl;
		}
	}
	void show_fieldd() {
		for (int i = 0; i < size_y; i++) {
			for (int j = 0; j < size_x; j++)
			{
					cout << setw(4) << count_of_steps[i][j];
				
			}
			cout << endl;
		}
	}//показываем количество шагов для всех клеток
	int get_size_x() {
		return size_x;
	}
	int get_size_y() {
		return size_y;
	}
};
class Order {
public:
	string order;
	string table;
	int count_of_people;
	time_t time;
	string status;
};

class Robot {
protected:
	string name;
	int position_x;
	int position_y;
	map<string, Order> orders;
public:
	Robot(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
	pair<int, int> get_coord_table(string table, Restaurant_field r) {
		pair<int, int> cord;
		int x_table_st = r.tables[table][0][0];//x1 = 1 x2 = 2  y1 = 1 y2 = 2
		int x_table_end = r.tables[table][0][1];//x1 = 1 x2 = 2  y1 = 1 y2 = 2
		int x;
		int y_table_st = r.tables[table][1][0];//x1 = 1 x2 = 2  y1 = 1 y2 = 2
		int y_table_end = r.tables[table][1][1];//x1 = 1 x2 = 2  y1 = 1 y2 = 2
		int y;
		if (abs(x_table_st - position_x) < abs(x_table_end - position_x)) x = x_table_st;
		else x = x_table_end;
		if (abs(y_table_st - position_y) < abs(y_table_end - position_y)) y = y_table_st;
		else y = y_table_end;
		cord.first = x;
		cord.second = y;
		return cord;
	}
	vector<pair<int, int>> marshrut(string table, Restaurant_field &r) {
		vector<pair<int, int>> res;
		int x = get_coord_table(table, r).first;
		int y = get_coord_table(table, r).second;
		/*if (position_x > x and position_y > y) {
			while (position_x != x or position_y != y) {
				pair<int, int> a;
				if (position_x == x) {
					a.first = position_x;
					a.second = position_y-1;
					position_y -= 1;
					res.push_back(a);
				}
				else if (position_y == y and r.field[position_y][position_x-1].value == "X") {
					a.first = position_x-1;
					a.second = position_y;
					position_x -= 1;
					res.push_back(a);
				}
				else if (r.count_of_steps[position_y - 1][position_x] > r.count_of_steps[position_y][position_x - 1]) {
					a.first = position_x;
					a.second = position_y - 1;
					position_y -= 1;
					res.push_back(a);
				}
				else {
					a.first = position_x - 1;
					a.second = position_y;
					position_x -= 1;
					res.push_back(a);
				}
			}
		}*/
		int start_f = 999;
		while (x != position_x or y != position_y) {
			if (r.count_of_steps[y][x - 1] == min(min(min(r.count_of_steps[y][x - 1], r.count_of_steps[y - 1][x]), r.count_of_steps[y][x + 1]), r.count_of_steps[y + 1][x])) {
				x--;
				pair<int, int> el;
				el.first = x;
				el.second = y;
				res.push_back(el);
			}
			else if (r.count_of_steps[y - 1][x] == min(min(min(r.count_of_steps[y][x - 1], r.count_of_steps[y - 1][x]), r.count_of_steps[y][x + 1]), r.count_of_steps[y + 1][x])) {
				y--;
				pair<int, int> el;
				el.first = x;
				el.second = y;
				res.push_back(el);
			}
			else if (r.count_of_steps[y][x+1] == min(min(min(r.count_of_steps[y][x - 1], r.count_of_steps[y - 1][x]), r.count_of_steps[y][x + 1]), r.count_of_steps[y + 1][x])) {
				x++;
				pair<int, int> el;
				el.first = x;
				el.second = y;
				res.push_back(el);
			}
			else if (r.count_of_steps[y + 1][x] == min(min(min(r.count_of_steps[y][x - 1], r.count_of_steps[y - 1][x]), r.count_of_steps[y][x + 1]), r.count_of_steps[y + 1][x])) {
				y++;
				pair<int, int> el;
				el.first = x;
				el.second = y;
				res.push_back(el);
			}
		}

		return res;
	}
	void get_order(string table, Restaurant_field &r) {
		cout << "Подъезжаем к столику! " << endl;
		Sleep(2000);
		vector<pair<int, int>> res = marshrut(table, r);
		for (int i = res.size()-1; i >=0; i--){
			system("cls");
			r.field[res[i].second][res[i].first].value = "O";
			r.show_field();
			Sleep(300);
			
		}
	}
	void take_order(string table) {
		cout << "Прием заказа..." << endl;
		Order order;
		int count;
		string ord;
		cout << "Сколько вас человек? " << endl;
		cin >> count; 
		order.count_of_people = count;
		cout << "Что будете заказывать? " << endl;
		cin >> ord;
		order.order = ord;
		order.table = table;

		order.time = std::time(NULL);
		orders[table] = order;


	}
	void put_order(string table) {
		
			cout << "Отдача заказа..." << endl;
			Sleep(1000);
			cout << "Ваш заказ: " << orders[table].order;
			orders.erase(table);
	}
	map<string, Order> orderss(){
		return orders;
	}
	void show_all_open_orders() {
		for (auto k :orders) {
			cout << "Столик: " << k.first << endl;
			cout << "Количество человек: " << k.second.count_of_people << endl;
			cout << "Заказ: " << k.second.order << endl;
			cout << "Принят в : " << put_time(std::localtime(&k.second.time), "%F %T") << endl;
			cout << endl;

		}
	}
	void come_back(string table, Restaurant_field& r) {
		cout << " Возвращаемся на базу! " << endl;
		Sleep(2000);
		vector<pair<int, int>> res = marshrut(table, r);
		for (int i = 0; i < res.size(); i++) {
			system("cls");
			r.field[res[i].second][res[i].first].value = "X";
			r.show_field();
			Sleep(300);

		}
	}
	void set_coord(int position_x, int position_y) {
		this->position_x = position_x;
		this->position_y = position_y;
	}
};


int main() {
	setlocale(LC_ALL, "RU");
	Restaurant_field rest1("Clod Mone", 20, 20);
	Robot s("Илья");
	rest1.create_field();
	rest1.change_fieldd();
	rest1.count_steps(15, 5);//считаем шаги для всех клеток 
	s.set_coord(5, 15);//начальные координаты робота
	rest1.show_field();
	while (true) {
		string command;
		cout << "Введите команду: ";
		cin >> command;
		if (find(command.begin(), command.end(), 't') != command.end()) {
			s.get_order(command, rest1); //подъезжаем к столику
			map<string, Order> orders = s.orderss();
			if (orders.find(command) == orders.end())
				s.take_order(command);
			else s.put_order(command);
			s.come_back(command, rest1);
		}
		else if (command == "Orders") {
			s.show_all_open_orders();
		}
	}
}


	
	
	




