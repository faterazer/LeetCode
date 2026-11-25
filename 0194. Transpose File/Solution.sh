# Read from the file file.txt and print its transposed content to stdout.
awk '{
    for (i = 1; i <= NF; i++) {
        cols[i] = NR == 1 ? $i : cols[i] " " $i
    }
}
END {
    for (i = 1; i <= NF; i++) {
        print cols[i]
    }
}' file.txt
