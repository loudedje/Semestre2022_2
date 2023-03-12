public class Teste {
    public static void main(String[] args) {
        Conjunto C =  new Conjunto(33, 50);
        Conjunto C1 = new Conjunto(57, 90);
        
        if (C.maior(C1)){
            System.out.println(" O primeiro elemento é maior");
        }
        else{
            System.out.println("errou, você entrou o menor primeiro.");
        }
        System.out.println("*****************************************");
        if (C.menor(C1)){
            System.out.println("O primeiro elemento é menor");

        }
    
        else{
            System.out.println("errou você entrou o maior primeiro");
        }
        System.out.println("*********************************************");
        if (C.igual(C1)){
            System.out.println("Eles são iguais");
        }
        else{
            System.out.println("Eles não  são iguais");
        }
        System.out.println("*********************************************");

        Data dt1 = new Data(20, 12, 2000);
        Data dt2 = new Data(29, 07, 2019);

        if(dt1.maior(dt2)){
            System.out.println("O primeiro elemento é maior");
        }
        else{
            System.out.println("O primeiro é menor, errouuuuu ");
        }
        System.out.println("---------------------------------------------");
        if(dt1.igual(dt2)){
            System.out.println("Eles são igual ");
        }else{
            System.out.println("Eles não são iguais");
        }
        System.out.println("----------------------------------------------");
        if(dt1.menor(dt2)){
            System.out.println("O primeiro  elemento é menor");
        }
        else{
            System.out.println("Erro, o primeiro não é o menor");
        }
        System.out.println("-------------------------------------------");
        

        
    }
    
}
