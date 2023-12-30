import java.util.Arrays;

public class MainTest {
    public static void main(String[] args) {
        String dictFile = "Resources/texteperso/texteperso_freq.txt";
        Dictionnary dict = new Dictionnary(dictFile);
        System.out.println(Arrays.asList(dict.readDict()));

        Tree tree = new Tree(dictFile);
        System.out.println(tree.getRoot());
    }
}