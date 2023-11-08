!/usr/local/bin/gnuplot -persist
# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 600, 400 
# set output 'histerror.1.png'
set border 3 front lt black linewidth 1.000 dashtype solid
set style fill   solid 1.00 border lt -1
set key fixed right top vertical Right noreverse enhanced autotitle columnhead nobox
set style histogram errorbars gap 2 lw 2title textcolor lt -1
set offsets 0, 0, 2, 0
unset parametric
set datafile separator "	"
set style data histograms
set xtics border in scale 1,0.5 nomirror norotate  autojustify
set xtics  norangelimit 
set xtics   ()
set ytics border in scale 1,0.5 nomirror norotate  autojustify
set cbtics border in scale 1,0.5 nomirror norotate  autojustify
set title "Histogram with error bars" 
set xrange [ * : * ] noreverse writeback
set x2range [ * : * ] noreverse writeback
set yrange [ 0.00000 : * ] noreverse writeback noextend
set y2range [ * : * ] noreverse writeback
set zrange [ * : * ] noreverse writeback
set cbrange [ * : * ] noreverse writeback
set rrange [ * : * ] noreverse writeback
set bmargin  5
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
NO_ANIMATION = 1
## Last datafile plotted: "world.dat"
plot 'world.dat' using 2:3 fs solid 0.5 lw 2 ti 'A',      '' using 4:5:xticlabel(1) fs solid 0.0 lw 2 ti 'B'
