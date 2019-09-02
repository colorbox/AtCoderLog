n, a, b = gets.strip.split.map(&:to_i)
v = gets.strip.split.map(&:to_i).sort.reverse

medians = v.take(a)
result_median = (medians.inject(:+)/medians.length.to_f)

@factorial_memo=[1,1]

def memo_factor(n, r)
  (@factorial_memo[n]/(@factorial_memo[r] * @factorial_memo[n-r]))
end

(2..50).each do |i|
  @factorial_memo[i] = i * @factorial_memo[i-1]
end

# 個数が可変になる要素は最後の要素のみ
# 可変個数は固定、それを全体の中から組合せで取得
kinds = medians.group_by(&:itself)
mobile_values = kinds.values.last
mobile_value = mobile_values.first
need_mobile_value_count  = mobile_values.length

all_mobile_value_count = v.count {|e| e==mobile_value }
result_count = memo_factor(all_mobile_value_count, need_mobile_value_count)

if medians.uniq.length==1
  (a+1..b).each do |c|
    result_count += memo_factor(all_mobile_value_count, c)
  end
end

p result_median
p result_count
