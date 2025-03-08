#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "struct.h"
unsigned long long calred(RGB **pixeli,int size, int x, int y) {
    int i = 0, j = 0;
    unsigned long long red = 0;
    for (i = x; i < x + size; i++){
        for (j = y ; j < y + size; j++) {
            red = red + pixeli[i][j].red;
        }
    }
        red = red / (size * size);
        red = floor(red);
        return red;
}
unsigned long long calgreen(RGB **pixeli,int size, int x, int y) {
    int i = 0, j = 0;
    unsigned long long green = 0;
    for (i = x; i < x + size; i++){
        for (j = y ; j < y + size; j++) {
            green = green + pixeli[i][j].green;
        }
    }
        green = green / (size * size);
        green = floor(green);
        return green;
}
unsigned long long calblue(RGB **pixeli,int size, int x, int y) {
    int i = 0, j = 0;
    unsigned long long blue = 0;
    for (i = x; i < x + size; i++) {
        for (j = y ; j < y + size; j++) {
            blue = blue + pixeli[i][j].blue;
        }
    }
        blue = blue / (size * size);
        blue = floor(blue);
        return blue;
}
unsigned long long divizare(RGB **pixeli,int size, int x, int y) {
    unsigned long long red = 0, blue = 0, green = 0, mean = 0, sum = 0;;
    int i = 0, j = 0;
    red = calred(pixeli, size, x, y);
    blue = calblue(pixeli, size, x, y);
    green = calgreen(pixeli, size, x, y);
    for (i = x; i < x + size; i++)
        for (j = y; j < y + size; j++) {
            sum = sum + ((red - pixeli[i][j].red) * (red - pixeli[i][j].red) + (blue - pixeli[i][j].blue)  * (blue - pixeli[i][j].blue) + (green - pixeli[i][j].green) * (green - pixeli[i][j].green));
        }
    mean = sum / (3 * size * size);
    mean = floor (mean);
    return mean;
}
Arbore insert_nod(RGB **pixeli, int x, int y, int size, int prag) {
    Arbore nod = (Arbore) malloc(sizeof(Nod));
    if (nod == NULL)
        return NULL;
    if (divizare(pixeli, size, x, y) <= prag) {
        nod->size = size;
        nod->tip = 1;
        nod->red = (unsigned char)calred(pixeli, size, x, y);
        nod->green = (unsigned char)calgreen(pixeli, size, x, y);
        nod->blue = (unsigned char)calblue(pixeli, size, x, y);
        nod->unu = NULL;
        nod->doi = NULL;
        nod->trei = NULL;
        nod->patru = NULL;
        return nod;
    } else {
        nod->red = (unsigned char)calred(pixeli, size, x, y);
        nod->green = (unsigned char)calgreen(pixeli, size, x, y);
        nod->blue = (unsigned char)calblue(pixeli, size, x, y);
        nod->tip = 0;
        nod->size = 0;
        nod->unu = insert_nod(pixeli, x, y, size / 2, prag);
        nod->doi = insert_nod(pixeli, x, y + size / 2, size / 2, prag);
        nod->trei = insert_nod(pixeli, x + size / 2, y, size/2, prag);
        nod->patru = insert_nod(pixeli, x + size / 2, y + size / 2, size/2, prag);
        return nod;
    }
}
int numarare(Arbore arbore) {
int nr_frunze = 0;
if (arbore == NULL)
    return 0;
if (arbore->unu == NULL && arbore->doi == NULL && arbore->trei == NULL && arbore->patru == NULL)
    return 1;
nr_frunze = nr_frunze +numarare(arbore->unu) + numarare(arbore->doi) + numarare(arbore->trei) + numarare(arbore->patru);
return nr_frunze;
}
int zona_maxima(Arbore arbore) {
    int num = arbore->size, num1 , num2, num3, num4;
if (arbore->unu == NULL && arbore->doi == NULL && arbore->trei == NULL && arbore->patru == NULL)
    return num;
num1 = zona_maxima(arbore->unu);
num2 = zona_maxima(arbore->doi);
num3 = zona_maxima(arbore->trei);
num4 = zona_maxima(arbore->patru);
if (num1 < num2)
    num1 = num2;
if (num3 < num4)
    num3 = num4;
if (num1 < num3)
    num1 = num3;
if (num < num1)
    num = num1;
return num;
}
int nivel(Arbore nod) {
if (nod == NULL)
    return 0 ;
int inaltime_unu = nivel(nod->unu), inaltime_doi = nivel(nod->doi), inaltime_trei = nivel(nod->trei), inaltime_patru= nivel(nod->patru);
if (inaltime_unu < inaltime_doi)
    inaltime_unu = inaltime_doi;
if (inaltime_trei < inaltime_patru)
    inaltime_trei = inaltime_patru;
if (inaltime_unu < inaltime_trei)
    inaltime_unu = inaltime_trei;
return inaltime_unu + 1;
}
/*void parcurgere(Arbore nod, int nivel) {

}*/