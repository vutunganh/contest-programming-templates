// example of use of BigInteger in Java
import java.io.*;
import java.util.*;
import java.math.*;
class Main {
    public static void main (String args[]){
        int upper = 10000000;
        Boolean[] sieve = new Boolean[upper];
        sieve[0] = sieve[1] = false;
        for(int i = 2; i < upper; ++i) {
            sieve[i] = true;
        }
        ArrayList<BigInteger> primes = new ArrayList<BigInteger>();
        for(int i = 2; i < upper; ++i) {
            if(sieve[i]) {
                BigInteger prime = BigInteger.valueOf(i);
                primes.add(prime);
                BigInteger tmp = prime.multiply(BigInteger.valueOf(2));
                while(tmp.compareTo(BigInteger.valueOf(upper)) < 0) {
                    sieve[tmp.intValue()] = false;
                    tmp = tmp.add(prime);
                }
            }
        }
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(primes.get(n-1));
        }
    }
}