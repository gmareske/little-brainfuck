#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEM_MAX 30000 // classic brainfuck number of memory cells

// pre-condition: buf is a null-terminated string
//   representing a brainfuck program
void bf_eval(char *buf) {
  int pos = 0; // iterating through string buffer
  // TODO: is there a better way to allocate memory?
  unsigned char tape[MEM_MAX];
  unsigned char *ptr = &tape[0]; // pointer to current mem cell
  unsigned char inc; // used for user input

  while (buf[pos] != '\0') {
    switch(buf[pos]) {
    case '+': ++*ptr; break; // increment the value in memory
    case '-': --*ptr; break; // decrement the value in memory
    case '>': ++ptr;  break; // move pointer forward
    case '<': --ptr;  break; // move pointer backward
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
}

char *read_file(char *filename) {
  FILE *f = fopen(filename, "r");
  int buf_size = 2048;
  char *buf = malloc(sizeof(char) * buf_size);
  int char_count = 0; // characters read
  int c;
  while ( (c = fgetc(f)) != EOF ) {
    buf[char_count] = c;
    char_count++;
    if (char_count >= buf_size) {
      buf_size *= 2;
      buf = realloc(buf, sizeof(char) * buf_size);
    }
  }
  buf[char_count] = '\0';
  return buf;
}

void print_help() {
  printf("Usage:\n");
  printf("lbf <filename> | lbf \"brainfuckprogram\"\n");
  printf("Where filename is a path to a file containing a brainfuck program");
}

int main(int argc, char **argv) {
  if (argc > 1) {
    if (access(argv[1], F_OK) != -1) {
      char *buf = read_file(argv[1]);
      bf_eval(buf);
      free(buf);
    } else {
      bf_eval(argv[1]);
    }

  } else {
    print_help();
  }
  return 0;
}
