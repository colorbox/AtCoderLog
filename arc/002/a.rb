y = gets.strip.to_i

is_leap = false

is_leap = true if (y%4).zero?
is_leap = false if (y%100).zero?
is_leap = true if (y%400).zero?

if is_leap
  puts 'YES'
else
  puts 'NO'
end
