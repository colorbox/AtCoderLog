sx, sy, tx, ty = gets.strip.split.map(&:to_i)

y_diff = ty-sy
x_diff = tx-sx

upper = 'U'*y_diff + 'R'*x_diff
downer = 'D'*y_diff + 'L'*x_diff

first = upper
second = downer
third = 'LU' + upper + 'RD'
forth = 'RD' + downer + 'LU'

result = first + second + third + forth

puts result

