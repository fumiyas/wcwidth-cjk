#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <alloca.h>
#include <locale.h>
#include <wchar.h>

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
	  "%s: ERROR: Invalid in multibyte sequence: argv=%d, index=%d, char=0x%2X\n",
	  argv[0],
	  i,
	  (int)(mb_p - argv[i]),
	  *(unsigned char *)mb_p
	);
	exit(1);
      }

      wc_width = wcwidth(wc);

      strncpy(mb_buf, mb_p, mb_consumed);
      mb_buf[mb_consumed] = '\0';

      printf("%d\t%s\n", wc_width, mb_buf);

      mb_p += mb_consumed;
      mb_len -= mb_consumed;
    }
  }
}

