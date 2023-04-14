#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <linux/input.h>
#include <fcntl.h>
using namespace std;


int main()
{
    int fd = open("/dev/input/event0", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Read input events
    struct input_event ev;
    while (1) {
        if (read(fd, &ev, sizeof(ev)) != sizeof(ev)) {
            perror("read");
            break;
        }

        if (ev.type == EV_KEY && ev.value == 1) {
            printf("Key pressed: %d\n", ev.code);
            if (ev.code == KEY_Q)
                break;
        }
    }

    // Close input device file
    close(fd);
    return 0;
}

