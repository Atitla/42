tui enable
set follow-fork-mode child
b main
run "infile" "grep n" "grep a" "outfile"
