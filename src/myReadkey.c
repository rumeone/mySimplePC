#include "myReadkey.h"

int rk_readkey(enum keys* key)
{
    char buf[8] = { 0 };
    int numbers_of_read;
    if (tcgetattr(0, &stored_settings) != 0) { 
        return -1;
    }
    if (rk_mytermregime(0, 0, 1, 0, 1) != 0) { 
        return -1;
    }

    numbers_of_read = read(0, buf, 7);
    if (numbers_of_read < 0) {
        return -1;
    }
    buf[numbers_of_read] = '\0';

    if (strcmp(buf, "\E[A") == 0) {
        *key = KEY_UP;
    } else if (strcmp(buf, "\E[B") == 0) {
        *key = KEY_DOWN;
    } else if (strcmp(buf, "\E[C") == 0) {
        *key = KEY_RIGHT;
    } else if (strcmp(buf, "\E[D") == 0) {
        *key = KEY_LEFT;
    } else if (strcmp(buf, "\E[15~") == 0) {
        *key = KEY_F5;
    } else if (strcmp(buf, "\E[17~") == 0) {
        *key = KEY_F6;
    } else if (strcmp(buf, "l") == 0) {
        *key = KEY_L;
    } else if (strcmp(buf, "s") == 0) {
        *key = KEY_S;
    } else if (strcmp(buf, "r") == 0) {
        *key = KEY_R;
    } else if (strcmp(buf, "t") == 0) {
        *key = KEY_T;
    } else if (strcmp(buf, "i") == 0) {
        *key = KEY_I;
    } else if (strcmp(buf, "q") == 0) {
        *key = KEY_Q;
    } else if (strcmp(buf, "\n") == 0) {
        *key = KEY_ENTER;
    } else {
        *key = KEY_OTHER;
    }
    if (tcsetattr(0, TCSAFLUSH, &stored_settings) != 0) { 
        return -1;
    }
    return 0;
}

int rk_mytermsave() 
{

    if (tcgetattr(0, &options) != 0) {
        return -1;
    }

    return 0;
}

int rk_mytermrestore() 
{

    if (tcsetattr(0, TCSAFLUSH, &options) != 0) {
        return -1;
    }

    return 0;
}

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)
{
    rk_mytermsave();

    if (regime == 1) {
        options.c_lflag = options.c_lflag | ICANON;

    } else if (regime == 0) {

        options.c_lflag = options.c_lflag & (~ICANON);

        switch (echo) {
        case 1:
            options.c_lflag = options.c_lflag | ECHO;
            break;
        case 0:
            options.c_lflag = options.c_lflag & (~ECHO);
            break;
        default:
            return -1;
        }

        switch (sigint) {
        case 1:
            options.c_lflag = options.c_lflag | ISIG;
            break;
        case 0:
            options.c_lflag = options.c_lflag & (~ISIG);
            break;
        default:
            return -1;
        }

        options.c_cc[VMIN] = vmin;
        options.c_cc[VTIME] = vtime;

    } else {
        return -1;
    }

    rk_mytermrestore();
    return 0;
}