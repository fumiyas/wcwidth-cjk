#if HAVE_CONFIG_H
#include "config.h"
#endif

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#endif
#include <locale.h>
#include <wchar.h>

void dump_bigendian(FILE *fp, void *p_in, int size) {
  unsigned char *p;
  int i;

  for (p = p_in, i = 0; i < size; i++) {
    fprintf(fp, " %02X", *(p + i));
  }
}

#ifndef WORDS_BIGENDIAN
void dump_littleendian(FILE *fp, void *p_in, int size) {
  unsigned char *p;
  int i;

  for (p = p_in, i = size - 1; i >= 0; i--) {
    fprintf(fp, " %02X", *(p + i));
  }
}
#endif

int main(int argc, char **argv) {
  int i;
  int mb_consumed;
  char *mb_p;
  size_t mb_len;
  char *mb_buf;
  wchar_t wc;
  int wc_width;

  if (argc < 2) {
    printf("Usage: %s STRING [...]\n", argv[0]);
    exit(1);
  }

  setlocale (LC_ALL, "");
  mbtowc(NULL, NULL, 0);
  mb_buf = alloca(MB_CUR_MAX + 1);

  for (i = 1; i < argc; i++) {
    mb_p = argv[i];
    mb_len = strlen(mb_p);
    while (mb_len > 0) {
      mb_consumed = mbtowc(&wc, mb_p, mb_len);
      if (mb_consumed == -1) {
	fprintf(stderr,
	  "%s: ERROR: Invalid multibyte sequence: argv=%d, index=%d, bytes:",
	  argv[0],
	  i,
	  (int)(mb_p - argv[i])
	);
	dump_bigendian(stderr, mb_p, mb_len);
	fputs("\n", stderr);
	exit(1);
      }

      wc_width = wcwidth(wc);

      strncpy(mb_buf, mb_p, mb_consumed);
      mb_buf[mb_consumed] = '\0';

      printf("%d", wc_width);
#ifdef WORDS_BIGENDIAN
      dump_bigendian(stdout, &wc, sizeof(wchar_t));
#else
      dump_littleendian(stdout, &wc, sizeof(wchar_t));
#endif
      printf("\t%s\n", mb_buf);

      mb_p += mb_consumed;
      mb_len -= mb_consumed;
    }
  }

  exit(0);
}

