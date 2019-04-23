import os
import sys

filename = sys.argv[1]
if sys.argv[2] is None:
  sr = 44100.0
else:
  sr = float(sys.argv[2])

with open(filename) as data:
  lines = data.readlines()
  freq = [float(x.split(' ')[0]) for x in lines]
  amp = [float(x.split(' ')[1]) for x in lines]
  phase = [float(x.split(' ')[2]) for x in lines]

max_x_val = sr/2
neg_pi = -3.14
phase_factor = neg_pi/min(phase)
factor = neg_pi/min(amp)*(1/phase_factor) # get a factor

command = ('gnuplot -p -e  \"' +
# the domain
'set xrange [10:{}]; '.format(int(max_x_val)) +
'set logscale x; ' +
# 'set xtics add (\'(Nyquist)\' {}); '.format(int(max_x_val)) + # add a label at the Nyquist
# 'set xtics 2,10,22050; ' +
# grid
'set grid mxtics x; ' +
'set style line 1 lc rgb \'grey\' lt 1 lw 1; ' +
'set grid xtics ls 12; ' +
'set ytics 0,-6,{} nomirror; '.format(int(min(amp))) +
# range for the phase
'set y2tics (\\"0\\" 0, \\"-{{/Symbol p}}/8\\" {}, \\"-3{{/Symbol p}}/8\\" {}, \\"-{{/Symbol p}}/4\\" {}, \\"-{{/Symbol p}}/2\\" {}, \\"-5{{/Symbol p}}/8\\" {}, \\"-3{{/Symbol p}}/4\\" {}, \\"-7{{/Symbol p}}/8\\" {}, \\"-{{/Symbol p}}\\" {}) nomirror; '.format(neg_pi/8, 3*neg_pi/8, neg_pi/4, neg_pi/2, 5*neg_pi/8, 0.75*neg_pi, 7*neg_pi/8, neg_pi) +
'set y2range [{}*{}:0*{}]; '.format(min(amp), factor, factor ) +
# # labels
'set xlabel \\"Frequency (Hz)\\"; ' +
'set ylabel \\"Amplitude (dB)\\"; ' +
'set y2label \\"Phase (radians)\\"; ' +
# save it

# set size
'set size 1, 1; ' +
'set terminal qt size 1300,800 font \'Veranda,12\'; ' +
# plot it
'plot \\"{}\\" using 1:2 with lines title \\"Frequency Response\\", \\"{}\\"  using 1:(\$3*{}) with lines title \\"Phase Response\\" \"'.format(filename, filename, min(amp)/neg_pi*phase_factor)
)

os.system(command)
