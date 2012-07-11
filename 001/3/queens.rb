#! ruby
# -*- coding: utf-8 -*-

BoardSize = 8

# 盤面表示
def view board
	board.map{|row| row.map{|c| c ? 'Q':'.'}.join}.join("\n")
end

# クイーンが置けるか調査
def enable board, target_x, target_y
	BoardSize.times do |y|
	# 上,下
		return false if board[target_x][y]
		# 右上,左下
		diagonal_x = target_x + target_y - y
		return false if (0...BoardSize).include? diagonal_x and board[diagonal_x][y]
		# 左上,右下
		diagonal_x = target_x + y - target_y
		return false if (0...BoardSize).include? diagonal_x and board[diagonal_x][y]
	end
	return true
end

# 妥当性判定
def is_valid? board
	board.each_with_index do |row, y|
		row.each_with_index do |cell, x|
			next unless cell
			y.downto 0 do |ty|
				# todo
			end
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
			if enable board, x, y
				board[x][y] = true
				return true if resolve board, y+1
				board[x][y] = false
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
