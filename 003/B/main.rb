#! ruby
# -*- coding: utf-8 -*-
gets
puts readlines.to_a.sort_by{|s| s.reverse}
