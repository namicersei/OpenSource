#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(int *, int);
int *convertToInt(char *, int);
char *convertToChar(int *, int);
int getSize(char *);
void operation(char *);
void swap(int *, int *);
char *substring(char *, int, int);
void doStuff();

#define MAX 9999

int main() {
    doStuff();
    return 0;
}


void doStuff() {
    int size = 0;
    scanf("%d", &size);
    char str[MAX];
    for (int i = 0; i < size; i++) {
        fgets(str, MAX, stdin);
        operation(str);
    }
}

void operation(char* str) {
    int size = getSize(str);
    int div = size / 4;
    int rem = size % 4;

    int *ar = convertToInt(str, size);
    sort(ar, size);

    char *str2 = convertToChar(ar, size);

    int sum = 0;

    for (int i = 0, k = 1, start = 0; i < 4; i++, start += div) {
        if (rem == 0) {
            char *temp = substring(str2, div, start);
            int no;
            sscanf(temp, "%d", &no);
            sum += no;
        } else {
            char *temp = substring(str2, div + k, start);
            int no;
            sscanf(temp, "%d", &no);
            sum += no;
            rem--;
            start++;
        }
    }
    printf("%d\n", sum);
}

char *substring(char *ar, int size, int start) {
    char *first = (char *) malloc(((size) * sizeof(char)) + 1);
    strncpy(first, ar + start, size);
    return first;
}


void sort(int *ar, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (ar[j] < ar[j + 1])
                swap(&ar[j], &ar[j + 1]);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int *convertToInt(char *ar, int size) {
    int *ar1 = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        ar1[i] = ar[i] - '0';
    return ar1;
}

char *convertToChar(int *ar, int size) {
    char *ar1 = (char *) malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
        ar1[i] = (char) (ar[i] + '0');
    return ar1;
}

int getSize(char *ar) {
    int counter = 0;
    while (ar[counter] != '\0')
        counter++;
    return counter - 1;
}