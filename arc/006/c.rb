n = gets.strip.to_i
ww = readlines.map {|line| line.strip.to_i }

results = [ww.shift]

ww.each do|w|
  results = results.sort

  if w > results.max
    results.push(w)
    next
  end

  i = results.bsearch_index {|e| e>=w }
  results[i] = w
end

p results.length
