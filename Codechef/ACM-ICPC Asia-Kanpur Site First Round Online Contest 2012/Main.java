//package lightoj;

import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

    final String filename = "in";

    public static void main(String[] args) throws java.lang.Exception {
        // new Thread(new Main()).start();
        new Thread(null, new Main(), "1", 1 << 25).start();
    }

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            //in = new BufferedReader(new FileReader(filename + ".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            for (int i = 1; ; ++i) {
                if(solve(i))
                	break;
            }
            out.flush();
        } catch (Exception e) {
            System.exit(1);
        }
    }

    public boolean solve(int kaseno) throws Exception {
		BigInteger A = new BigInteger(readword());
		BigInteger B = new BigInteger(readword());
		
		if(A.toString().equals("1") && B.toString().equals("1"))
			return true;
		
		while(!A.toString().equals("0")) {
			BigInteger n = B.add(A.subtract(new BigInteger("1"))).divide(A);
			if(n.toString().equals("0"))
				break;
			
			System.out.print(n.toString());
			System.out.print(" ");
			
			BigInteger An = A.multiply(n).subtract(B), Bn = B.multiply(n);
			A = An;
			B = Bn;
			
			//break;
		}
		
		System.out.println();
		
		return false;
    }
    public void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public int iread() throws Exception {
        return Integer.parseInt(readword());
    }

    public double dread() throws Exception {
        return Double.parseDouble(readword());
    }

    public long lread() throws Exception {
        return Long.parseLong(readword());
    }
    BufferedReader in;
    BufferedWriter out;

    public String readword() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c >= 0 && c <= ' ') {
            c = in.read();
        }
        if (c < 0) {
            return "";
        }
        while (c > ' ') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }
}

