#!/usr/bin/env ruby
# coding: utf-8

def judge h, base, add, t
  nh = h.map{|lf| lf - t * base}
  add_count = 0
  nh.reject{|lf| lf <= 0}.each{|lf|
    add_count += (lf / add.to_f).ceil
  }
  return t >= add_count
end

lambda {
  n,a,b = *readline.split(/\s+/).map(&:to_i)
  a -= b
  h = readlines.map(&:to_i)
  hi = (h.max.to_f / b).ceil
  lo = 1
  while lo < hi
    t = (lo + hi) / 2
    if judge h, b, a, t
      hi = t
    else
      lo = t + 1
    end
  end
  puts lo
}.call

