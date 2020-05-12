# configure
This is a configuration library that is intended for use in the Simpler programming language.

This is a simple command line parser that uses 2 character options, such as "-x" with an optional
argument. Command parameters are easy to implement in a single data structure and parameters are
retrieved by name. See the bottom of configure.c for an example use. Look at the macros in the
header file for detailed use.

To build the test program:

1. create a directory called "build" (or similar)
2. CD to that directory
3. type "cmake .."
4. type "make"

There should be no operating system dependencies. The test program should work on any system
via the command line.

TODO:
1. Make command options any arbitrary length.
2. Scan for the "-h" paramter and do not update the default values if found.
3. Streamline the way that config parameters are accessed.
4. Add functionality to read parameters from the system environment.
    4a. Use the system $PATH to find files.
