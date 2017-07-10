#include <stdio.h>


int main(int argc, char **argv) {
  char *buf = "++--+-+-f";
  int pos = 0;
  char mem[30000]; // classic brainfuck allocation space
  int mempos = 0;
  while (buf[pos] != '\0') {
    switch(buf[pos]) {
    case '+':
      break;
    case '-':
      break;
    case '>':
      break;
    case '<':
      break;
    case '[':
      break;
    case ']':
      break;
    case '.':
      break;
    case ',':
      break;
    default:
      printf("unknown token '%c' at position %i\n", buf[pos], pos);
    }
    pos++;
  }
}
