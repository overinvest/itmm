#define _CRT_SECURE_NO_WARNINGS
#include "Algoritms.h"
#include "main_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
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
	char* description;
	int is_active;
	void (*callback)(char*);
} item;

typedef struct VKey {
	int prev_value;
	int value;
	int is_released_buff;
	int is_released;
	int is_held;
	int is_toggled;
	int vkey;
} VKey;

VKey create_key(int vkey) {
	VKey key;
	key.prev_value = 0;
	key.value = 0;
	key.is_released_buff = 0;
	key.is_released = 0;
	key.is_held = 0;
	key.is_toggled = 0;
	key.vkey = vkey;
	return key;
}

int update_key(VKey* key) {
	(*key).prev_value = (*key).value;
	(*key).value = GetAsyncKeyState((*key).vkey);

	(*key).is_held = (*key).value < 0 ? 1 : 0;

	if ((*key).is_released_buff == 0 && (*key).is_released == 1) {
		(*key).is_released = 0;
		(*key).is_released_buff = 0;
	}

	if ((*key).is_held == 1 && (*key).is_released_buff == 0) {
		(*key).is_released_buff = 1;
	}

	if ((*key).is_released_buff == 1 && (*key).is_released == 0 && (*key).is_held == 0) {
		(*key).is_released = 1;
		(*key).is_released_buff = 0;
	}

	(*key).is_toggled = GetKeyState((*key).vkey) & 1;
}

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
	system("cls"); // ������� �����
}

void create_item(const char* const name, const char* const description, int* idx, item** items, void(*callback)(void) ) {
	int len_name = strlen(name) + 2;
	int len_description = strlen(description) + 2;
	item new_item;
	new_item.name = (char*)calloc(len_name, sizeof(char));
	new_item.description = (char*)calloc(len_description, sizeof(char));
	new_item.id = (*idx);
	strcpy(new_item.name, name);
	strcpy(new_item.description, description);
	new_item.is_active = 0;
	new_item.callback = callback;
	(*items)[(*idx)] = new_item;
	(*idx)++;
	(*items) = (item*)realloc((*items), ((*idx) + 1) * sizeof(item));
}

void draw_menu(int start_index, item** items, int idx) {
	clear();

	print("��� ����:");
	for (int i = 0; i < idx; i++) {

		if (i == start_index) {
			SetColor(0, 15);
			printf("%s // %s", (*items)[i].name, (*items)[i].description);
			SetColor(15, 0);
			printf("\n");
		}
		else {
			printf("%s", (*items)[i].name);
			printf("\n");
		}

	}

	print("������� Esc, ���� ������ ������� ����");
}

int show_items(int* item_selected, item** items, int idx) {

	int start_index = 0;

	int exit = 0;

	VKey ARR_UP = create_key(VK_UP);
	VKey ARR_DOWN = create_key(VK_DOWN);
	VKey ARR_RIGHT = create_key(VK_RIGHT);
	VKey ESC = create_key(VK_ESCAPE);

	draw_menu(start_index, items, idx);

	do {

		if ( ARR_DOWN.is_released != 0 ) {
			start_index++;

			if (start_index > idx - 1) {
				start_index = 0;
			}

			draw_menu(start_index, items, idx);
		}

		if ( ARR_UP.is_released != 0 ) {
			start_index--;

			if (start_index < 0) {
				start_index = idx - 1;
			}

			draw_menu(start_index, items, idx);
		}

		if (ESC.is_released != 0) {
			exit = 1;
		}

		update_key(&ARR_UP);
		update_key(&ARR_DOWN);
		update_key(&ARR_RIGHT);
		update_key(&ESC);

	} while (ARR_RIGHT.is_released == 0 && exit == 0);
	
	if (exit != 1) {
		do {

			(*items)[start_index].is_active = 1;
			(*item_selected) = 1;
			clear();

		} while ((*item_selected) == 0);

		show_item(items, item_selected, start_index, idx);
	}
	else {
		clear();
	}

	return 0;
}

int show_item(item** items, int* item_selected, int res, int idx) {

	int scan_res;
	int exit_code;

	elem_callback((*items)[res].name, (*items)[res].callback);
	exit_code = 0;

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
	print("�����������: %s", name);

	callback();

	print("�������� ����������, ����� ����� ������� ESC");
	return 0;
}

void create_menu() {

	item* items;
	int idx = 0;
	items = (item*)malloc(1 * sizeof(item));

	create_item("1 ��������", "����� n-�����", &idx, &items, Algoritm1);
	create_item("2 ��������", "����� ������������ �������� ������� � ������������ ��� ����� � �������", &idx, &items, Algoritm2);
	create_item("3 ��������", "����� �������� ������� �� ��������� �������� � ������������� ������ �������", &idx, &items, Algoritm3);
	create_item("4 ��������", "�������� �����", &idx, &items, Algoritm4);
	create_item("5 ��������", "�������� �����", &idx, &items, Algoritm5);
	create_item("6 ��������", "������ ��� ����������", &idx, &items, Algoritm6);
	create_item("7 ��������", "������ ��� ���������� + �������", &idx, &items, Algoritm7);
	create_item("8 ��������", "������ ��� ���������� + ��������������", &idx, &items, Algoritm8);
	create_item("9 ��������", "��������� ������ �� �����", &idx, &items, Algoritm9);
	create_item("10 ��������", "��������� ������ �� ����� � �������������", &idx, &items, Algoritm10);

	int item_selected = 0;

	int res = show_items(&item_selected, &items, idx);

}

void start() {

	print("������! ����� ���������� � ����-������ ����");
	print("������� ������� ����? (�������� y ��� �������� ����, ��� ����� ����� ������� ����� ��������� ���������)");

	if (getch() == YES) {
		clear();
		print("��� ����:");
		create_menu();
	}
}

