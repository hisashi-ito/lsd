#! /bin/sh
#
# Swing Build 用シェル
#
rm -rf *.so *.o *.cxx
swig -c++ -ruby lsd.i
ruby extconf.rb
make
# カーカイブ以外削除
rm -f *.o *.cxx
