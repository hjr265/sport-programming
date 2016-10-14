import java.math.BigInteger;

public class E {
	class Lcmsegtree {
		int N = 100005;
		BigInteger V[] = new BigInteger[2*N];
		
		public Lcmsegtree() {
			clear();
		}
		
		public void clear() {
			for(int i = 0; i < V.length; ++i)
				V[i] = new BigInteger("0");
		}
		
		public void set(int i, Integer v) {
			V[i+N] = new BigInteger(v.toString());
			for(i = (i+N)/2; i > 0; i /= 2)
				V[i] = V[2*i].gcd(V[2*i+1]);
		}
		
		BigInteger lcm(int i, int j) {
			BigInteger r = new BigInteger("0");
		    for(i += N, j += N; i < j; i /= 2, j /= 2) {
		        if((i&1) != 0) {
		        	r = r.multiply(V[i]).divide(r.gcd(V[i]));
		        	++i;
		        }
		        if((j&1) != 0) {
		        	--j;
		        	r = r.multiply(V[j]).divide(r.gcd(V[j]));
		        }
		    }
		    return r;
		}
	};
	
	public static void main(String[] args) {
		
	}
};
