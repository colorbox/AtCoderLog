a, b, q = gets.strip.split.map(&:to_i)
s = a.times.map { gets.strip.to_i }
t = b.times.map { gets.strip.to_i }
x = q.times.map { gets.strip.to_i }


rs = s.reverse
rt = t.reverse

x.each do |xx|
  right_s = s.bsearch {|e| e>=xx }
  right_s = right_s-xx if right_s

  left_s = rs.bsearch {|e| e<= xx}
  left_s = xx - left_s if left_s

  right_t = t.bsearch {|e| e>=xx }
  right_t = right_t - xx if right_t

  left_t = rt.bsearch {|e| e<=xx }
  left_t = xx - left_t if left_t

  candidates = []
  candidates.push( [right_s, right_t].max ) if right_s && right_t
  candidates.push( [left_s, left_t].max ) if left_s && left_t
  candidates.push( [left_s*2 + right_t, left_s + right_t*2].min ) if left_s && right_t
  candidates.push( [left_t *2+ right_s, left_t + right_s*2].min ) if left_t && right_s

  result = candidates.min
#p"---"
#  p [xx, left_s,right_s, left_t, right_t]
#  p candidates
  p result
end
