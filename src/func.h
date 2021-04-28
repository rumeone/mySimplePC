#ifndef FUNC_H
#define FUNC_H

#define SIZE_ARRAY 100

#define EXIT_MEMORY -1
#define ERROR_WB_FILE -2
#define ERROR_RB_FILE -3
#define READ_ERROR -4
#define ERROR_FILE -5
#define ERROR_VALUE -6
#define ERROR_REGISTER -7
#define ERROR_COMMAND -8
#define ERROR_OPERAND -9
#define ERROR_NOT_COMMAND -10

/* Регистры флагов */

#define P 0b00000001
#define O 0b00000010
#define M 0b00000100
#define T 0b00001000
#define E 0b00010000

int array[SIZE_ARRAY];
int register_flags;
int accumulator;
int instructionCounter;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int registr, int value);
int sc_regGet(int registr, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);

#endif