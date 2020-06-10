# configure
This is a configuration library that is intended for use in the Simpler programming language.

This is a robust command line parser that uses arbitrary length options, such as "-x" and "-xyz"
with an optional argument. The argument can be separated by a space or not. When defining switches
that have the same character(s) for the beginning, the longer switch name should be first.

Command parameters are easy to implement in a single data structure and parameters are
retrieved by name. See the bottom of configure.c for an example use. Look at the macros in the
header file for detailed use.

The definitions for a config option are

* CONFIG_NUM -- Taken to be an unsigned int, such as a count. If you want something like a float, then make it a string and convert it yourself.
* CONFIG_STR -- Any arbitrary string. If you use quotes, they will be passed to the progam as well.
* CONFIG_LIST -- A list of items separated by a ":" character. These are broken up into individual strings and passed to your program using the iterate_config function. See the example.
* CONFIG_BOOL -- This is a toggle. No parsing is done for strings like "true" or "false". It accepts 1 and 0.

Parameters for the definition of a command line parameter as in ```CONFIG_NUM("-v", "VERBOSE", "Set the verbosity from 0 to 50", 0, 0, 0)```:
* The string to look for on the command line of your program. This can be any string you want, though there is some checking for a "-" under certain circumstances. If a string not specified in the list is found and it does not start with a "-", then it is taken to be an input file. If it does start with a "-" and it does not appear in the list, then it is taken to be a mistaks and an error is published.
* The name that your program will use to look up the value of the parameter. Look at the example in main.c to see how to do this. Also refer to configure.h.
* The help string. This is displayed as a result of the built in parameter "-h".
* The "required" flag. If this is 1 and the command line does not have the parameter, then a "missing arg" error is published.
* The default value. This should be consistent with the type of argument. See the examples.
* The "once" flag. If this is set and there is more than one instance of the given parameter on the command line then an error is published.

Builtin parameters.
There are 2 built in parameters.
* "-h" -- when this parameter is specified, the use message is displayed. Note that the command line is built up before the help is displayed, so you can experement with the options.
* File list. This has no parameter. Any string that is discovered on the command line that does not start with a "-" is taken to be a file name in the file list. (if you don't want this, just comment out the line)

To build the test program:

1. create a directory called "build" (or similar)
2. CD to that directory
3. type "cmake .."
4. type "make"

There should be no operating system dependencies. The test program should work on any system
via the command line.

