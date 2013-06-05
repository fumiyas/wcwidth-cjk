#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 COMMAND [ARGUEMNT ...]" 1>&2
  exit 1
fi

LD_PRELOAD="${LD_PRELOAD:+$LD_PRELOAD:}@libdir@/wcwidth-cjk.so"
export LD_PRELOAD

exec "$@"

