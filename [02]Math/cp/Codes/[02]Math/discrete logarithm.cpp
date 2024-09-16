// Computes x which a ^ x = b mod n.
LL d_log(LL a, LL b, LL n) {
	LL m = ceil(sqrt(n)), aj = 1;
	map<LL, LL> M;
	for (int i = 0; i < m; ++i) {
		if (!M.count(aj)) M[aj] = i;
		aj = (aj * a) % n;
	}
	LL coef = mod_pow(a, n - 2, n);
	coef = mod_pow(coef, m, n);
	// coef = a ^ (-m)
	LL gamma = b;
	for (int i = 0; i < m; ++i) {
		if (M.count(gamma)) return i * m + M[gamma];
		else gamma = (gamma * coef) % n;
	}
	return -1;
}
