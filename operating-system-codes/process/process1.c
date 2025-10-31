#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main() {
  printf("Running ps with system\n");
  system("ps -ax"); // shows the currently running processes in the system
  printf("Done.\n");
  exit(0);
}
