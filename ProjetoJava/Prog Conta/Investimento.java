
public class Investimento  extends Conta {
     protected double taxaRendimento;

    public Investimento(int numero,String nome, double taxaRendimento){
        super(numero,nome);
        this.taxaRendimento=taxaRendimento;        
    }
    void setTaxaRendimento(double taxaRendimento){
        this.taxaRendimento = taxaRendimento;
    }
    public double getTaxaRendimento(){
        return taxaRendimento;
    }
    
    @Override
    public void fazManutencao(){
        double valorRendimento = (this.saldo*this.getTaxaRendimento())/100;
        this.saldo+=valorRendimento;
        //System.out.println(" O valor de manutenção é: "+ getTaxaRendimento());
        Movimentacao movimento = new Movimentacao("12/20/2020",this.saldo, 'M');
        this.movimentacoes.add(movimento);
    }

@Override
    public void resumoExtrato(){
        System.out.println("Nome:" +this.getNome());
        System.out.println("Saldo: " +this.getSaldo());
        System.out.println("Rendimento: "+ this.getTaxaRendimento()
        + "\n");
    }
}
