#! /bin/sh

scripts/prepare.sh

aclocal

automake --add-missing

autoconf
