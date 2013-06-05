#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 COMMAND [ARGUEMNT ...]" 1>&2
  exit 1
fi

wcwidth_cjk_so="@libdir@/wcwidth-cjk.so"

case ":$LD_PRELOAD:" in
*":$wcwidth_cjk_so:"*)
  ;;
*)
  LD_PRELOAD="${LD_PRELOAD:+$LD_PRELOAD:}$wcwidth_cjk_so"
  ;;
esac

if [ x"$1" = x"--sh-init" ]; then
  echo "LD_PRELOAD='$LD_PRELOAD'"
  echo "export LD_PRELOAD"
  exit 0
fi

export LD_PRELOAD

exec "$@"
exit 1

