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

	print("������� ���-�� �����");
	scanf_s("%d", &N);
	a = (int*)calloc(N, sizeof(int));
	print("������� �����: ");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}
	sum = summing(a, N);
	print("����� ����� ����� %d", sum);
}

void Algoritm2() {

	int* a;
	int n;
	int min, l;

	print("������� ���-�� �����");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	print("������� ������");

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	min = a[0];
	l = 0;

	min_number(a, n, &min, &l);

	print("����������� �����: %d ��� ������ %d", min, l);
}

void Algoritm3() {

	int N;
	char tmp[255];
	char** Names;
	char** NewNames;
	char param[2];

	print("������� ���������� ���������");
	scanf("%d", &N);

	Names = (char**)calloc(N, sizeof(char*));

	print("������� ��������");
	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp) + 2;
		Names[i] = (char*)calloc(len, sizeof(char));
		strcpy(Names[i], tmp);
	}

	print("������� �����");

	scanf("%s", &param);

	int k = otbor_elem(Names, N, param[0], &NewNames);

	print("����� ������:");

	for (int i = 0; i < k; i++) {
		print("[%d] = %s", i, NewNames[i]);
	}
}

void Algoritm4() {

	int N, i, len;
	char** name;
	char* ctrl;
	char tmp[255];

	printf("������� ���-�� N: ");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	print("����� ������");

	for (i = 0; i < N; i++) {

		scanf("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy(name[i], tmp);
	}

	print("������� ������� �����");
	scanf("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy(ctrl, tmp);

	print("�������� ����� %d", linear_search(name, ctrl, N));
	//printf("�������� ����� %d\n", binary_search(name, ctrl, N));

}

void Algoritm5() {

	int N, i, len;
	char** name;
	char* ctrl;
	char tmp[255];

	printf("������� ���-�� N: ");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	print("����� ������");

	for (i = 0; i < N; i++) {

		scanf("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy(name[i], tmp);
	}

	print("������� ������� �����");
	scanf("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy(ctrl, tmp);

	print("�������� ����� %d", binary_search(name, ctrl, N));

}

void Algoritm6()
{
	char tmp[255];
	char** name;
	char** list;
	int N;

	print("������� ���������� ���������");
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

	print("������ ��� ����������");
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

	print("������� ���������� ���������");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	Rate = (int*)calloc(N, sizeof(int));

	print("������� ��������");
	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_rate(name, N, &list, &Rate);

	print("������ ��� ���������� � ������� ��������");
	for (int i = 0; i < k; i++) {
		print("[%d] = %s ��� ������� %d", i, list[i], Rate[i]);
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

	print("������� ���������� ���������");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	CH = (int*)calloc(N, sizeof(int));
	Sum = (int*)calloc(N, sizeof(int));

	print("������� �������� �������� � ��� ��������������");
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &tmp, &CH[i]);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

	print("������ ��� ���������� � ������� ��������");
	for (int i = 0; i < k; i++) {
		print("[%d] = %s\t �������������� %d", i, list[i], Sum[i]);
	}
}

void Algoritm9()
{
	char data[100];
	char** result;

	print("������� ������");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split(data, " ", &result);

	for (int i = 0; i < k; i++) {
		print("[%d] %s", i, result[i]);
	}

}

void Algoritm10()
{
	char data[100];
	char** result;
	char razd[] = ",/.'[]*-+? ";

	print("������� ������");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split_smart(data, razd, &result);

	for (int i = 0; i < k; i++) {
		print("[%d] %s", i, result[i]);
	}

}