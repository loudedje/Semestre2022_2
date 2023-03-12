public class News extends Post {
    private String source;
    public News() {

    }

    public void setSource(String source) {
        this.source = source;
    }

    public String getSource() {
        return this.source;
    }

    public void show() {
        super.show();
        System.out.println("Source: " + this.source);
    }

}
