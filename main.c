#include <stdio.h>
#include <stdlib.h>

#define MEM_MAX 30000 // classic brainfuck number of memory cells

typedef struct bfnode {
  int val;
  struct bfnode *next;
} bfnode_t;
typedef struct bfstack {
  bfnode_t *first;
} bfstack_t;

bfnode_t *make_node(int val) {
  bfnode_t *n = malloc(sizeof(bfnode_t));
  n->val = val;
  n->next = NULL;
  return n;
}
void free_node(bfnode_t *n) {
  free(n);
  return;
}
bfstack_t *make_stack() {
  bfstack_t *st = malloc(sizeof(bfstack_t));
  st->first = NULL;
  return st;
}
void free_stack(bfstack_t *st) {
  if (!st->first) { free(st); return;}
  bfnode_t *cur = st->first;
  while (cur !=NULL) {
    bfnode_t *temp = cur->next;
    free(cur);
    cur = temp;
  }
  free(st);
  return;
}

void push_stack(bfstack_t *st, int val) {
  bfnode_t *n = make_node(val);
  n->next = st->first;
  st->first = n;
}
int pop_stack(bfstack_t *st) {
  bfnode_t *n  = st->first;
  int ret = n->val;
  st->first = n->next;
  free_node(n);
  return ret;
}
void print_stack(bfstack_t *st) {
  bfnode_t *cur = st->first;
  while (cur != NULL ) {
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}

// pre-condition: buf is a null-terminated string
//   representing a brainfuck program
void bf_eval(char *buf) {
  int pos = 0; // iterating through string buffer
  unsigned char mem[MEM_MAX] = {0}; // memory
  unsigned char *ptr = mem; // pointer to current mem cell
  unsigned char inc; // used for user input

  int loop; // used for nested loops
  unsigned char c; // current character, used for looping backwards
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
      break; // continue
    case ']':
      if (*ptr) { // value at ptr is nonzero
	loop = 1;
	while (loop) {
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
      printf("unknown token '%c' at position %i\n", *ptr, pos);
    }
    pos++;
  }
}

int main(int argc, char **argv) {
  if (argc > 1) {
    bf_eval(argv[1]);
  } else {
    char *helloworld = ">++++++++[-<+++++++++>]<.>[][<-]>+>-[+]++>++>+++[>[->+++<<+++>]<<]>-----.>->+++..+++.>-.<<+[>[+>+]>>]<--------------.>>.+++.------.--------.>+.>+.";
    bf_eval(helloworld);
  }
  return 0;
}
