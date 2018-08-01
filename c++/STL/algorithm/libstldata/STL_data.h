#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <assert.h>

#define PROCESS_CMD "ps -ef | awk '{print $2}'"
#define BUF_SIZE 256
#define PID_LIMIT 32768

int getPidLimit(void);
int getPidNumberList(int *);
int getPidList(int *);

