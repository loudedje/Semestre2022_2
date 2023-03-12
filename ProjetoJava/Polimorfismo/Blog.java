import java.util.*;



public class Blog {
    static List<Post> posts = new ArrayList <Post>();

    public void readData(Post p){
        
        try (Scanner lire = new Scanner(System.in)) {
            Date data = new Date();
      
            if (p instanceof News){
                News news = (News) p;
                System.out.println("Digite o Title:");
                String title = lire.next();
                news.setTitle(title);

               for(int i = 0 ; i < posts.size() ; i++){
                System.out.println("Title: " +title);
                System.out.println("O Title: " +posts.get(i).getTitle());
                    if(title.equals(posts.get(i).getTitle())){
                        throw new RuntimeException(" esse Titulo já está  Registrado! ");
                    }
               }

   
                System.out.println("Entrar o conteúdo: ");
                String content = lire.next();
                news.setContent(content);

                System.out.println("Entrar the source of the news: ");
                String source = lire.next();
                news.setSource(source);

                news.setLikes(2);

                news.setDislikes(1);
                news.setData(data);

            }else if(p instanceof ProductReview){
                ProductReview productReview = (ProductReview) p;

                System.out.println("Digite o Title:");
                String title = lire.next();
                productReview.setTitle(title);

                for(int i = 0 ; i < posts.size() ; i++){
                    if(title.equals(posts.get(i).getTitle())){
                        throw new RuntimeException("Titulo já existe!");
                    }
               }

                System.out.println("Entrar o conteúdo: ");
                String content = lire.next();
                productReview.setContent(content);

                System.out.println("Entrar o brand do produto: ");
                String brand = lire.next();
                productReview.setBrand(brand);

                System.out.println("  Entrar o numero de stars: ");
                int stars = lire.nextInt();
                productReview.evaluate(stars);

                productReview.setLikes(2);

                productReview.setDislikes(1);
                productReview.setData(data);

            }else{

                Post post = p;

                System.out.println("Entrar o Title:");
                String title = lire.next();
                post.setTitle(title);

                for(int i = 0 ; i < posts.size() ; i++){
                    if(title.equals(posts.get(i).getTitle())){
                        throw new RuntimeException(" Esse titulo já existe!");
                    }
               }

                System.out.println("Entrar o conteúdo: ");
                String content = lire.next();
                post.setContent(content);

                post.setLikes(2);
                post.setDislikes(1);
                post.setData(data);

                
            }
        }

       
    }

    public void showAll(){
        Iterator <Post> p = posts.iterator();
        Post p1;
        while (p.hasNext()){
            p1 = p.next();
            p1.show();

            System.out.println("**==========================================================**\n");
        }
    }
}
