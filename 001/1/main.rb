gets;l=gets
puts (1..4).to_a.map{|n| l.count n.to_s}.minmax.reverse.join(' ')
