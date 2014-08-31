%module lsd
// STL::stringを利用しているのでstl.iを利用する
%include "stl.i"
%{
#include "Lsd.h"
%}
%include Lsd.h
