import java.util.ArrayList;
import java.util.Collections;

public class Tree {

    private String nameFile;
    private Node root;

    public String getNameFile() {
        return nameFile;
    }

    public void setNameFile(String nameFile) {
        this.nameFile = nameFile;
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    public Tree(String nameFile){
        this.nameFile = nameFile;
        Dictionnary dictHM = new Dictionnary(this.nameFile);
        ArrayList<Node> listNode = new ArrayList<Node>();

        //Création de toutes les nodes
        //Le label est la clé du HM et la fréquence est le nombre associé
        for (String c : dictHM.readDict().keySet()) {
            listNode.add(new Node(dictHM.readDict().get(c), c));
        }

        //Création de l'arbre tant qu'il y a plus d'une node
        while (listNode.size() > 1){

            Collections.sort(listNode, Node.compareFreq);

            Node leftNode = listNode.remove(0);
            Node rightNode = listNode.remove(0);

            Node parentNode = new Node(leftNode.getFreq() + rightNode.getFreq(), null);
            parentNode.setChildren(leftNode, rightNode);

            listNode.add(parentNode);



        }
        //La dernière node qu'il reste devient la racine qui contient tout l'arbre
        this.root = listNode.get(0);
    }
}