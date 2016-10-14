## Disjoint Set

	type Dsets(n)
		.p := [n]int
		for i := range .p
			.p[i] = i
		.r := [n]int

	func (Dsets) Find(i int) int
		if .p[i] != i
			.p[i] = .Find(.p[i])
		return .p[i]

	func (Dsets) Union(i, j int)
		i = .Find(i)
		j = .Find(j)
		if .r[i] > .r[j]
			.p[j] = i
		else
			.p[i] = j

## Fenwick Tree

	type Fwtree<T>(n int)
		.v := [n]T

	func (Fwtree) Add(i int, x T)
		for ++i; i < len(v); i += i&-i
			.v[i] += x

	func (Fwtree) Sum(i int) T
		var r T
		for ++i; i < len(v); i -= i&-i
			r += .v[i]
		return r

## Segment Tree

	type Segtree<T>(a []int)
		.n := len(a)
		.v := [n*2+1]T
		for i, x := range a
			.v[i+.n] = a
		for i := .n-1; i >= 1; --i
			.v[i] = .v[i*2]+.v[i*2+1]

	func (Segtree) Sum(i, j int) T
		var r T
		for i += .n, j += .n; i < j; i /= 2, j /= 2
			if i%2 == 1
				r += v[i++]
			if j%2 == 1
				r += v[--j]
		return r

## Inverse Segment Tree

	type Segtree<T>(n)
		.n := n
		.v := [.n*2+1]T

	func (Segtree) Add(i, j int, x T)
		for i += .n, j += .n; i < j; i /= 2, j /= 2
			if i%2 == 1
				.v[i++] += x
			if j%2 == 1
				.v[--j] += x

	func (Segtree) Sum(i, j int) T
		var r T
		for i += .n; i > 0; i /= 2
			r += v[i]
		return r

## Z Algorithm

	func Zalgo(s string) []int
		z := [len(s)]int
		l := 0
		r := 0
		for i := 1; i < len(s); ++i
			if i > r
				l = r = i
				for r < len(s) && s[r-l] == s[r]
					++r
				z[i] = r-l
				--r
			else
				k = i-l
				if z[k] < r-i+1
					z[i] = z[k]
				else
					l = i
					for r < len(s) && s[r-l] == s[r]
						++r
					z[i] = r-l
					--r
		return z

## Fallback Table

	func Fbtab(s string) []int
		r := [len(s)]int
		r[0] = -1
		k := -1
		for i := 1; i < n; ++i
			..

## Longest Palindromic Substring

	func Palinsstr(s string) []int
		r := [0]int
		l := 0
		for i := range s
			if i > l && S[i-l-1] == S[i]
				l += 2
				++i
				continue
			append(r, l)
			for j := len(r)-2; j > s-l; --j
				d := j-e-1
				if r[j] == d
					l = d
					break
				append(r, min(d, r[j]))
			else
				l += 1
				i += 1
			append(r, l)
		for j := len(r)-2, e := 2*(len(r)-len(s))-3; j > e; --j
			append(r, min(i-e-1, r[i]))
		return r
