#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 COMMAND [ARGUEMNT ...]" 1>&2
  exit 1
fi

LD_PRELOAD="${LD_PRELOAD:+$LD_PRELOAD:}@libdir@/wcwidth-cjk.so"

if [ x"$1" = x"--sh-init" ]; then
  echo "LD_PRELOAD='$LD_PRELOAD'"
  echo "export LD_PRELOAD"
  exit 0
fi

export LD_PRELOAD

exec "$@"
exit 1

