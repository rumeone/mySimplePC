#include "myReadkey.h"

int rk_readkey (enum keys * key) {

	char buf[8] = {0};

	if (tcgetattr(0, &stored_settings) != 0) {
		return 0;
	}

	/*if (rk_mytermregime(0, 0, 1, 0, 1) != 0) { // режимы: 1) прямой доступ, 2) считывается 1 символ, 3) символ не отображается на экране, 4) разрешена обработка клавиш прерывания
        return -1;
    }*/

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
    } else {
        *key = KEY_OTHER;
    }

    rk_mytermrestore();

    return 0;

}

int rk_mytermsave() {

if (tcgetattr(0, &stored_settings)) {
	return 1;
	}
	return -1;
}


int rk_mytermrestore() {
	if (tcsetattr(0, TCSANOW, &stored_settings)) {
		return 1;
	}

	return -1;
}

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint) {

	struct termios new_settings;
	rk_mytermsave();

	if (regime == 1) {
		new_settings.c_lflag |= ICANON;
	}
	else if (regime == 0) {
		new_settings.c_lflag &= ICANON;

		if (echo == 0) 
			new_settings.c_lflag |= ECHO;
		
		else if(echo == 1) 
			new_settings.c_lflag &= ECHO;
		

		if (sigint == 0) 
			new_settings.c_lflag |= ISIG;
		
		else if (sigint == 1) 
			new_settings.c_lflag &= ISIG;

		new_settings.c_cc[VMIN] = vmin;
		new_settings.c_cc[VTIME] = vtime; 
	}

	tcsetattr(0, TCSANOW, &new_settings);

	return 0;
}