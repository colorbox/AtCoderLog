s = gets.strip

terms = s.split('+')

zero_count = terms.select {|line| eval(line).zero? }.count

p terms.count - zero_count
