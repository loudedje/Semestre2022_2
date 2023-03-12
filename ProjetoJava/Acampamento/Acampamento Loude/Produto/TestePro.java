    import java.util.ArrayList;
    import java.util.List;
    import java.util.Scanner;
    
    public class TestePro{
        public static void main(String []args){
            
            int variavel;
            Scanner ler = new Scanner(System.in);
    
            ArrayList<Produto> list = new ArrayList<Produto>();
            
            {
                System.out.println("*=================================================*");
                System.out.println("**Opa! Bem- vindo\n  **");
                System.out.println("1 – Cadastrar Produto");
                System.out.println("2 – Consultar estoque");
                System.out.println("3 – Remover unidades");
                System.out.println("4 – Adicionar unidades");
                System.out.println("5 – imprimir");
                System.out.println("9 – Sair");
                System.out.println("Opcao:");
                int ten = ler.nextInt();
                if (ten == 1){
                    
                    
                    System.out.println("Digite o nome:");
                    String nome = ler.next();
    
                    System.out.println("Digite o valor:");
                    float valor = ler.nextFloat();
    
                    System.out.println("Digite a quantidade:");
                    int quantidade = ler.nextInt();
    
                    Produto p = new Produto(nome, valor, quantidade);
                    list.add(p);
                }else if(ten == 2){
    
                    System.out.println("Digite o codigo do produto:");
                    variavel = ler.nextInt();
    
                    for(int i = 0; i < list.size(); i ++){
                        if (variavel == i){
                            System.out.println("Nome: " +list.get(i).getNome() + "quantidade: " +list.get(i).getQuantidade());
                        }
                        
                    }
                }else 
                    if (ten == 3){
                    System.out.println("Digite o codigo do produto:");
                    variavel = ler.nextInt();
    
                    for(int i = 0; i < list.size(); i ++){
                        if (variavel == i){
                            list.get(i).removerUnidades(i);
                        }
                    }
                 }
                 else if(ten == 4){
                    System.out.println("Digite o codigo do produto:");
                    variavel = ler.nextInt();
                    for(int i = 0; i< list.size(); i ++){
                        if (variavel == i){
                            list.get(i).adicionarUnidades(i);
                        }
                    }
                }
                else if(ten == 5){
                    for(int i = 0; i < list.size(); i ++){
                        System.out.println(list.get(i).toString());
                    }
                }
                else if(ten== 9){
                    break;
                }
                
            }
    
        }
    
    }
    
