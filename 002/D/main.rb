#! ruby
# -*- coding: utf-8 -*-

lambda {
	h,w = *gets.split(/ /).map{|c| c.to_i}
	lines = readlines.map{|l| l.chomp}

	lines.each do |line|
		odd = even = 0
		line.scan /(o+)(\.+)(x+)/ do |o,d,x|
			# puts o+d+x
			if d.size.odd?
				odd += 1
			else
				even += 1
			end
		end
		puts odd, even
	end
}.call
