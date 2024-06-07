import java.util.*;
public class sign_check {
    public static void main (String args[]){
        Scanner sc =new Scanner (System.in);
        int n;
        System.out.print("Enter the number =");
        n=sc.nextInt();
        if(n>0){
            System.out.println(n + " is a positive number ");
        }
        else if(n==0){
             System.out.println(n+" is a neutral number ");
        }
        else {
            System.out.println(n + " is a negative number ");
        }
    }
}
