public class Acampamento{
    private String nome;
    private int idade;
    private char equipe;
    

    public Acampamento(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
        setNome(nome);
        setIdade(idade);
    }
    public void definirEquipe(){
        
        if(idade >= 6 && idade <= 10){
            setEquipe ("A");
            return;
        }else if(idade >= 11 && idade <= 20 ){
            setEquipe("B");
            return;
        }else if(idade >= 21){
            setEquipe("C");
            return;
        }
    }
    private void setEquipe(String string) {
    }
    public void setNome(String nome) {
        this.nome=nome;
    }
    public void setIdade(int idade){
        this.idade=idade;
    }
    public void setEquipe(char equipe){
        this.equipe=equipe;
    }
    public String getNome(){
        return this.nome;
    }
    public int getIdade(){
        return this.idade;
    }
    public char getEquipe(){
        return this.equipe;
    }
    public String toString() {
        
        return "O Nome" + getNome() + " a idade" +getNome() + " e Equipe"+getEquipe();
    }    
    }


