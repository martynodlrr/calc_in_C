#include "matrix.h"

struct trail trails[WIDTH];

void init_trail(struct trail *trail) {
    trail->start = -(float)(rand() % HEIGHT);
    trail->end = 0;
    trail->speed = (rand() % 5) / 10.0f + 0.2f;
}

void update() {
    for (int x = 0; x < WIDTH; x++) {
        int start = trails[x].start < 0 ? 0 : (int)trails[x].start;
        int end = trails[x].end > HEIGHT ? HEIGHT : (int)trails[x].end;

        for (int y = start; y < end; y++) {
            move(y, x);
            if (y < (int)trails[x].end - 1)
                addch(rand() % 256 | COLOR_PAIR(1));
            else
                addch(rand() % 256 | COLOR_PAIR(2));
        }

        trails[x].start += trails[x].speed;
        trails[x].end += trails[x].speed;

        if (trails[x].start >= HEIGHT)
            init_trail(&trails[x]);
    }
}

void invoke_matrix(void) {
    srand((unsigned)time(NULL));

    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);

    for (int i = 0; i < WIDTH; i++)
        init_trail(&trails[i]);

    for (;;) {
        update();
        refresh();
        napms(16);
    }

    endwin();
}
