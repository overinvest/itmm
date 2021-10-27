#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include "main_functions.h"

void Algoritm1() {

	int N;
	int sum;
	int i;
	int* a;

	print("Введите кол-во чисел");
	scanf_s("%d", &N);
	a = (int*)calloc(N, sizeof(int));
	print("Введите числа: ");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}
	sum = summing(a, N);
	print("Сумма чисел равна %d", sum);
}

void Algoritm2() {

	int* a;
	int n;
	int min, l;

	print("Введите кол-во чисел");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	print("Введите список");

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	min = a[0];
	l = 0;

	min_number(a, n, &min, &l);

	print("Минимальное число: %d Его индекс %d", min, l);
}

void Algoritm3() {

	int N;
	char tmp[255];
	char** Names;
	char** NewNames;
	char param[2];

	print("Введите количество элементов");
	scanf("%d", &N);

	Names = (char**)calloc(N, sizeof(char*));

	print("Введите элементы");
	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp) + 2;
		Names[i] = (char*)calloc(len, sizeof(char));
		strcpy(Names[i], tmp);
	}

	print("Введите букву");

	scanf("%s", &param);

	int k = otbor_elem(Names, N, param[0], &NewNames);

	print("Новый список:");

	for (int i = 0; i < k; i++) {
		print("[%d] = %s", i, NewNames[i]);
	}
}

void Algoritm6()
{
	char tmp[255];
	char** name;
	char** list;
	int N;

	print("Введите количество элементов");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));

	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy(name, N, &list);

	print("Список без повторений");
	for (int i = 0; i < k; i++) {
		print("[%d] = %s", i, list[i]);
	}
}

void Algoritm7()
{
	char tmp[255];
	char** name;
	char** list;
	int* Rate;
	int N;

	print("Введите количество элементов");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	Rate = (int*)calloc(N, sizeof(int));

	print("Введите элементы");
	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_rate(name, N, &list, &Rate);

	print("Список без повторений и подсчет рейтинга");
	for (int i = 0; i < k; i++) {
		print("[%d] = %s Его рейтинг %d", i, list[i], Rate[i]);
	}
}

void Algoritm8()
{
	char tmp[255];
	char** name;
	char** list;
	int* Sum;
	int* CH;
	int N;

	print("Введите количество элементов");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	CH = (int*)calloc(N, sizeof(int));
	Sum = (int*)calloc(N, sizeof(int));

	print("Введите название элемента и его характеристику");
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &tmp, &CH[i]);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

	print("Список без повторений и подсчет рейтинга");
	for (int i = 0; i < k; i++) {
		print("[%d] = %s\t Характеристика %d", i, list[i], Sum[i]);
	}
}



