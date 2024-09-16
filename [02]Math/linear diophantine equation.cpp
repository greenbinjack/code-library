using PLL = pair <LL,LL>;
tuple <LL,LL,LL> EGCD(LL a, LL b){
    if(b == 0) return {1, 0, a};
    else{
        auto [x,y,g] = EGCD(b, a%b);
        return {y, x - a/b*y,g};
    }
}
tuple <bool, LL, LL, LL> get_solution(LL a, LL b, LL c) {
	auto [x, y, g] = EGCD(abs(a), abs(b));
	x *= (a < 0) ? -c / g : c / g;
	y *= (b < 0) ? -c / g : c / g;
	return {c % g == 0, x, y, g} ;
}
PLL shift_solution(LL a, LL b, LL x, LL y, LL shift) {
	return {x + shift * b, y - shift * a};
}