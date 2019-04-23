#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int vulnfunc(int32_t intInput, char * strInput) {
   if (2 * intInput + 1 == 31337)
      if (strcmp(strInput, "Bad!") == 0)
         assert(0);
   return 0;
}

int main(int argc, char* argv[]) {
  char buf[9];
  int fd = open(argv[1], O_RDONLY);
  read(fd, buf, sizeof(buf) -1);
  buf[8] = 0;
  vulnfunc(*((int32_t*) &buf[0]), &buf[4]);
  return 0;
}

