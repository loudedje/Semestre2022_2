public class Material {
   private int codigo;
   private String nome;
    private int quantidade; 


 public Material(int codigo, String nome, int quantidade){
    this.codigo = codigo;
    this.nome = nome;
    this.quantidade = quantidade;


 }
 public Material (int codigo, String nome){
    this.codigo = codigo;
    this.nome = nome;
    this.quantidade = 0;
 }

void retirarMaterial(int retirar){
   if (this.quantidade>=retirar){
      this.quantidade-=retirar;
      System.out.println("uhuhuhu foi realizado com Sucesso");
   }
   else
   {
      System.out.println(" Errou !");
   }

}
void addMaterial(int ajou){
   this.quantidade+=ajou;
}
void setNome(String nome){
   this.nome=nome;   
}
 public String getNome(){
   return this.nome;
}
public void imprimir(){
   System.out.println("O codigo é "+ this.codigo + " do nome "+ this.getNome()+ "e com "+ this.quantidade );
}    
}
