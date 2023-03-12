import java.util.ArrayList;

public abstract class Conta{
    
     protected  int numero;
     protected  double saldo =0;
     protected String nome;
    Cliente cliente;
    ArrayList<Movimentacao>movimentacoes = new ArrayList<Movimentacao>();

    public  Conta(int numero, String nome){
        
        this.numero = numero;
        this.nome = nome;
    }
    public void setNumero(int numero){
        this.numero =numero;

    }
    public int getNumero(){
        return this.numero;
    }
    public void setNome(String nome){
        this.nome=nome;
    }
    public String getNome(){
        return this.nome;
    }
    public void setSaldo(double saldo){
        this.saldo=saldo;
    }
    public double getSaldo(){
        return this.saldo;
    }

    public   void saldo (){
        System.out.println(" O saldo da tua conta é "+ this.saldo);

        
    }

    public  void depositar(double valor){
        this.saldo += valor;
        Movimentacao movimento = new Movimentacao("12/20/2020", valor, 'D');
        this.movimentacoes.add(movimento);
    }

    public  boolean sacar(double valor){
        if (valor<=this.saldo){
            //System.out.println("Saldo disponivel");//
            this.saldo-=valor;
            Movimentacao movimento = new Movimentacao("12/20/2020", valor, 'S');
            this.movimentacoes.add(movimento);
            //resumoExtrato();//
            return true;
        }else{
            System.out.println("Saldo indisponivel");
            return false;
        }
    }
    
    public void resumoExtrato(){
                System.out.println("--------------------------------");
                System.out.println("Resumo do extrato bancaria:");
                System.out.println(" numero da Conta: " +this.getNumero());
                System.out.println("Nome: " + this.getNome());
                System.out.println("O saldo:  " + this.getSaldo());
                System.out.println("------------------------------------");


    }

    abstract void fazManutencao();
    public void extrato(){
        for(int i=0; i<movimentacoes.size(); i++){
            System.out.println("Data " + this.movimentacoes.get(i).data);
            System.out.println("valor " + this.movimentacoes.get(i).valor);
            System.out.println("Tipo "+ this.movimentacoes.get(i).tipo);
        }

    }

    
}
    
