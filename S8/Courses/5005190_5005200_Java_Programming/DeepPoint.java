public class DeepPoint extends Point {
    private int depth;

    public DeepPoint(int x, int y, int depth) {
        super(x, y);
        setDepth(depth);
    }

    public void setDepth(int d){
        if (d < 1) {
            this.depth = 1;
        }
        else if (d > 10) {
            this.depth = 10;
        }
        else {
            this.depth = d;
        }
    }

    public int getDepth(){
        return this.depth;
    }

    @Override
    public void print() {
        for (int i = 0; i < this.depth-1; i++) {
            System.out.print("(");
        }
        super.print();
        for (int i = 0; i < this.depth-1; i++) {
            System.out.print(")");
        }
        
    }   
}
