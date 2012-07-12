#! ruby
# -*- coding: utf-8 -*-

lambda{
	# データ読み込み
	n = gets.to_i
	start, goal = *gets.split(/ /).map{|c| c.to_i}

	ranges = Array.new(n+1) do
		l, r = *gets.split(/ /).map{|c| c.to_i}
		{ :l => l, :r => r }
	end

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
		if r_view_angle < l_view_angle
			if y == r_wall_y # 右の壁が奥=左コーナー
				x = ranges[l_wall_y][:l]
				dist += Math.hypot(x - start, l_wall_y - turning_y)
				start, turning_y = x, l_wall_y
			else # 右コーナー
				x = ranges[r_wall_y][:r]
				dist += Math.hypot(x - start, r_wall_y - turning_y)
				start, turning_y = x, r_wall_y
			end
			l_view_angle = -Float::MAX
			r_view_angle = Float::MAX
			y = turning_y
		end
		y += 1
	end
	dist += Math.hypot(goal - start, n - turning_y)
	puts dist
}.call
