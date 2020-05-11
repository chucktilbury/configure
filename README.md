# configure
This is a configuration library that is intended for use in the Simpler programming language.

This library will include command line parsing, configuration file parsing, and configuration parameters taken from the system environment. The goal is to place all of the configuration in a single user-facing data structure that is filled in from a single function call. The configuration for the library is to be done by filling in a single data structure.

The command line processor is the top priority. It will accept input that looks like "-abc" where it is 3 switch parameters, or where it is a single parameter with an argument. 
