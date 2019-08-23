n = gets.strip.to_i
s = gets.strip.split('')

four_types = ['SS', 'SW', 'WS', 'WW'].map {|line| line.split('') }

def valid_trinity(arr, saying)
  return arr[0] == arr[2] if arr[1] == 'S' && saying=='o'
  return arr[0] != arr[2] if arr[1] == 'S' && saying=='x'
  return arr[0] != arr[2] if arr[1] == 'W' && saying=='o'
  return arr[0] == arr[2] if arr[1] == 'W' && saying=='x'
end

four_types.each do |candidate|
  current = candidate.dup
  (2...n).each do |i|
    pair = current[-2..-1]

    if pair[1]=='S'
      current.push('S') if s[i-1]=='x' && pair[0]=='W'
      current.push('W') if s[i-1]=='o' && pair[0]=='W'
      current.push('W') if s[i-1]=='x' && pair[0]=='S'
      current.push('S') if s[i-1]=='o' && pair[0]=='S'
    else
      current.push('W') if s[i-1]=='x' && pair[0]=='W'
      current.push('S') if s[i-1]=='o' && pair[0]=='W'
      current.push('S') if s[i-1]=='x' && pair[0]=='S'
      current.push('W') if s[i-1]=='o' && pair[0]=='S'
    end

    break if current.length<=i
  end
  if current.length==n
    last2first1 = current[-2..-1] + [current.first]
    last1first2 = [current.last] + current[0..1]

#p [last2first1, s.first]

    if valid_trinity(last2first1, s.last) && valid_trinity(last1first2, s.first)
      puts current.join('')
      exit
    end
  end
end

p -1
