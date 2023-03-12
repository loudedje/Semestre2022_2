public class Data  implements Comparavel{
    private int dia;
    private  int mes;
    private int ano;

public Data(int dia,int mes, int ano){
    this.dia = dia;
    this.mes = mes;
    this.ano = ano;
    
}
 public void setDia(int dia){
    this.dia = dia;
}
 public void setMes(int mes){
    this.mes = mes;
}
public  void setAno(int ano){
    this.ano = ano;
}
public int  getDia(){
    return this.dia;
}
public int getmes(){
    return this.mes;
}
public int getAno(){
    return this.ano;
}

public  String getFormatado(){

    System.out. println("A data é " + this.getDia() + "/" + this.getmes() + "/" + this.getAno()+ "/");
    return this.getFormatado();
}
@Override
public boolean maior(Comparavel obj) {
    Data dt =(Data) obj;
    if(dt.dia>this.dia && dt.mes>this.mes && dt.ano>this.ano){
    return true;
    }
    else{
        
        return false;
    }
    
}
@Override
public boolean menor(Comparavel obj) {
    Data dt =(Data) obj;
    if(dt.dia<this.dia && dt.mes<this.mes && dt.ano<this.ano){
        return true;
    }
    else{
        return false;
    }
    
    
}
@Override
public boolean igual(Comparavel obj) {
    Data dt =(Data) obj;
    if(dt.dia==this.dia && dt.mes== this.mes && dt.ano== this.ano){
        return true;
    }
    else{
        return false;
    }
    
}

}

