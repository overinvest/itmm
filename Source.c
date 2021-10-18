#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

void main()
{
    char tmp[255];
    char src[255];
    char** res;
    const char sep;
    int len;
    int i;
    int j;
    int prev_i;

    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введите строку:\n");
    fgets(src, 255, stdin);

    printf("Введите разделитель: ");
    fgets(sep, 1, stdin);

    printf("Вы ввели: \n%s\nДлина строки %d", src, strlen(src));
    res = str_split(src, sep);

    printf(res);
}