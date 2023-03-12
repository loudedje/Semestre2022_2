import java.util.ArrayList;
public class ContaEspecial extends Conta{
    protected double limite;
    protected double taxaManutencao;
     ArrayList<Movimentacao>movimentacoes = new ArrayList<Movimentacao>();

    public ContaEspecial(int numero,String nome,double limite, double taxaManutencao) {
        super(numero, nome);
        this.limite=limite;
        this.taxaManutencao=taxaManutencao;

    }
    public void setLimite(double limite){
        this.limite = limite;
    }
    public double getLimite(){
        return this.limite;
    }
    public void setTaxaManutencao(double taxaManutencao){
        this.taxaManutencao = taxaManutencao;
    }
    public double getTaxaManutencao(){
        return this.taxaManutencao;
    }

    @Override 
    public boolean sacar(double valor){
        super.sacar(valor);
        return true;
    }

    @Override
    public void fazManutencao(){

        double valorManutencao = (this.saldo*this.taxaManutencao)/100;
        this.saldo-=valorManutencao;
        
        //System.out.println(" O valor de manutenção é: "+ valorManutencao);
        Movimentacao movimento = new Movimentacao("12/20/2020", this.saldo, 'M');
        this.movimentacoes.add(movimento);
    }


    @Override
    public void resumoExtrato(){
        System.out.println("Nome " + this.getNome());
        System.out.println("Saldo " + this.getSaldo());
        System.out.println("Taxa de Manutencao " + this.getTaxaManutencao());
        System.out.println("Limite " +this.getLimite());
    
    }
    public void multiMov(String data, int valor , char tipo){
        this.movimentacoes.add(new Movimentacao(data, valor, tipo));
    }



}
