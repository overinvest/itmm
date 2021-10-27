#define _CRT_SECURE_NO_WARNINGS
#include "Algoritms.h"
#include "main_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "menu_handler.h"

typedef struct item {
	int id;
	char* name;
	int is_active;
	void (*callback)(char*);
} item;

/*
class menu {
public:

	void create_item(const char* const _Format) {
		item new_item { this->id, _Format, false };

		int idx = id + 1;

		items = (item*)malloc(idx * sizeof(new_item));
		items[id++] = new_item;
	}

	void print_out() {
		for (int i = 0; i < id; i++) {
			items[i].print_out();
		}
	}

	void clear() {
		system("cls"); // очищаем экран
	}

	void do_handle() {
		int res;
		int scan_result;
		bool exit = false;

		do {
			scan_result = scanf("%d", &res);

			items[res].is_active = true;
			item_selected = true;
			clear();

		} while (item_selected == false && (res < 0 || res > id) && scan_result != 1);

		do {
			int exit_code = scanf("%d", &res);

			if (exit_code == 0) {
				clear();
				item_selected = false;
				exit = true;
				print_out();
			}
		} while (item_selected == true && exit == false);
	}
	
private:
	item* items;
	int id = 0;
	bool item_selected = false;
};

*/

void print_out_item(item* var) {
	print("%d. %s", (*var).id, (*var).name);
}

void print_out_items(item** items, int idx) {
	for (int i = 0; i < idx; i++) {
		item current_item = (*items)[i];
		print("%d. %s", current_item.id, current_item.name);
	}
}

void clear() {
	system("cls"); // очищаем экран
}

void create_item(const char* const name, int* idx, item** items, void(*callback)(void) ) {
	int len = strlen(name) + 2;
	item new_item;
	new_item.name = (char*)calloc(len, sizeof(char));
	new_item.id = (*idx);
	strcpy(new_item.name, name);
	new_item.is_active = 0;
	new_item.callback = callback;
	(*items)[(*idx)] = new_item;
	(*idx)++;
	(*items) = (item*)realloc((*items), ((*idx) + 1) * sizeof(item));
}

int show_items(int* item_selected, item** items, int idx) {
	int res;
	int scan_result;

	print_out_items(items, idx);

	scan_result = scanf("%d", &res);

	if ((res < 0 || res > idx) || scan_result != 1) {
		do {

			print("Не могу найти такой элемент в меню, попробуйте еще раз");
			scan_result = scanf("%d", &res);

		} while ((res < 0 || res > idx) && scan_result == 1);
	}
	
	do {

		(*items)[res].is_active = 1;
		(*item_selected) = 1;
		clear();

	} while ( (*item_selected) == 0 );

	show_item(items, item_selected, res, idx);

	return 0;
}

int show_item(item** items, int* item_selected, int res, int idx) {

	int scan_res;
	int exit_code;

	elem_callback((*items)[res].name, (*items)[res].callback);
	exit_code = scanf("%d", &scan_res);

	if (scan_res != 0 || exit_code != 1) {
		do {

			print("чтобы выйти напишите 0");
			exit_code = scanf("%d", &scan_res);

		} while (scan_res != 0 || exit_code != 1);
	}

	clear();
	(*item_selected) = 0;
	(*items)[res].is_active = 0;

	show_items(item_selected, items, idx);
	return 0;
}

int elem_callback(char* name, int (*callback)(void)) {
	print("Выполняется: %s", name);

	callback();

	print("Алгоритм выполнился, чтобы выйти напишите 0");
	return 0;
}

void create_menu() {

	item* items;
	int idx = 0;
	items = (item*)malloc(1 * sizeof(item));

	create_item("1 Алгоритм", &idx, &items, Algoritm1);
	create_item("2 Алгоритм", &idx, &items, Algoritm2);
	create_item("3 Алгоритм", &idx, &items, Algoritm3);
	create_item("6 Алгоритм", &idx, &items, Algoritm6);
	create_item("7 Алгоритм", &idx, &items, Algoritm7);
	create_item("8 Алгоритм", &idx, &items, Algoritm8);

	//print("%s", new_elem.name);

	int exit = 0;
	int item_selected = 0;
	int full_exit = 0;

	int res = show_items(&item_selected, &items, idx);
}

