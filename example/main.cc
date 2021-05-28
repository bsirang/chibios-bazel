#include <ch.h>
#include <hal.h>

int main(int argc, char* argv[]) {
  halInit();
  chSysInit();

  while (true) {
    chThdSleepMilliseconds(1000);
  }

  return 0;
}
