public class exo9 {
    public static void main(String [] args){
        int vetor [] = new int [50];
       // 1 + (int) (Math.random() * 100); 
        for(int j = 0; j < 50; j++){

           vetor[j] = 1 + (int) (Math.random() * 100); 

        }

        int soma = 0, soma1 = 0, cont = 0,media2;
        for( int i = 0; i<50 ; i++){
            System.out.println(+vetor[i]);
            soma += vetor[i];
        }

        int media = soma / 50;

        for(int x = 0; x <50; x++ ){
            if (vetor[x] < media){
                soma1 += vetor[x];
                cont = cont + 1;
            }
        }
        media2 = soma1 / cont;

        
        System.out.println("media = " +media);
        System.out.println("media2 = " +media2);
        System.out.println("contador = " +cont);
    }

   
}