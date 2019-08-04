h, w, T = gets.split.map(&:to_i)
sw = readlines.map {|line| line.strip.split('') }

start = nil
goal = nil

sw.each_with_index do |line, i|
  line.each_with_index do |num, j|
    if sw[i][j]=='S'
      start = [i,j]
      sw[i][j] = '.'
    end
    if sw[i][j]=='G'
      goal = [i, j]
      sw[i][j] = '.'
    end
    break if start && goal
  end
end

result = (1..T).bsearch{|t|
  q = [[0, start]]
  v = {}
  v[start]=1

  loop{
    c, index = q.sort!.shift
    break c if index==goal

    [[0, -1], [0, 1], [-1, 0], [1, 0]].each do|dir|
      y = index.first + dir.first
      x = index.last + dir.last

      if (0...h)===y && (0...w)===x && !v[[y, x]]
        cost = sw[y][x]=='#' ? t : 1
        q << [c+cost, [y,x]]
        v[[y, x]]=true
      end
    end
  } > T
}

p result-1
