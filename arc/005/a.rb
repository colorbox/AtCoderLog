n=gets.strip.to_i
w = gets.strip.split


takahashis = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
takahashis += takahashis.map{|w| w+'.' }

puts w.select {|word|takahashis.include?(word) }.length
