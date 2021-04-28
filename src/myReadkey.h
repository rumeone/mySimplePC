#ifndef MYREADKEY_H
#define MYREADKEY_H

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

enum keys {
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_F5,
  KEY_F6,
  KEY_L,
  KEY_S,
  KEY_R,
  KEY_T,
  KEY_I,
  KEY_OTHER,
  KEY_Q,
  KEY_ENTER
};

struct termios options;
struct termios stored_settings;
enum keys key;

int rk_readkey(enum keys * key);
int rk_mytermrestore();
int rk_mytermsave();
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);


#endif