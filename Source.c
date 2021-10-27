#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "main_functions.h"
#include "menu_handler.h"

void main()
{	

	char choise[100];

	localize();

	print("Привет! Добро пожаловать в бета-версию меню");
	print("Желаете открыть меню? (Напишите y для открытия меню, или просто Enter чтобы закрыть программу)");
	char* res = fgets(choise, 100, stdin);

	if (tolower(res[0]) == 'y') {
		clear();
		print("Вот меню:");
		create_menu();
	}
	
}
