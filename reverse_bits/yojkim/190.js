var reverseBits = function(n) {
	bin = n.toString(2);
	res = 0;
	exp = 0;
	while (bin.length != 32) {
		bin = '0' + bin;
	}
	for (let i = bin.length - 1; i >= 0; i--) {
		if (bin[i] == 1) {
			res += Math.pow(2, bin.length - 1 - exp);
		}
		exp++;
	}
	return res;
};
