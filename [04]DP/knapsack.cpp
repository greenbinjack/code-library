bool possible[W][N] = {false};
possible[0][0] = true;
	for (int k = 1; k <= n; k++) {
	 for (int x = 0; x <= W; x++) {
		if (x-w[k] >= 0) possible[x][k] |= possible[x-w[k]][k-1];
		possible[x][k] |= possible[x][k-1];
	}
}