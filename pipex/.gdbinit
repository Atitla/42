tui enable
set follow-fork-mode child
b main
run "infile" "cat" "hostname" "output"
