a, b, q = gets.strip.split.map(&:to_i)
ss = a.times.map { gets.strip.to_i }
tt = b.times.map { gets.strip.to_i }
xx = q.times.map { gets.strip.to_i }

# xの位置を二分探索で見つける
# 右、左、右左*2、左右*2の6パターンを探索
# 6パターンのうち最短を出力

INF = 10**12
xx.each do |x|
  s_right_index = ss.bsearch_index {|e| e>=x } || a
  s_left_index = s_right_index-1

  t_right_index = tt.bsearch_index{|e| e>=x } || b
  t_left_index = t_right_index-1

  r_s = (s_right_index != a) ? ss[s_right_index]-x : INF
  l_s = (s_left_index != -1) ? x-ss[s_left_index] : INF
  l_s = r_s = 0 if r_s.zero? || l_s.zero?

  r_t = (t_right_index != b) ? tt[t_right_index]-x : INF
  l_t = (t_left_index != -1) ? x-tt[t_left_index] : INF
  l_t = r_t = 0 if r_t.zero? || l_t.zero?

  r = [r_s, r_t].max
  l = [l_s, l_t].max
  rt_ls = r_t*2+l_s
  rs_lt = r_s*2+l_t
  lt_rs = l_t*2+r_s
  ls_rt = l_s*2+r_t
  #p [r, l, rt_ls, rs_lt, lt_rs, ls_rt]
  p [r, l, rt_ls, rs_lt, lt_rs, ls_rt].min
end
