public class Conjunto implements Comparavel{
    private int elemento_1;
    private int elemento_2;

public Conjunto(int elemento_1, int elemento_2){
    this.elemento_1=elemento_1;
    this.elemento_2=elemento_2;
}
public  void setElemento_1(int elemento_1){
    this.elemento_1=elemento_1; 
}
public void setElemento_2(int elemento_2){
    this.elemento_2=elemento_2;
}
public int getElemento_1(){
    return this.elemento_1;
}
public int getElemento2(){
    return this.elemento_2;
}
public  void conjunto(int a, int b){

}
public int soma(){
    int soma = elemento_1 + elemento_2;
    return soma;
}

public String getElementos(){

        return "<"+this.elemento_1+this.elemento_2+">";
}
@Override
public boolean maior(Comparavel obj) {
    Conjunto  C =(Conjunto ) obj;
    if(C.elemento_1 > this.elemento_1 && C.elemento_2 > this.elemento_2);
    return true;
}
 

@Override
public boolean menor(Comparavel obj) {
    Conjunto C = (Conjunto) obj;
    if(C.elemento_1< this.elemento_1 && C.elemento_2 <this.elemento_2);
    return true;  
}

@Override
public boolean igual(Comparavel obj) {
    Conjunto C = (Conjunto) obj;
    if(C.soma()==this.soma()){
        return true;
    }else{
        return false;
    }
   
} 

}


