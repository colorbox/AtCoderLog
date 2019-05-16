A, B, C, X, Y = gets.strip.split.map(&:to_i)

maximum_price =
  if X < Y
    C*2*Y
  else
    C*2*X
  end

reduced_price =
  if X < Y
    maximum_price-(C*2*(Y-X))+(B*(Y-X))
  else
    maximum_price-(C*2*(X-Y))+(A*(X-Y))
  end

result =
  if reduced_price < maximum_price
    reduced_price
  else
    maximum_price
  end

single_price = A*X+B*Y

result = single_price if single_price < result

#  puts(maximum_price)
#  puts(reduced_price)
puts(result)
