#!/usr/bin/env ruby
# coding: utf-8

def stack_point c, stack, x, y
  stack.push([x, y]) if c[y][x] !~ /^[#d]$/
end

def solve c, stack
  loop do
    return false if stack.empty?
    x, y = *stack.pop
    return true if c[y][x] == "g"
    c[y][x] = "d"
    stack_point c, stack, x-1, y
    stack_point c, stack, x, y-1
    stack_point c, stack, x, y+1
    stack_point c, stack, x+1, y
  end
end

def find_start c
  c.each_with_index{|row, y|
    x = row.find_index "s"
    return x, y if x
  }
  return nil, nil
end

lambda {
  h, w = *readline.split(/\s+/).map(&:to_i)
  c = readlines.map{|line|
    row = line.chomp.split(//)
    row.unshift "#"
    row.push "#"
    row
  }
  c.unshift Array.new(w+2, "#")
  c.push Array.new(w+2, "#")
  sp = find_start(c)
  raise if sp.first.nil?
  puts solve(c, [sp])? "Yes" : "No"
}.call

