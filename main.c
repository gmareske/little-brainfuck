#include <stdio.h>

#define MEM_MAX 30000 // classic brainfuck number of memory cells

// pre-condition: buf is a null-terminated string
//   representing a brainfuck program
void bf_eval(char *buf) {
  int pos = 0; // iterating through string buffer
  unsigned char mem[MEM_MAX] = {0}; // memory
  unsigned char *ptr = mem; // pointer to current mem cell
  unsigned char inc; // used for user input

  int loop; // used for nested loops
  int c; // current character, used for looping backwards
  while (buf[pos] != '\0') {
    switch(buf[pos]) {
    case '+':
      (*ptr)++;
      break;
    case '-':
      (*ptr)--;
      break;
    case '>':
      ptr++;
      break;
    case '<':
      ptr--;
      break;
    case '[':
      break; // continue
    case ']':
      if (*ptr) { // value at ptr is nonzero
	loop = 1;
	while (loop > 0) {
	  c = buf[--pos];
	  if (c == '[') {
	    loop--;
	  } else if (c == ']') {
	    loop++;
	  }
	}
      }
      break;
    case '.':
      printf("%c", *ptr);
      break;
    case ',':
      scanf(" %c", &inc);
      *ptr = inc;
      break;
    default:
      printf("unknown token '%c' at position %i\n", buf[pos], pos);
    }
    pos++;
  }
}
int main(int argc, char **argv) {
  if (argc > 1) {
    bf_eval(argv[1]);
  } else {
    char *helloworld = ">>>>--<-<<+[+[<+>--->->->-<<<]>]<<--.<++++++.<<-..<<.<+.>>.>>.<<<.+++.>>.>>-.<<<+.";
    bf_eval(helloworld);
  }
  return 0;
}
