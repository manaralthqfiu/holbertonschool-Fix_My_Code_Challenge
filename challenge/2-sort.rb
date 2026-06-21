result = []
ARGV.each do |arg|
    next if arg !~ /^-?[0-9]+$/

    i_arg = arg.to_i

    is_inserted = false
    i = 0
    l = result.size

    while !is_inserted && i < l do
        if result[i] < i_arg
            i += 1
        else
            result.insert(i, i_arg)
            is_inserted = true
            break
        end
    end

    result << i_arg if !is_inserted
end

puts result
