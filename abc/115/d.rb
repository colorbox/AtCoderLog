n, x = gets.strip.split.map(&:to_i)

@p_counts = [1]
@b_counts = [0]

n.times do
  @p_counts.push(@p_counts.last*2+1)
  @b_counts.push(@b_counts.last*2+2)
end
@pb_counts = @p_counts.zip(@b_counts).map {|l, r| l+r }

#p @p_counts
#p @b_counts
#p @pb_counts

def bite_count(dim, count)
  if dim.zero?
    if count <= 0
      return 0
    else
      return 1
    end
  end

  return bite_count(dim-1, count-1) if count <= 1 + @pb_counts[dim-1]
  @p_counts[dim-1] +1 + bite_count(dim-1, count-1-@pb_counts[dim-1]-1)
end

p bite_count(n, x)
