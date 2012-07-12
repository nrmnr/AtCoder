#! ruby
# -*- coding: utf-8 -*-

$ranges = []

def calc_dist r_min, r_max, start, goal
	dx = goal - start
	dy = r_max - r_min

	if r_min == r_max
		return 0
	elsif r_max - r_min == 1
		return Math.hypot dx, dy
	end

	(r_min..r_max).each do |row|
		rng = $ranges[row]
		pass = start + dx * (row - r_min) / dy
		if pass < rng[:l]
			return calc_dist(r_min, row, start, rng[:l]) +
				calc_dist(row, r_max, rng[:l], goal)
		elsif pass > rng[:r]
			return calc_dist(r_min, row, start, rng[:r]) +
				calc_dist(row, r_max, rng[:r], goal)
		end
	end

	Math.hypot dx, dy
end

lambda{
	n = gets.to_i
	start, goal = *gets.split(/ /).map{|c| c.to_i}
	n += 1
	n.times do
		l, r = *gets.split(/ /).map{|c| c.to_i}
		$ranges << { :l => l, :r => r }
	end

	puts calc_dist 0, n-1, start, goal
}.call
