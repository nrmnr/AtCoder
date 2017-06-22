#!/usr/bin/env ruby
# coding: utf-8

lambda {
  n = readline.to_i
  s = readlines.map(&:to_i).sort
  total = s.inject(&:+)
  if total % 10 != 0
    puts total
    return
  end

  s.select!{|t| t % 10 != 0}
  if s.empty?
    puts 0
  else
    puts total - s.first
  end
}.call

