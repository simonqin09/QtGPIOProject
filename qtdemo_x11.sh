#!/bin/sh

set -e

cd /usr/bin/
QTAPP="helloworldUI"
QTAPPSTART="./${QTAPP} > /var/log/Xsession.log 2>&1"

case "$1" in
  start)
        echo "Starting ${QTAPP}"
        Xorg &
        export DISPLAY=:0
        eval $QTAPPSTART &
        ;;
  stop)
        echo "Stopping ${QTAPP}"
                killall $QTAPP
                killall Xorg
        ;;
  restart)
        $0 stop
        $0 start
        ;;
  *)
        echo "usage: $0 { start | stop | restart }" >&2
        exit 1
        ;;
esac

exit 0
