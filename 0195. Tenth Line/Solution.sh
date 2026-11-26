# Read from the file file.txt and output the tenth line to stdout.
# Solution 1
sed -n '10p;10q' file.txt

# Solution 2
awk 'NR == 10 { print; exit }' file.txt

# Solution 3
head -n 10 file.txt | tail -n +10
