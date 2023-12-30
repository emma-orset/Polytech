public class Ma_ioTest {
   public static void main(String[] args) {
      int i;
      Player[] players = { new Ma_io(), new Ma_io(), new Ma_io(), new Ma_io() };
      players[1].mushroom(); 
      players[2].mushroom(); 
      players[2].flower(); 
      players[3].mushroom(); 
      players[3].flower(); 
      players[3].star();
      for (i = 0 ; i < 3; i++) {
         for (Player p: players) {
            p.talk();
            System.out.print(" ");
            p.attack();
            System.out.print(" ");
            p.hit();
            System.out.println();
         }
         System.out.println("---");
      }
   }
}