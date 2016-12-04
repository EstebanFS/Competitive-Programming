/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public BigInteger squareRoot(BigInteger y) {
		BigInteger base = new BigInteger("0");
		BigInteger limit = new BigInteger("10");
		limit = limit.pow(505);
		BigInteger mid = new BigInteger("1");
		while(base.compareTo(limit) <= 0) {
			mid = (base.add(limit)).divide(new BigInteger("2"));
			BigInteger tmp = mid.multiply(mid);
			if(tmp.compareTo(y) == 0) return mid;
			if(tmp.compareTo(y) < 0) base = mid.add(new BigInteger("1"));
			else limit = mid.subtract(new BigInteger("1"));
		}
		return mid;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Main id = new Main();
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int i = 0; i < cases; ++i) {
			BigInteger y = in.nextBigInteger();
			if(i == 0) System.out.println(id.squareRoot(y));
			else System.out.println("\n" + id.squareRoot(y));
		}
	}
}
