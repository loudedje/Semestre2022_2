public class Carro {
    //attributos
    String nome;
    String marca;
    int ano;
    int vel;

    //metodos
    void acelerar(int acceleração){
        vel+=acceleração;
    } 
    void freiar(int fre){
        vel-=fre;
    }
    void buzinar(){
     System.out.println("bibibi");
        
    }
    
}
