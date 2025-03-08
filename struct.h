typedef struct Nod{
    unsigned int tip;     
    int size;      
    struct Nod *unu, *doi , *trei , *patru;
    unsigned char red, green , blue; 
}Nod, *Arbore;

typedef struct RGB{ 
    unsigned char red;
    unsigned char green; 
    unsigned char blue; 
}RGB;

unsigned long long calred(RGB **pixeli,int size, int x, int y);
unsigned long long calgreen(RGB **pixeli,int size, int x, int y);
unsigned long long calblue(RGB **pixeli,int size, int x, int y);
unsigned long long divizare(RGB **pixeli,int size, int x, int y);
Arbore insert_nod(RGB **pixeli, int x, int y, int size, int prag);
int numarare(Arbore arbore);
int zona_maxima(Arbore arbore);
int nivel(Arbore nod);
