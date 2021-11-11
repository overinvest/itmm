#define _CRT_SECURE_NO_WARNINGS
#include "Algoritms.h"
#include "main_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "menu_handler.h"

enum {
	ESC = 27,
	ENTER = 13,
	ARROW = 224,
	YES = 121
};

typedef struct item {
	int id;
	char* name;
	int is_active;
	void (*callback)(char*);
} item;

void print_out_item(item var) {
	print("%d. %s", var.id, var.name);
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

	int start_index = 0;

	int code = -1;

	do {

		clear();

		print("Вот меню:");
		for (int i = 0; i < idx; i++) {

			if (i == start_index) {
				SetColor(0, 15);
				printf("%d. %s", (*items)[i].id, (*items)[i].name);
				SetColor(15, 0);
				printf("\n");
			}
			else {
				printf("%d. %s", (*items)[i].id, (*items)[i].name);
				printf("\n");
			}

		}

		code = getch();

		if ( code == ARROW) {
			start_index++;
		}

		if (start_index > idx) {
			start_index = 0;
		}

	} while ( code != ENTER );
	
	do {

		(*items)[start_index].is_active = 1;
		(*item_selected) = 1;
		clear();

	} while ( (*item_selected) == 0 );

	show_item(items, item_selected, start_index, idx);

	return 0;
}

int show_item(item** items, int* item_selected, int res, int idx) {

	int scan_res;
	int exit_code;

	elem_callback((*items)[res].name, (*items)[res].callback);
	exit_code = 0;

	print("чтобы выйти нажмите ESC");

	do {

		int code = getch();

		if (code == ESC) {
			exit_code = 1;
		}

	} while ( exit_code != 1 );


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
	create_item("4 Алгоритм", &idx, &items, Algoritm4);
	create_item("5 Алгоритм", &idx, &items, Algoritm5);
	create_item("6 Алгоритм", &idx, &items, Algoritm6);
	create_item("7 Алгоритм", &idx, &items, Algoritm7);
	create_item("8 Алгоритм", &idx, &items, Algoritm8);
	create_item("9 Алгоритм", &idx, &items, Algoritm9);
	create_item("10 Алгоритм", &idx, &items, Algoritm10);

	int item_selected = 0;

	int res = show_items(&item_selected, &items, idx);

}

void start() {

	print("Привет! Добро пожаловать в бета-версию меню");
	print("Желаете открыть меню? (Напишите y для открытия меню, или любую другу клавишу чтобы завершить программу)");

	if (getch() == YES) {
		clear();
		print("Вот меню:");
		create_menu();
	}
}

