import java.util.Scanner;
public class exo10 {
    public static void main(String [] args){
        Scanner input = new Scanner(System.in);
        int x;
        int j;
        int matriz[][] = new int[4][4];
        for( x=0; x<4; x++){
            for( j=0; j<4; j++){
                matriz[x][j] = input.nextInt();
            }
        }

        for( x=0; x<4; x++){
            for( j=0; j<4; j++){
                System.out.print(matriz[x][j] +" ");
            }
            System.out.println(" ");
        }
        int soma = 0;
        for( x=0; x<4; x++){
            for( j=0; j<4; j++){
                if(x > j){
                    soma +=matriz[x][j];
                }
            }
        
        }
        System.out.println(" a Soma é: " +soma);

        
    }
}