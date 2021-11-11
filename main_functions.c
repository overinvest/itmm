#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


void localize() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

int print(const char* const _Format, ...) {
	int _ = printf(_Format);
	printf("\n");
	return _;
}

// 1 Алгоритм
int summing(int* a, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
// 2 Алгоритм
void min_number(int* a, int n, int* min, int* l) {
	(*min) = a[0];
	(*l) = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < (*min)) {
			(*min) = a[i];
			(*l) = i;
		}
	}
}
// 3 Алгоритм
int otbor_elem(char** a, int n, char param, char*** best) {
	(*best) = (char**)calloc(n, sizeof(char*));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == param) {
			int len = strlen(a[i]) + 2;
			(*best)[k] = (char*)calloc(len, sizeof(char));
			strcpy((*best)[k], a[i]);
			k++;
		}
	}
	return k;
}
// 4 Алгоритм
int linear_search(char** dst, char* source, int size) {
	int index = -1;
	int i = 0;

	while (index == -1 && i < size) {

		if (strcmp(dst[i], source) == 0) {
			index = i;
		}

		i++;
	}

	return index;
}
// 5 Алгоритм
int binary_search(char** dst, char* source, int size) {
	int start = 0;
	int finish = size - 1;
	int index = -1;
	int i = 0;

	while (start <= finish)
	{
		int middle = (start + finish) / 2;

		int str_cmp_data = strcmp(source, dst[middle]);

		if (str_cmp_data == 0) {
			index = middle;
			break;
		}
		if (str_cmp_data < 0)
			finish = middle - 1;
		else
			start = middle + 1;
	}

	return index;
}
// 6 Алгоритм
int spisok_bez_povtoreniy(char** name, int n, char*** list) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			k++;
		}
	}
	return k;
}
// 7 Алгоритм
int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*rate)[k] = 1;
			k++;
		}
		else {
			(*rate)[l] += 1;
		}
	}
	return k;
}
// 8 Алгоритм
int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*sum)[k] = ch[i];
			k++;
		}
		else {
			(*sum)[l] += ch[i];
		}
	}
	return k;
}
// 9 Алгоритм
int string_split(char* str, char* razd, char*** res) {

	strcat(str, " ");
	int k = 0;
	while (strlen(str) > 0) {
		int l = strcspn(str, razd);
		if (l > 0) {
			(*res)[k] = (char*)calloc(l + 2, sizeof(char));
			strncpy((*res)[k], str, l);
			k++;
		}
		int len = strlen(str);
		for (int i = 0; i < len - l + 1; i++) {
			str[i] = str[l + i + 1];
		}
	}
	return k;
}
// 10 Алгоритм
int string_split_smart(char* str, char* razd, char*** res) {
	char* tmp;
	int len = strlen(str);

	str[len - 1] = ' ';
	str[len] = '\0';

	tmp = (char*)calloc(len + 2, sizeof(char));

	int k = 0;

	strcpy(tmp, "");

	for (int i = 0; i < len; i++) {
		char symb[2] = { str[i], '\0' };
		int l = strcspn(symb, razd);

		if (l > 0) {
			strcat(tmp, symb);
		}
		else {
			if (symb[0] == ' ')
			{
				int tmp_len = strlen(tmp);
				if (tmp_len != 0)
				{
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
			}
			else {
				int tmp_len = strlen(tmp);
				if (tmp_len != 0) {
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
				(*res)[k] = (char*)calloc(2, sizeof(char));
				strcpy((*res)[k], symb);
				k++;
			}
		}
	}
	return k;
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}