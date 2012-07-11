#! ruby
# -*- coding: utf-8 -*-

BoardSize = 8

# 盤面表示
def view board
	board.map{|row| row.map{|c| c ? 'Q':'.'}.join}.join("\n")
end

# クイーンが置けるか調査
def enable? board, x, y
	dirc = [[0,1], [0,-1], [1,0], [-1,0], [1,1], [1,-1], [-1,1], [-1,-1]]
	dirc.each do |dx, dy|
		return false unless enable_direction? board, x, y, dx, dy
	end
	return true
end

def enable_direction? board, x, y, dx, dy
	rng = (0...BoardSize)
	x += dx
	y += dy
	while rng.include? x and rng.include? y
		return false if board[y][x]
		x += dx
		y += dy
	end
	return true
end

# 妥当性判定
def is_valid? board
	board.each_with_index do |row, y|
		row.each_with_index do |cell, x|
			next unless cell
			return false if ! enable? board, x, y
		end
	end
	return true
end

# boardを読み込み
def create_board
	board = Array.new(BoardSize)
	y = 0
	while line = gets
		board[y] = line.split(//)[0...8].map{|c| c=='Q' ? true:false}
		y+=1
	end
	board
end

# パズルを解く
def resolve board, y
	return true if y == BoardSize
	if board[y].any?{|c| c}
		return resolve board, y+1
	else
		BoardSize.times do |x|
			if enable? board, x, y
				board[y][x] = true
				return true if resolve board, y+1
				board[y][x] = false
			end
		end
		return false
	end
end

lambda {
	board = create_board
	if is_valid? board and resolve board, 0
		puts view board
	else
		puts 'No Answer'
	end
}.call
