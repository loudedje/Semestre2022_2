public class Cliente {
    private String nome;
    private String cpf;
    Conta conta;
    public Investimento Investimento;

    public Cliente(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
    }

    public void setNome(String nome){
        this.nome=nome;
        
    }
    public String getNome(){
        return nome;
    }
    public void setCpf(String cpf){
        this.cpf=cpf;
    }
    public String getCpf(){
        return cpf;
    }
    
    

    
}
