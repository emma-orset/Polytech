import java.util.HashMap;

public class Encode {
    private HashMap<String, String> encode = new HashMap<String, String>();

    public Encode() {
    }

    public HashMap<String, String> dictEncode(Node node, String code) {
        if(node == null){
            return null;
        }
        if (node.getLabel() != null){
            this.encode.put(node.getLabel(), code);
        }
        this.dictEncode(node.getLeftChild(), code + "0");
        this.dictEncode(node.getRightChild(), code + "1");
        return this.encode;
    }

}
