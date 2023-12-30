import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        String files[] = {"alice", "extraitAlice", "textesimple", "texteperso", "exemple"};

        for (String file : files) {
            String path = "Resources/" + file + "/" + file;


            Tree tree = new Tree(path + "_freq.txt");
            Encode encode = new Encode();
            BinaryFile binFile = new BinaryFile(path + "_comp.bin");
            HashMap<String, String> dictEncode = encode.dictEncode(tree.getRoot(), "");
            String text = binFile.readBinFile();

            try {
                FileWriter newFile = new FileWriter(path + ".txt");
                String character = "";
                String newText = "";
                for (int i = 0; i < text.length(); i++) {

                    character += text.charAt(i);
                    for (String c : dictEncode.keySet()) {
                        if (character.compareTo(dictEncode.get(c)) == 0) {
                            newText += c;
                            character = "";
                        }
                    }
                }

                newText = newText.replace("\\n", "\n");
                newFile.write(newText);

                newFile.close();
            } catch (IOException e) {
                System.out.println("Error.");
                e.printStackTrace();
            }

        }

    }
}