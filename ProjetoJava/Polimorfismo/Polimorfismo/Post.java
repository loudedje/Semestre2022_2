import java.util.Date;

public class Post {
    private String title;
    private String content;
    private int likes = 0;
    private int dislikes;
    private Date date;

    public Post() {

    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }

    public void setLikes(int likes) {
        this.likes = likes;
    }

    public int getLikes() {
        return this.likes;
    }

    public void setDislikes(int dislikes) {
        this.dislikes = dislikes;
    }

    public int getDilikes() {
        return this.dislikes;
    }

    public void setData(Date data) {
        this.date = data;
    }

    public void show() {
        System.out.print("Titulo : " + this.title );
        System.out.println("Data : " + this.date);
        System.out.println("Like: " + this.likes);
        System.out.println("Dislike: " + this.dislikes);
        System.out.println("Conteúdo: " + this.content);
    }

    public void like() {
        this.likes += 1;
    }

    public void dislike() {
        this.dislikes += 1;
    }

    public Date getDate() {
      return this.date;
    }

    public static void add(Post p) {

    }
    
}