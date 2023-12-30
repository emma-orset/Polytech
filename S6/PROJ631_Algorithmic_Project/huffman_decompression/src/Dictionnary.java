import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;

public class Dictionnary {
    private String fileName;

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public Dictionnary(String fileName) {
        this.fileName = fileName;
    }

    //Création d'un HashMap qui va stocker les caractères du dictionnaire associés à leur fréquence sous forme de clé/valeur
    public HashMap<String,Integer> readDict() {
        HashMap<String,Integer> dict = new HashMap<String,Integer>();
        File document = new File(this.fileName);
        try{
            BufferedReader file = new BufferedReader(new FileReader(document, StandardCharsets.UTF_8));
            String line;
            int numLine = 1;

            //Tant que la ligne qu'on lit a quelque chose d'écrit
            while((line = file.readLine()) != null){

                //Parcourir le dictionnaire
                if (numLine > 2 && line.length() > 1){
                    String freq="";
                    if(line.charAt(1) == ' '){

                        //Pour un grand texte, la fréquence du cacatère peut être >9
                        for(int i=2; i<line.length();i++) {
                            freq = freq + line.charAt(i);
                        }

                        //La clé du HM est le caractère et la valeur associée est la fréquence associée
                        dict.put(String.valueOf(line.charAt(0)), Integer.parseInt(freq));

                    }
                    //Si c'est un \n
                    else{

                        for(int i=3; i<line.length();i++) {
                            freq = freq + line.charAt(i);
                        }

                        //La clé du HM est le caractère et la valeur associée est la fréquence associée
                        dict.put(String.valueOf(line.charAt(0)) + String.valueOf(line.charAt(1)), Integer.parseInt(freq));

                    }

                }
                numLine++;

            }
            file.close();

        }
        catch (IOException error){
            error.printStackTrace();
        }


        return dict;
    }


}
