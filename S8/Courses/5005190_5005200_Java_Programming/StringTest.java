public class Main {
  public static void main(String[] args) {
    String msg = "The quick brown fox jumps over the lazy dog.";
    
    // Find the position of the last occurrence of the character 'e'
    int lastEPos = msg.lastIndexOf('e');
    System.out.printf("The last 'e' is at position %d.%n", lastEPos);

    // Extract the substring from the 11th character to the 20th character
    String sub = msg.substring(11, 21);
    System.out.printf("The substring is '%s'.%n", sub);
  }
}