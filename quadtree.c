#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "struct.h"
#include <string.h>

int main(int argc, char const *argv[]) {
    if(strcmp(argv[1], "-c1") == 0) {
        int i = 0, j = 0;
        char citire[3], space;
        //Arbore arbore = malloc(sizeof(arbore));
        unsigned int  width, height, val_max;
        // citire din fisier binar
        FILE *input; // fisierul din care citim
        FILE *output; // fisierul in care afisam
        input = fopen(argv[3], "rb");
        output = fopen(argv[4], "w");
        fscanf(input, "%s\n", citire);
        fscanf(input, "%u", &width);
        fscanf(input, "%u\n", &height);
        fscanf(input, "%u", &val_max);
        fscanf(input, "%c", &space);
        RGB **pixeli = malloc (width * sizeof(RGB*));
        for (i = 0; i < height; i++)
            pixeli[i] = malloc(height * sizeof(RGB)); 
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++) {
                fread(&pixeli[i][j].red, sizeof(unsigned char), 1 , input);
                fread(&pixeli[i][j].green, sizeof(unsigned char), 1 , input);
                fread(&pixeli[i][j].blue, sizeof(unsigned char), 1 , input);
            }
        int prag = atoi(argv[2]);
        int size =  width; // salvam dimensiunile cu care vom lucra prima data
        int x = 0 , y = 0;
        Arbore arbore = insert_nod(pixeli, x, y, size, prag);
        int t = nivel(arbore);
        fprintf(output, "%d\n", t);
        fprintf(output, "%d\n", numarare(arbore));
        fprintf(output, "%d\n", zona_maxima(arbore)); 
    } 
    if(strcmp(argv[1], "-c2") == 0) {
        int k = 0, i = 0, j = 0;
        char citire[3], space;
        //Arbore arbore = malloc(sizeof(arbore));
        unsigned int  width, height, val_max;
        // citire din fisier binar
        FILE *input; // fisierul din care citim
        FILE *output; // fisierul in care afisam
        input = fopen(argv[3], "rb");
        output = fopen(argv[4], "w");
        fscanf(input, "%s/n", &citire);
        fscanf(input, "%u/n", &width);
        fscanf(input, "%u/n", &height);
        fscanf(input, "%u/n", &val_max);
        fscanf(input, "%c", &space);
        RGB **pixeli = malloc (width * (sizeof(RGB*)));
        for (i = 0; i < height; i++)
            pixeli[i] = malloc(height * sizeof(RGB)); //buba
        for (i = 0; i < height; i++)
            for (j = 0; j < width; j++) {
                fread(&pixeli[i][j].red, sizeof(unsigned char), 1 , input);
                fread(&pixeli[i][j].green, sizeof(unsigned char), 1 , input);
                fread(&pixeli[i][j].blue, sizeof(unsigned char), 1 , input);
            }
        // functia care trebuie sa realizeze arborele
        
    }   
}
