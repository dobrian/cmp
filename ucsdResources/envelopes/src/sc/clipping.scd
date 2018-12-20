a = Signal.sineFill(1024, [1], [0])
a.plot
f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/atan_a=10.dat", "w")


b = {|x|
	if(x>1) {1} {
		if(x < -1) {-1} {
			(-0.5*x.pow(3)) + (1.5*x);
		}
	}
};

c = {|x, coeff = 0|
	// coeff = 1 - coeff;
	x - (coeff * x.pow(3));
};

t = {|x, alpha = 0|
	(2/pi) * (alpha*x).atan;
};

z = a.collect{|i|
	// i = i.clip(-1 * -3.dbamp, -3.dbamp);
	// i = b.(i*3.dbamp);
	// i = c.(i, 0);
	i = t.(i, 10);
	f.write(i.asString ++ "\n");
};
a.do{|i|}
z.plot
f.close

3.dbamp

1000.collect{|i| i=(i*0.001)*(2/pi); i.atan}.plot
