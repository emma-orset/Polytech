public class DeepPointTest {
    public static void main(String args[]) {
        Point p = new Point(10, 20);
        p.move(1, -1);
        p.print();
        System.out.println();
        
        DeepPoint dp = new DeepPoint(20, 30, -999);
        dp.move(1, -1);
        dp.print();
        System.out.println();

        dp.setDepth(8);
        //dp.depth = 20;     // コンパイル時にエラーになることを確認してコメントアウトしておくこと
        dp.print();
        System.out.println();

        Point[] pts = new Point[2];
        pts[0] = p; pts[1] = dp;
        
        int i;
        for (i = 0; i < 2; i++) {
            pts[i].moveAndPrint(10, 10);
            System.out.println();
        }
    }
}