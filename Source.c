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

	print("������! ����� ���������� � ����-������ ����");
	print("������� ������� ����? (�������� y ��� �������� ����, ��� ������ Enter ����� ������� ���������)");
	char* res = fgets(choise, 100, stdin);

	if (tolower(res[0]) == 'y') {
		clear();
		print("��� ����:");
		create_menu();
	}
	
}
