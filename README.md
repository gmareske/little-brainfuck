# Little Brainfuck

A small brainfuck implementation in C.

## Specifications

TODO

### Installation

Setup is very simple since this is intended to be a fairly
small project.
Clone the repository (or download the zip):

```
git clone https://github.com/gmareske/little-brainfuck
```

then move into the code directory and build the project with

```
make
```

### Usage

Little brainfuck supports taking in a brainfuck program as a
command line argument, or the name of a file that contains a
brainfuck program.

Examples:

```
./lbf "+[>,.<]"
```

```
./lbf bf/hello.bf
```

Executes the brainfuck program in ```bf/hello.bf```.

## Authors

**[Griffin Mareske]** - (gmareske@gmail.com)

## License

All code is licensed under the MIT license (see included LICENSE)
