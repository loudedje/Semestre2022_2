public class Movimentacao {
    public String data;
    public double valor;
    public char tipo;

    public Movimentacao(String data, double valor,char tipo){
        this.data = data;
        this.valor =valor;
        this.tipo = tipo;
    }
    public void SetData(String data){
        this.data =data;
    }
    public void setValor(double valor){
        this.valor =valor;
        }
    public void SetTipo(char tipo){
        this.tipo=tipo;
    }
    public String getData(){
        return data;
    }
    public double getValor(){
        return valor;
    }
    public char getTipo(){
        return tipo;
    }
    


}
