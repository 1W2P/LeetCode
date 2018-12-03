var hammingWeight = function(n) {
	console.log('hello');
	bin = n.toString(2);
	res = 0;
	for (let x of bin) {
		if (x == '1') {
			res++;
		}
	}
	return res;
};

console.log(hammingWeight(128));
