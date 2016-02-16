
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class glasses{

    public static void main(String[] args) {
        int number;
        BigInteger[] sequence = new BigInteger[1005];
        sequence[0] = BigInteger.ONE;
        sequence[1] = new BigInteger("2");
        for(int i=2;i<1001;i++)sequence[i]= sequence[i-1].add(sequence[i-2]);
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            number = in.nextInt();
            System.out.println(sequence[number]);
        }
    }
}
