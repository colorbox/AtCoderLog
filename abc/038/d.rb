# from https://atcoder.jp/contests/abc038/submissions/3776604

n = gets.strip.to_i
wh = readlines.map {|line| line.strip.split.map(&:to_i) }

#p wh
wh.sort_by! {|w, h| [w, -h] }
#p wh
#p "###"

f = wh.shift
result = [f]

wh.each do |w, h|
  index = result.bsearch_index {|cw, ch| h <= ch }

  if index.nil?
    result << [w, h]
  else
    result[index] = [w,h]
  end
end

#p result
p result.length
