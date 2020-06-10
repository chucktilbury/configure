

#include "common.h"

BEGIN_CONFIG
    CONFIG_NUM("-v", "VERBOSE", "Set the verbosity from 0 to 50", 0, 0, 0)
    CONFIG_STR("-o", "OUTFILE", "Specify the file name to output", 0, "output.bc", 1)
    CONFIG_LIST("-i", "FPATH", "Specify directories to search for imports", 0, ".:include", 0)
    CONFIG_BOOL("-D", "DFILE_ONLY", "Output the dot file only. No object output", 0, 0, 0)
    CONFIG_STR("-d", "DUMP_FILE", "Specify the file name to dump the AST into", 0, "ast_dump.dot", 1)
END_CONFIG


int main(int argc, char** argv) {

    int n = configure(argc, argv);

    printf("num_parms: %d\n", n);
    printf("prog_name: %s\n", GET_CONFIG_STR("PROG_NAME"));
    printf("VERBOSE: %d\n", GET_CONFIG_NUM("VERBOSE"));
    printf("OUTFILE: %s\n", GET_CONFIG_STR("OUTFILE"));
    printf("DUMP_FILE: %s\n", GET_CONFIG_STR("DUMP_FILE"));

    printf("\nVERBOSE: ");
    for(char* str = iterate_config("VERBOSE"); str != NULL; str = iterate_config("VERBOSE"))
        printf("%s ", str);
    printf("\n");

    printf("FPATH: ");
    for(char* str = iterate_config("FPATH"); str != NULL; str = iterate_config("FPATH"))
        printf("%s ", str);
    printf("\n");

    printf("INFILES: ");
    for(char* str = iterate_config("INFILES"); str != NULL; str = iterate_config("INFILES"))
        printf("%s ", str);
    printf("\n");

    printf("OUTFILE: ");
    for(char* str = iterate_config("OUTFILE"); str != NULL; str = iterate_config("OUTFILE"))
        printf("%s ", str);
    printf("\n");

    printf("DUMP_FILE: ");
    for(char* str = iterate_config("DUMP_FILE"); str != NULL; str = iterate_config("DUMP_FILE"))
        printf("%s ", str);
    printf("\n");

    //show_use();
    return 0;
}
