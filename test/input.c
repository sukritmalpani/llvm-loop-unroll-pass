#include <stdio.h>

void loop() {
    for (int i = 0; i < 4; ++i) {
        printf("Hello %d\n", i);
    }
}

int main() {
    loop();
    return 0;
}
