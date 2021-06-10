# Matrix Utility

A utility that reduces matrices into rref or ref. Can be used to solve systems of linear equations.

For example, entering this matrix

```
2 -3 5
4 1 6
0 7 -4
```

outputs the following (in Reduced Row Echelon Form)

```
1 0 23/14
0 1 -4/7
0 0 0
```

For Row Echelon Form, this matrix

```
2 -3 5
4 1 6
0 7 -4
```

becomes

```
1 -3/2 5/2
0 1 -4/7
0 0 0
```

## Installation

### Windows

Pre-built Windows binaries can be obtained from the Releases section. Simply download and unzip the folder of the latest release.

Alternatively, build from source yourself. See [Building](#Building).

### Linux

Linux users will have to build from source. see [Building](#Building) below.

## Usage

### Windows

Click on `rref.bat` if you want to reduce the matrix to Reduced Row Echelon Form and click on `ref.bat` if you want to reduce it to Row Echelon Form.

Enter your matrix row by row. Hit `Enter` twice to end the input. The reduced matrix will be outputed.

### Linux

Run `mat` and type in your matrix row by row. Press `Enter` twice (or hit Control+D) to end the input. By default, `mat` will output the matrix in [Reduced Row Echelon Form](https://en.wikipedia.org/wiki/Row_echelon_form). If you want to reduce the matrix into Row Echelon Form instead, pass the `-ref` option.

## Limitations

`mat` currently only supports signed integer input, although output is displayed as signed fractions.

You may input matrices of any dimensions.

## Building

There are two ways to build `mat`:

1. CMake (Windows, MacOS and Linux)
2. GNU Make (Linux and MacOS only)

### Build using CMake

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

The `mat` executable will be installed to your `/usr/local/bin`. You may now clean the temporary files created during the build process by running

```
$ make clean
```

To uninstall (when built with GNU Make),

```
$ sudo make uninstall
```
