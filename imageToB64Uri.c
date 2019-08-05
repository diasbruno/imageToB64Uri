#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str-concat.h"
#include "file2str.h"
#include "b64.h"

typedef unsigned char buffer_t;

static inline char* encode_file(const char* filename) {
  buffer_t* content = (buffer_t*)file2str(filename);

  char* encoded = b64_encode(content, strlen((const char*)content));

  char* uri = concat("data:image/png;base64,", encoded);

  free(content);
  free(encoded);

  return uri;
}

int main(int count, char* args[]) {
  static char filename[1024] = { 0 };
  int c = 0;
  char* walk = filename;
  while ((c = getchar()) != EOF) {
	  if (c == '\n') {
	    *walk = '\0';
	    char* uri = encode_file(filename);
	  printf("File: %s\n"
		 "%s\n\n", filename, uri);
	  free(uri);
	    walk = filename;
	  } else {
	    *(walk++) = c;
	  }
  } 

  return 0;
}
