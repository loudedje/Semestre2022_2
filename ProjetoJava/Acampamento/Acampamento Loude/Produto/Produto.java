public class Produto {
    private String nome;
    private float valor;
    private int quantidade;

    public Produto(String nome, float valor, int quantidade){
        this.nome = nome;
        this.valor = valor;
        this.quantidade = quantidade;
    }

    void setNome (String nome){
        this.nome = nome;
    }

    String getNome(){
        return this.nome;
    }

    void setvalor(float valor){
        this.valor = valor;
    }

    float getValor(){
        return this.valor;
    }

    void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }

    int getQuantidade(){
        return this.quantidade;
    }

    boolean verificarDisponibilidade(int qtde){
        if (this.quantidade >= qtde){
            return true;
        } else{
            return false;
        }
    }

    void adicionarUnidades(int qtde){
        this.quantidade += qtde;
    }

    boolean removerUnidades(int qtde){
        if(verificarDisponibilidade(qtde) == true){
            this.quantidade -= quantidade;
            return true;
        }else{
            return false;
        }
    }

    public String toString(){
        return "Nome: " +getNome() + "valor: " +getValor() +" Quantidade: " +getQuantidade();
    }
}
