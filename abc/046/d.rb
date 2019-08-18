s=gets.strip.split('')

goo, par = s.partition {|e| e=='g' }

if s.count.odd?
  goo.shift
end

max_count = (goo.length + par.length)/2

p max_count - par.length
