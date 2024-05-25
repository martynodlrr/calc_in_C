#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#define WIDTH  80
#define HEIGHT 40

#define idx(x, y) ((x)+WIDTH*(y))

struct trail {
	float start;
	float end;
	float speed;
};

extern struct trail trails[WIDTH];

void init_trail(struct trail *trail);

void update(void);

void invoke_matrix(void);

#endif


