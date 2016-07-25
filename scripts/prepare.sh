#! /bin/sh

data="CFLAGS = -std=c++11 -O2\nbin_PROGRAMS = manticore\nmanticore_SOURCES = "

cd src
files=`ls *.cpp *.h`
final=$data$files

#echo $final # for debugging

echo $final > ../src/Makefile.am
