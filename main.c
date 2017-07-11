#include <stdio.h>
#include <stdlib.h>

#define MEM_MAX 30000 // classic brainfuck number of memory cells
// pre-condition: buf is a null-terminated string
//   representing a brainfuck program
void bf_eval(char *buf) {
  int pos = 0;
  unsigned char *mem[MEM_MAX];
  for (int i = 0; i < MEM_MAX; i++) {
    mem[i] = 0; // initialize all memory cells to 0 to start
  }
  int mempos = 0;
  char inc; // used for user input
  /* int stack[1024]; // stack for loops, maximum of 1024 nested loops */
  /* int stackpos = 0; */
  while (buf[pos] != '\0') {

    switch(buf[pos]) {
    case '+':
      mem[mempos]++;
      break;
    case '-':
      mem[mempos]--;
      break;
    case '>':
      mempos++;
      break;
    case '<':
      mempos--;
      break;
    case '[':
      /* if (mem[mempos] == 0) { */
      /*	while (buf[pos] != ']') { */
      /*	  pos++; */
      /*	} */
      /*	stackpos--; */
      /* } else { */
      /*	stackpos++; */
      /*	stack[stackpos] = pos; */
      /* } */
      break;
    case ']':
      /* if (mem[mempos] != 0) { */
      /*	pos = stack[stackpos] - 1; */
      /*	stackpos--; */
      /* } */
      break;
    case '.':
      printf("%c", mem[mempos]);
      break;
    case ',':
      scanf(" %c", &inc);
      mem[mempos] = inc;
      break;
    default:
      printf("unknown token '%c' at position %i\n", buf[pos], pos);
    }

    pos++;
  }
}
int main(int argc, char **argv) {
  char *helloworld = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    bf_eval(helloworld);
}
