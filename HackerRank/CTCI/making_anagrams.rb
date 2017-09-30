# https://www.hackerrank.com/challenges/ctci-making-anagrams
#!/bin/ruby

def count_letters (s)
    s_counts = Hash.new(0)
    s.each_char{ |letter|
        s_counts[letter] += 1
    }
    return s_counts
end

def find_anagram(a_counts, b_counts)
    total = 0
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    alphabet.each_char{ |letter|
        total += (a_counts[letter] - b_counts[letter]).abs
    }
    return total
end

a = gets.strip
b = gets.strip

a_counts = count_letters(a)
b_counts = count_letters(b)

puts find_anagram(a_counts, b_counts)
