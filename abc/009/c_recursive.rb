n,k  =gets.strip.split.map(&:to_i)
s = gets.strip

sorted = s.split('').sort

def diff(arr1, arr2)
  duped = arr2.dup
  arr1.each do |c|
    target_index = duped.index(c)
    duped.delete_at(target_index) if target_index
  end
  duped.length
end

def solve(origin, sorted, permissible)
  p [permissible, origin.join(''), sorted.join('')]
  return [] if origin.empty?

  origin_first = origin.shift
  sorted.each do |c|
    d = 0
    d += 1 if origin_first != c

    current_sorted = sorted.dup
    current_sorted.delete_at(current_sorted.index(c))

    d += diff(origin, current_sorted)

    if d <= permissible
      permissible-=1 if c != origin_first
      return [c] + solve(origin, current_sorted, permissible)
    end
  end
  return []
end

puts solve(s.split(''), sorted, k).join('')
