/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class catalan
{
	BigInteger []fact = new BigInteger[10010];
	public void build() {
		fact[0] = BigInteger.valueOf(1);
		for(int i = 1; i <= 10004; ++i) fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
	}

	public BigInteger ci(int x) {
		return fact[x * 2].divide(fact[x].multiply(fact[x + 1]));
	}

	public void solve() {
		Scanner s = new Scanner(System.in);
		while(s.hasNext()) {
			int n = s.nextInt();
			System.out.println(ci(n + 1));
		}

	}
	public static void main (String[] args) throws java.lang.Exception
	{
		catalan r = new catalan();
		r.build();
		r.solve();
	}
}
