package Revision;

public class Date implements Compa {
    private int dia;
    private int mes;
    private int ano;
    private String getDia;
    private String getMes;

public Date(){
    this.dia = dia;
    this.mes = mes;
    this.ano = ano;
}
public void setDia(int dia){
    this.dia = dia; 
}
public  void setMes(int mes){
    this.mes = mes;
}
public void SetAno(int ano){
    this.ano -= ano;
}
public int getDia(){
    return dia;
}
public int getMes(){
    return mes;

}
public int getAno(){
    return ano;
}
public void Data(int d, int m, int a){
    
}
public String getDataFormatada(){
    System.out.println("A data é" + this.getDia()  +"/"+ this.getMes()  + "/" + this.getAno() );
    return getDataFormatada();
    
}
@Override
public boolean maior(Compa obj){
    Date dt =(Date) obj;
    if(dt.dia>this.dia && dt.mes>this.mes && dt.ano>this.ano){
        return true;
    }
    else{
        return false;
    }
     
}
@Override
 public boolean menor (Compa obj){
    Date dt = (Date) obj;
    if (dt.dia< this.dia && dt.mes<this.mes && dt.ano < this.ano){
        return true;

    }
    else {
        return false;
    }

 }

 @Override
 public boolean igual (Compa obj){
    Date dt = (Date) obj ; 
    if (dt.dia == this.dia && dt.mes == this.mes && dt.ano == ano){
        return true;
    }
    else{
        return false;
    }
 }
}