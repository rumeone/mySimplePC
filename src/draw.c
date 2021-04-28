#include "draw.h"

int zero[2] = {1111638588, 1010975298};
int one[2] = {404364312, 2115508248};
int two[2] = {1615096888, 2081167408};
int three[2] = {1615086648, 943998016};
int four[2] = {1145324612, 1077952636};
int five[2] = {1006896252, 1010843712};
int six[2] = {1006896248, 943998020};
int seven[2] = {1077952636, 1077952576};
int eight[2] = {943998008, 943998020};
int nine[2] = {2084848764, 2084585536};
int plus[2] = {2081427456, 4112};
int a[2] = {1145317392, 1145324668};
int b[2] = {1011106876, 1011106884};
int c[2] = {67372152, 2013529092};
int d[2] = {1145316380, 472138820};
int e[2] = {1006896252, 2080637956};
int f[2] = {1006896252, 67372036};



void init() {

    sc_memoryInit();
    sc_regInit();
    instructionCounter = 0;
    accumulator = 0;
    num_element = 0;
    sc_regSet(T,1);

}



/*void Draw()
{
    srand(time(NULL));
    mt_clrscr();
    int* rs = malloc(sizeof(int));
    int* cs = malloc(sizeof(int));

    mt_getscreensize(rs, cs);
    if (*rs < 30 || *cs < 100) {
        printf("Увеличьте размер окна терминала.\n");
        exit(-1);
    }
    int x, y;

    bc_box(5, 3, 11, 62);
    x = 5;
    y = 30;
    mt_gotoXY(x, y);
    printf(" Memory ");
        srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        x++;
        mt_gotoXY(x, 4);
        for (int j = 0; j < 10; j++) {
            int value = rand() % 65535;
            printf("+%04X ", value);
        }
    }

    bc_box(5, 66, 2, 25);
    x = 5;
    y = 75;
    mt_gotoXY(x,y - 2);
    printf("accumulator");
    x++, y++;
    mt_gotoXY(x,y);
    printf("+9999");

    bc_box(8, 66, 2, 25);
    x = x + 2;
    mt_gotoXY(x, y - 5);
    printf("instructionCounter");
    x++;
    mt_gotoXY(x, y);
    printf("+0000");

    bc_box(11, 66, 2, 25);
    x = x + 2;
    mt_gotoXY(x, y - 2);
    printf("Operation");
    x++;
    mt_gotoXY(x,y-2);
    printf("+00 : 00");

    bc_box(14, 66, 2, 25);
    x = x + 2;
    mt_gotoXY(x, y);
    printf("Flags");
    x++;
    mt_gotoXY(x,y - 2);
    printf("P O M T E");

    bc_box(17, 3, 9, 41);
    bc_printbigchar(plus, 18, 4, 7, 0);
    bc_printbigchar(nine, 18, 12, 7, 0);
    bc_printbigchar(nine, 18, 20, 7, 0);
    bc_printbigchar(nine, 18, 28, 7, 0);
    bc_printbigchar(nine, 18, 36, 7, 0);

    bc_box(17, 45, 9, 46);
    x = 17;
    y = 47;

    mt_gotoXY(x,y);
    printf("Keys:");
    y--;
    mt_gotoXY(x + 1, y);
    printf("l - load");
    mt_gotoXY(x + 2, y);
    printf("s - save");
    mt_gotoXY(x + 3, y);
    printf("r - run");
    mt_gotoXY(x + 4, y); 
    printf("t - step");
    mt_gotoXY(x + 5, y);
    printf("i - reset");
    mt_gotoXY(x + 6, y);
    printf("F5 - accumulator");
    mt_gotoXY(x + 7, y);
    printf("F6 - instructionCounter");

    mt_gotoXY(80, 0);*/
