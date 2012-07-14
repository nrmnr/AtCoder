#! ruby
# -*- coding: utf-8 -*-

lambda {
	short_cut = []
	for c1 in %w(A B X Y) do
		for c2 in %w(A B X Y) do
			short_cut << c1 + c2
		end
	end

	gets
	cmd = gets.chomp

	len = cmd.size
	for l in short_cut do
		for r in short_cut do
			break if l == r
			new_len = cmd.gsub(/#{l}/,'L').gsub(/#{r}/,'R').size
			len = new_len if new_len < len
		end
	end

	puts len
}.call
