import java.io.*;
import java.nio.charset.StandardCharsets;

public class BinaryFile {
    private String fileName;

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public BinaryFile(String fileName){
        this.fileName = fileName;
    }

    public String readBinFile(){
        String binaryString = "";
        try {
            //Permet de lire le code binaire d'un fichier
            FileInputStream binFile = new FileInputStream(new File(this.getFileName()));
            //Convertit inputStream en BufferedInputStream
            BufferedInputStream binFileReader = new BufferedInputStream(binFile);

            int bit;
            int i = 0;
            //Lire les bits un par un
            while ((bit = binFileReader.read()) != -1) {
                String sbit = Integer.toBinaryString(bit);
                i+=1;
                if (i == 1){
                    binaryString += sbit;
                }else{
                    String sbit_replace = String.format("%8s", sbit).replace(" ", "0");
                    binaryString += sbit_replace;
                }

            }

            // close the reader
            binFileReader.close();

        } catch (IOException ex) {
            ex.printStackTrace();
        }
        return binaryString;
    }
}
