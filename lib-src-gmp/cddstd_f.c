/* automatically generated by sed scripts from the c source named below: */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "cddtypes_f.h"

void *ddf_malloc(size_t size)
{
  void *x = malloc(size);
  if (x == 0) {
    fprintf(stderr, "ERROR: Out of Memory\n");
    exit(EXIT_FAILURE);
  }
  return x;
}
void *ddf_calloc(size_t nmemb, size_t size)
{
  void *x = calloc(nmemb, size);
  if (x == 0) {
    fprintf(stderr, "ERROR: Out of Memory\n");
    exit(EXIT_FAILURE);
  }
  return x;
}

void ddf_scanf(int n, const char *format, ...)
{
  int rc;

  va_list args;
  va_start(args, format);
  rc = vscanf(format, args);
  va_end(args);

  if (rc != n) {
    if (rc == EOF) {
      perror("scanf");
    } else {
      // rc < n, not all arguments of format could be read
      fprintf(stderr, "ERROR: Invalid input\n");
    }
    exit(EXIT_FAILURE);
  }
}

int ddf_fscanf(FILE *stream, int check, int n, const char *format, ...)
{
  int rc;

  va_list args;
  va_start(args, format);
  rc = vfscanf(stream, format, args);
  va_end(args);

  if (rc != n) {
    if (check) {
      return 1;
    } else {
      if (rc == EOF) {
        perror("scanf");
      } else {
        // rc < n, not all arguments of format could be read
        fprintf(stderr, "ERROR: Invalid input\n");
      }
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
void ddf_fgets(char *s, FILE *stream)
{
  char *ret = fgets(s, ddf_linelenmax, stream);
  if (ret == NULL) {
    fprintf(stderr, "ERROR: Failed while reading\n");
    exit(EXIT_FAILURE);
  }
}
