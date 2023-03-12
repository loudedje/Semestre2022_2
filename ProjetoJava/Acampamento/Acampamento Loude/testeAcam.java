import java.util.Scanner;
import java.util.Vector;
public class testeAcam {
    public static void main(String[]args){
        
        int x = 10;
        Acampamento vetor[] = new Acampamento [x];
        Scanner ler = new Scanner(System.in);

        for(int y = 0; y < vetor.length; y++){
            System.out.println("\ndigite o nome:");
            String nome = ler.next();
            System.out.println("\ndigite a idade:");
            int idade = ler.nextInt();
            Acampamento acamp = new Acampamento(nome, idade);
            vetor[i] = acamp;
            vetor[i].definirEquipe();
        }

        for(int j = 0; j < vetor.length; j++){
           System.out.println(vetor[j].toString()) ;
        }

    }
}

