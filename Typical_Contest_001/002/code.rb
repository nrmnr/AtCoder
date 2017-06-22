#!/usr/bin/env ruby
# coding: utf-8
require "set"

def comb a, b
end

def root x
  
end

def judge a, b
  return root(a) == root(b)
end

lambda {
  n, q = *readline.split(/\s+/).map(&:to_i)
  $tree = Array.new(n)
  q.times {
    p, a, b = *readline.split(/\s+/).map(&:to_i)
    if p == 0
      comb a, b
    elsif p == 1
      puts (judge a, b)? :Yes : :No
    end
  }
}.call

