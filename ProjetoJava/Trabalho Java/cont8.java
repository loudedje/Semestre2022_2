import java.util.Scanner;

public class cont8 {
    public static void main(String[] args) {
        int menor=0;
        int maior=0;
        Scanner valor = new Scanner(System.in);
        System.out.println("Enter number: ");
        int num [] = new int [10];

        for (int i = 0; i<10; i++){
            num[i] = valor.nextInt();
    
        }
        for(int j = 0; j<10; j++){
            if (num[j]> maior){
                maior = num[j];
    
            }

            menor = maior;
        for (int x =0; x<10; x++){
            if (num[x]< menor){
                menor = num[x];

            }
        }

        }
       System.out.println(" o maior valor: "  +maior);
       System.out.println(" o menor valor: "  +menor);
      } 
    }

