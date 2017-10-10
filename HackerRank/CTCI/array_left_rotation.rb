#!/bin/ruby
# https://www.hackerrank.com/challenges/ctci-array-left-rotation
n,k = gets.strip.split(' ')
n = n.to_i
k = k.to_i
a = gets.strip
a = a.split(' ').map(&:to_i)

b = a[k..-1] + a[0..k-1]
b.each do |val|
   print val
   print ' '
end
