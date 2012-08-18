#! ruby
# -*- coding: utf-8 -*-

def overlap? a, b
	return true if a.include? b.begin or a.include? b.end or b.include? a.begin or b.include? a.end
	ta = nil
	if a.begin < b.begin
		ta = (a.begin+24*60..a.end+24*60)
	else
		ta = (a.begin-24*60..a.end-24*60)
	end
	return (ta.include? b.begin or ta.include? b.end or b.include? ta.begin or b.include? ta.end)
end

lambda(){
	rngs = []
	gets.to_i.times do
		ts, te = gets.chomp.split(/ /).map do |t|
			h, m = t.split(/:/).map(&:to_i)
			h * 60 + m
		end
		rngs << (ts..te-1)
	end
	rngs.sort!{|a,b| a.begin <=> b.begin}

	c = 0
	until rngs.empty?
		used = [rngs.shift]
		c += 1
		rngs.clone.each do |o|
			if used.all?{|r| !overlap?(r,o)}
				used << o
				rngs.delete_if{|e| e.equal? o}
			end
		end
	end
	puts c
}.call
