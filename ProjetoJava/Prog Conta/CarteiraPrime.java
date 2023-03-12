
import java.util.ArrayList;

public class CarteiraPrime {
   private ArrayList<Cliente>clientes = new ArrayList<Cliente>();
    
    public void addClientes( Cliente addcli){
        this.clientes.add(addcli);
    }
    public void listarClientes(){
        for(int i=0 ; i< clientes.size() ; i++){
            System.out.println(" Nome: " +clientes.get(i).getNome());
            System.out.println("CPF" +clientes.get(i).getCpf());
        }
    }
}
