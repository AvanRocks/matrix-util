# Matrix Utility

A utility that reduces matrices into rref or ref. Can be used to solve systems of linear equations.

## Usage

Run the executable `mat` and type in your matrix row by row. Type `Enter` after the last row and then hit `Control + D` to end the input. By default, `mat` will output the matrix in [Reduced Row Echelon Form](https://en.wikipedia.org/wiki/Row_echelon_form). For example,

```
$ mat
2 -3 5
4 1 6
0 7 -4
```

which outputs

```
1 0 23/14
0 1 -4/7
0 0 0
```

If you want to reduce the matrix into Row Echelon Form (as opposed to _Reduced_ Row Echelon Form), pass the `-ref` option

```
$ mat -ref
2 -3 5
4 1 6
0 7 -4
```

which outputs

```
1 -3/2 5/2
0 1 -4/7
0 0 0
```

`mat` currently only supports signed integer input. You may input matrices of any dimensions.

## Building

There are two ways to build `mat`:

1. CMake (Windows, MacOS and Linux)
2. GNU Make (Linux and MacOS only)

### Build using CMake

- [`cmake`](https://cmake.org/) or `make`

Ensure you have `cmake` installed. If you don't, see the official [CMake webpage](https://cmake.org/runningcmake/) for instructions to install it. Once you have installed CMake, clone this repo and run the following commands from the repo's directory.

```
cmake -B build
cmake --build build
cmake --install build
```

Alternatively, see the [CMake documentation](https://cmake.org/runningcmake/) for instructions on how to use the CMake GUI.

### Build using GNU Make (Linux and MacOS only)

Clone this repo and run the following commands.

```
$ make
$ sudo make install
```

The `mat` executable will be installed to your `/usr/local/bin`. You may now clean the temporary files created during the build process by running this command.

```
$ make clean
```

To uninstall (when built with GNU Make),

```
$ sudo make uninstall
```
