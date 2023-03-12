package Revision;

public class Loude implements Compa{
    private int elemento1;
   
    private int elemento2;


    public Loude() {
        this.elemento1 = elemento1;
        this.elemento2 = elemento2;
    }

    public void  SetElemento1(int elemento1){
        this.elemento1 = elemento1;
    
    }
    public void setElemto2(int elemento2){
        this.elemento2 = elemento2;
    }
    public int getElemento(){
        return elemento1;

    }
    public int getElemto2(){
        return elemento2;
    }

public void Conjunto(int a, int b) {

}   
public int soma(){
    int soma = elemento1 + elemento2;
    return soma;
}

public String getElementos(){

        return "<"+this.elemento1+this.elemento2+">";
}
@Override
public boolean maior(Compa obj) {
    Loude  C =(Loude ) obj;
    if(C.elemento1 > this.elemento1 && C.elemento2 > this.elemento2){
        return true;
    }
    else{
        return false;
    } 
}

@Override
public boolean menor(Compa obj) {
    Loude C = (Loude) obj;
    if
        (C.elemento1 < this.elemento1 && C.elemento1 <this.elemento1){
    }
    else{
        return false;
    } 
    
}

@Override
public boolean igual(Compa obj){
    Loude C = (Loude) obj;
    if(C.soma()==this.soma()){
        return true;
    }else{
        return false;

    }
}

}