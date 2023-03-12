import java.lang.String;

class Apolice {
    int numApolice;
    String nomeSegurado;
    int idade;
    float valorPremio;
  static  int ultimoNumApolice;
  String cidade;

  
 public Apolice(){
 ultimoNumApolice++;
  
  numApolice=ultimoNumApolice;
  
 }
 public Apolice(String nomeSegurado,int idade,float valorPremio){
 this();
 this.nomeSegurado=nomeSegurado;
 this.idade=idade;
 this.valorPremio=valorPremio;
 }
 public  void imprimir(){
   System.out.print("\n\nNumApolice :" +numApolice+"\n"+"Nomesegurado: "+nomeSegurado+"\n"+"Idade: " +idade+"\n"+"valorPremio: " +valorPremio+"\n\n");
 }

 public void calcularPremioApolice(){
    if(idade>=18&&idade<=25) valorPremio+=(valorPremio*20)/100;

    else if(idade>25&&idade<=36) valorPremio+=(valorPremio*15)/100; 

    else if(idade>36) valorPremio+=(valorPremio*10)/100;
  
 }
 public void oferecerDesconto(String cidade){
    if(cidade=="Florianópolis") valorPremio-=(valorPremio*5)/100;
    else if (cidade=="Chapecó") valorPremio-=(valorPremio*6)/100;
    else if (cidade=="Joaçaba")valorPremio-=(valorPremio*7)/100;
    else if(cidade=="Joinville")valorPremio-=(valorPremio*8)/100;
   }

   public void Exibe(){
      System.out.println("Ultimp_Numero: \n" +ultimoNumApolice);
  }
 }
 