#!/bin/ruby
# https://www.hackerrank.com/challenges/ctci-ransom-note

def ransom_note
  m,n = gets.strip.split(' ')
  m = m.to_i
  n = n.to_i
  magazine = gets.strip
  magazine = magazine.split(' ').sort
  ransom = gets.strip
  ransom = ransom.split(' ').sort
  ransom.each do |word|
    word_index = magazine.index(word)
    if word_index
      magazine.delete_at(word_index)
    else
      print "No"
      return
    end
  end
  print "Yes"
end

ransom_note
