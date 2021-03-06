#! ruby
# -*- coding: utf-8 -*-

lambda{
	# データ読み込み
	n = gets.to_i
	start, goal = *gets.split(/ /).map{|c| c.to_f}

	ranges = Array.new(n+1) do
		l, r = *gets.split(/ /).map{|c| c.to_f}
		{ :l => l, :r => r }
	end
	# Goalの範囲はgoal地点のみとみなす
	ranges[n][:l] = ranges[n][:r] = goal

	# 左右の視野角(簡易)
	l_view_angle = -Float::MAX
	r_view_angle = Float::MAX
	# 左右障害になりうる壁のy座標
	l_wall_y = r_wall_y = 0

	dist = 0.0
	turning_y = 0
	y = 1
	while y <= n do
		rng = ranges[y]

		l_va = (rng[:l] - start) / (y - turning_y)
		if l_va >= l_view_angle
			l_view_angle = l_va
			l_wall_y = y
		end
		r_va = (rng[:r] - start) / (y - turning_y)
		if r_va <= r_view_angle
			r_view_angle = r_va
			r_wall_y = y
		end

		# 左の壁が右の壁の右方にきた
		if l_view_angle > r_view_angle
			if y == r_wall_y # 右の壁が奥=左カーブ
				x = ranges[l_wall_y][:l]
				y = l_wall_y
			else
				x = ranges[r_wall_y][:r]
				y = r_wall_y
			end
			dist += Math.hypot(x - start, y - turning_y)
			start, turning_y = x, y
			l_view_angle = -Float::MAX
			r_view_angle = Float::MAX
		end
		y += 1
	end
	dist += Math.hypot(goal - start, n - turning_y)
	puts dist
}.call
