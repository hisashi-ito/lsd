lsd
===

lsd is levenshtein distance ruby library using c++.  
This library use swig2.0 for compile.

#### how to use
```
require 'lsd'

l = Lsd::Lsd.new()
p l.dp("あいうえお","あいうえ") # => 1
```
