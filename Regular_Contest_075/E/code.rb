#!/usr/bin/env ruby
# coding: utf-8


class Bit # Binary Indexed Tree
  def initialize n
    @n = n
    @bit = Array.new n+1, 0
  end
  attr_reader :bit

  def sum i
    s = 0
    while i > 0
      s += @bit[i]
      i -= i & (-i)
    end
    return s
  end

  def add i, x
    i += 1
    while i <= @n
      @bit[i] += x
      i += i & (-i)
    end
  end
end

lambda {
  n,k = *readline.split(/\s+/).map(&:to_i)
  a = [0] + readlines.map{|v| v.to_i - k}

  acc = a.inject([]){|r,v| r << (v + (r.last || 0))}
  acc_sort = acc.sort
  acc_reg = acc.map{|v| acc_sort.bsearch_index{|x| x >= v}}
  # p acc
  # p acc_sort
  # p acc_reg

  bit = Bit.new n+1
  count = 0
  acc_reg.each do |i|
    count += bit.sum(i+1)
    bit.add i, 1
  end
  puts count
}.call
