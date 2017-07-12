#include <stdio.h>
#include <stdlib.h>

#define MEM_MAX 30000 // classic brainfuck number of memory cells


// pre-condition: buf is a null-terminated string
//   representing a brainfuck program
void bf_eval(char *buf) {

  int pos = 0; // iterating through string buffer
  // TODO: is there a better way to allocate memory?
  unsigned char *tape = calloc(sizeof(unsigned char) * MEM_MAX, 1); // memory all 0'd
  unsigned char *ptr = &tape[0]; // pointer to current mem cell
  unsigned char inc; // used for user input

  while (buf[pos] != '\0') {
    switch(buf[pos]) {
    case '+':
      ++*ptr;
      break;
    case '-':
      --*ptr;
      break;
    case '>':
      ++ptr;
      break;
    case '<':
      --ptr;
      break;
    case '[':
      if (!*ptr) { // value at ptr is zero
	int loop = 1;
	while(loop) {
	  ++pos;
	  if (buf[pos] == ']') {
	    --loop;
	  } else if (buf[pos] == '[') {
	    ++loop;
	  }
	}
      }
      break; // continue
    case ']':
      if (*ptr) { // value at ptr is nonzero
	int loop = 1;
	while (loop) {
	  --pos;
	  if (buf[pos] == '[') {
	    --loop;
	  } else if (buf[pos] == ']') {
	    ++loop;
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
  free(tape);
}

int main(int argc, char **argv) {
  if (argc > 1) {
    bf_eval(argv[1]);
  } else {
    /* char *helloworld = ">++++++++[-<+++++++++>]<.>[][<-]>+>-[+]++>++>+++[>[->+++<<+++>]<<]>-----.>->+++..+++.>-.<<+[>[+>+]>>]<--------------.>>.+++.------.--------.>+.>+."; */
    /* char *hw = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."; */
    /* char *hello = "[]>+>+>++>++<[>[->++++<<+++>]<<]>----.>->+.+++++++..+++.<+[][]>>.<<<+++++++++++++++.>>.+++.------.--------.>+.+>++.<<<[]"; */
    /* bf_eval(helloworld); */
    /* bf_eval(hw); */
    /* bf_eval(hello); */
  }
  return 0;
}
