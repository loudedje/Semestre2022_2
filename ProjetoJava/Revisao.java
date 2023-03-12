public class Revisao{
    
    public static void main(String[] args) {
       try{
        int [] vector = new   int [4];
        System.out.println("Antes da exeção");

        vector[2] =5;
        System.out.println("Depois da exeção");

       }catch(ArrayIndexOutOfBoundsException exception){
        System.out.println("Indice invalido");
       }
       
       System.out.println("Antes da exeção");
    }
}