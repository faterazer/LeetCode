import java.io.*;
import java.nio.charset.StandardCharsets;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Codec {
    private void serialize(TreeNode root, ObjectOutputStream output) {
        try {
            if (root == null) {
                output.writeByte(0);
                return;
            }
            output.writeByte(1);
            output.writeInt(root.val);
            serialize(root.left, output);
            serialize(root.right, output);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        ByteArrayOutputStream buffer = new ByteArrayOutputStream();
        try {
            ObjectOutputStream output = new ObjectOutputStream(buffer);
            serialize(root, output);
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return buffer.toString(StandardCharsets.ISO_8859_1);
    }

    private TreeNode deserialize(ObjectInputStream input) {
        TreeNode root = null;
        try {
            if (input.readByte() == 0) {
                return null;
            }
            root = new TreeNode(input.readInt());
            root.left = deserialize(input);
            root.right = deserialize(input);

        } catch (IOException e) {
            e.printStackTrace();
        }
        return root;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        ByteArrayInputStream buffer = new ByteArrayInputStream(data.getBytes(StandardCharsets.ISO_8859_1));
        ObjectInputStream input = null;
        try {
            input = new ObjectInputStream(buffer);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return input == null ? null : deserialize(input);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
