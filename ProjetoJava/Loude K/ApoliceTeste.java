import java.util.Scanner;
public class ApoliceTeste {
    public static void main(String [] args){
        Apolice variable = new Apolice();
        
        Scanner Ver= new Scanner(System.in);

        System.out.println("Digite o nome_Segurado: ");
        variable.nomeSegurado = Ver.nextLine();

        System.out.println("Digite a idade: ");
    variable.idade = Ver.nextInt();

        System.out.println("Digite o valor premio: ");
        variable.valorPremio = Ver.nextFloat();

        System.out.println("Digite o nome da cidade: ");
        variable.cidade = Ver.next();
        variable.imprimir();
        variable.calcularPremioApolice();
        variable.imprimir();
        variable.oferecerDesconto(variable.cidade);
        variable.imprimir();

        System.out.println("Digite o nome_Segurado: ");
        String nomeSegurado = Ver.next();

        System.out.println("Digite a idade: ");
        int idade = Ver.nextInt();

        System.out.println("Digite o valor premio: ");
        float valorPremio = Ver.nextFloat();

        System.out.println("Digite o nome da cidade: ");
        String cidade = Ver.next();
        Apolice var1 = new Apolice(nomeSegurado, idade, valorPremio);
        var1.imprimir();
        var1.calcularPremioApolice();
        var1.imprimir();
        var1.oferecerDesconto(variable.cidade);
        var1.imprimir();
        


    }
}

    

