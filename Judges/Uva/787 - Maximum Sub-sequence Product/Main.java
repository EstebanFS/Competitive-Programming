
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Esteban
 */
public class Main {
    public static void main(String[] args){
        int number;
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            ArrayList<Integer> product = new ArrayList<Integer>();
            while(in.hasNext() && ((number = in.nextInt())!= -999999))product.add(number);
            BigInteger result = BigInteger.valueOf(product.get(0));
            for(int i=0; i<product.size(); i++){
                BigInteger aux = BigInteger.valueOf(product.get(i));
                result = aux.max(result);
                for(int j=i+1; j<product.size(); j++){
                    aux = aux.multiply(BigInteger.valueOf(product.get(j)));
                    result = aux.max(result);
                }
            }
            System.out.println(result);
        }
    }
    
}
