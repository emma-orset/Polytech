public class Ma_io extends Player {
    private int hitPoint;
    private boolean invincible;
    private boolean fire;

    public Ma_io(int hitPoint, boolean invincible, boolean fire) {
        super();
        this.hitPoint = hitPoint;
        this.invincible = invincible;
        this.fire = fire;
    }

    public Ma_io() {
        super();
        this.hitPoint = 1;
        this.invincible = false;
        this.fire = false;
    }

    @Override
    public void talk() {
        if (this.hitPoint > 0) {
            System.out.print("It's-a me, Ma_io!");
        } else {
            System.out.print("zzz.");
        }
    }

    @Override
    public void  hit() {
        if(this.hitPoint > 0 && this.invincible == false) {
            this.hitPoint -= 1;
            this.fire = false;
        }
    }

    @Override
    public void mushroom() {
        if(this.hitPoint == 1){
            this.hitPoint = 2;
        }
    }

    @Override
    public void flower() {
        if(this.hitPoint == 1){
            this.hitPoint = 2;
        }

        else if (this.hitPoint == 2){
            this.fire = true;
        }
    }

    @Override
    public void star() {
        this.invincible = true;
    }

    @Override
    public void timeout() {
        this.invincible = false;
    }

    @Override
    public void attack() {
        if(this.fire == true){
            System.out.print("Fire!");
        }
    }
}

