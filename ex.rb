#! /usr/local/bin/ruby
$:.unshift File.join(File.dirname(__FILE__), ".")
require 'lsd'

l = Lsd::Lsd.new()
p l.dp("あいうえお","あいうえ")
