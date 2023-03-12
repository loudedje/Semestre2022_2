import java.util.Scanner;
import java.rmi.server.ExportException;
import java.util.ArrayList;
import java.util.List;

public class Menu {

    public static void curtirPostagem( Post returnV, Scanner ler) throws VoidListException{
        if ( Blog.posts.size() > 0){
            System.out.println("Entrar o codigo do post: ");
            int codigo  = ler.nextInt();

            if (codigo > 0 && codigo == (Blog.posts.size() - 1)){
                returnV = Blog.posts.get(codigo);
                returnV.like();
            }else{
                throw new ArrayIndexOutOfBoundsException("Código invalido, esse Post já existe ! ");
            }

        }else{
            throw new VoidListException("vaziu!\n");
        }
    }
}
public static void dislikePostagem(Post returnV, Scanner ler) throws VoidListException{
    if (Blog.posts.size() > 0){
        System.out.println("Entrar o codigo do post: ");
        int codigo  = ler.nextInt();

        if (codigo > 0 && codigo == (Blog.posts.size() - 1)){
            returnV = Blog.posts.get(codigo);
            returnV.dislike();
        }else{
            throw new ArrayIndexOutOfBoundsException("Código invalido\n");
        }
    }else{
        throw new VoidListException("Lista vazia!\n");
    }
}
public static void main(String []args) throws VoidListException{
    for( ; ; ){

        System.out.println("BLOG: O que você quer fazer?");
        System.out.println("_____________________________________________");
        System.out.println("1 - Novo post de noticia");
        System.out.println("2 - Novo resenha de produto");
        System.out.println("3 - Novo post de outros assuntos");
        System.out.println("4 - Listar todas as postagem"); 
        System.out.println("5 - Curtir uma postagem");
        System.out.println("6 - Curtir uma postagem");
        System.out.println("10- Sair");
        System.out.println("_____________________________________________");
        System.out.println("Escolher uma  opção por favor\n: ");

        Scanner ler = new Scanner(System.in);
        int choix = ler.nextInt();
        Blog blog = new Blog();

        Post returnV = new Post();

        if(choix == 1){
        try{
            News noticia = new News();
            Post post = (Post) noticia;
            blog.readData(post);
            Blog.posts.add(post);
        }catch(Exception e){
            System.out.println(e.getMessage());
        }


        }else if (choix == 2){
            try{
                ProductReview prod = new ProductReview();
                Post post = (Post) prod;
                blog.readData(post);
                Blog.posts.add(post);
            }catch(Exception e){
                System.out.println(e.getMessage());
            }

        }else if(choix == 3){
            try{
                Post post1 = new Post();
                blog.readData(post1);
                Blog.posts.add(post1);
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        

        }else if(choix == 4){
            blog.showAll();

        }else if(choix == 5){
        
        try{
            curtirPostagem(returnV, ler);
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
            

        }else if( choix == 6){

            try{
                curtirPostagem(returnV, ler);
            }catch(Exception e){
                System.out.println(e.getMessage());
            }

        }else if(choix == 10){
        System.out.println("Foi um prazer ver você, espero que volte, até\n");
            break;
        }

    }


}




