public class ProductReview extends Post implements Evaluable {
    private String brand;
    private int stars;

    
    public ProductReview() {

    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return this.brand;
    }

    public void setStars(int stars) {
        this.stars = stars;
    }

    public int getStars() {
        return this.stars;
    }

    public void show() {
        super.show();
        System.out.println("Brand : " + this.brand + "\n" + "Stars: " + this.stars);
    }

    @Override

    public void evaluate(int value) {
        if (value >= 1 && value <= 10) {
            this.stars = value;
        } else {
            System.out.println(" Avaliar novamente!!!");
        }
    }

}
