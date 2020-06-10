
/*
 *  Errors
 *
 *  This contains the functions that show errors and warnings that result from
 *  parsing as well as those that result from things like memory allocation
 *  issues.
 */
#include "common.h"

static struct errors
{
    int level;
    FILE* fp;
    int errors;
    int warnings;
} errors;

/*
 *  Initialize the errors and logging system.
 */
void init_errors(int level, FILE* stre)
{
    errors.level = level;
    errors.fp = stre;  // If this is NULL, then stderr will be
    // used.
    errors.errors = 0;
    errors.warnings = 0;
}

void inc_error_count(void) { errors.errors++; }

void inc_warning_count(void) { errors.warnings++; }

void set_error_level(int lev) { errors.level = lev; }

int get_error_level(void) { return errors.level; }

void set_error_stream(FILE* fp) { errors.fp = fp; }

FILE* get_error_stream(void) { return errors.fp; }

int get_num_errors(void) { return errors.errors; }

int get_num_warnings(void) { return errors.warnings; }

void error(char* str, ...)
{
    va_list args;

    fprintf(stderr, "Error: ");
    va_start(args, str);
    vfprintf(stderr, str, args);
    va_end(args);
    fprintf(stderr, "\n");
    errors.errors++;
}

void warning(char* str, ...)
{
    va_list args;

    fprintf(stderr, "Warning: ");
    va_start(args, str);
    vfprintf(stderr, str, args);
    va_end(args);
    fprintf(stderr, "\n");
    errors.warnings++;
}

void debug(int lev, char* str, ...)
{
    va_list args;
    FILE* ofp;

    if(lev <= errors.level)
    {
        if(NULL != errors.fp)
            ofp = errors.fp;
        else
            ofp = stderr;

        fprintf(ofp, "DBG: ");
        va_start(args, str);
        vfprintf(ofp, str, args);
        va_end(args);
        fprintf(ofp, "\n");
    }
}

void fatal_error(char* str, ...)
{
    va_list args;

    fprintf(stderr, "FATAL ERROR: ");
    va_start(args, str);
    vfprintf(stderr, str, args);
    va_end(args);
    fprintf(stderr, "\n");

    exit(1);
}


void debug_trace(int lev, const char *str, ...) {

    va_list args;
    FILE *ofp;

    if(lev <= errors.level) {
        if(NULL != errors.fp)
            ofp = errors.fp;
        else
            ofp = stderr;

        fprintf(ofp, "TRACE: ");
        va_start(args, str);
        vfprintf(ofp, str, args);
        va_end(args);
        fprintf(ofp, "\n");
    }
}

