import java.util.*;
public class odd_even {
    public static void main (String args []){
        int  number;
        Scanner sc =new Scanner (System.in);
        System.out.print("Enter the number =");
        number=sc.nextInt();
        if(number %2==0){
            System.out.print("number is even");
        }
        else {
            System.out.print("number is odd");
        }
    }
}
