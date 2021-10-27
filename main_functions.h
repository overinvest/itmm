#pragma once

void localize();
int print(const char* const _Format, ...);
int summing(int* a, int n);
void min_number(int* a, int n, int* min, int* l);
int otbor_elem(char** a, int n, char param, char*** best);
int linear_search(char** dst, char* source, int size);
int binary_search(char** dst, char* source, int size);
int spisok_bez_povtoreniy(char** name, int n, char*** list);
int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate);
int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum);
int string_split(char* str, char* razd, char*** res);
int string_split_smart(char* str, char* razd, char*** res);