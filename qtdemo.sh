#!/bin/sh


set -e

QTAPP="helloworldUI"

if [ -f /etc/profile.d/tslib.sh ]; then
        source /etc/profile.d/tslib.sh
fi

if [ -e "$TSLIB_TSDEVICE" ]; then
        if [ ! -f /etc/pointercal ]; then
                /usr/bin/ts_calibrate
        fi
        else
        if [ -e "/usr/bin/xinput_calibrator_once.sh" ]; then
                xinput_calibrator_once.sh
        fi
fi


export QT_QPA_PLATFORM=linuxfb:fb="/dev/fb0"

export QT_QPA_GENERIC_PLUGINS=tslib

export QT_QPA_FB_TSLIB=1

export TSLIB_TSDEVICE=/dev/input/touchscreen0

export TSLIB_CALIBFILE=/etc/pointercal

#export QT_QPA_FB_DISABLE_INPUT=1

#export QT_QPA_FB_HIDECURSOR=1


cd /home/root/
./helloworldUI

