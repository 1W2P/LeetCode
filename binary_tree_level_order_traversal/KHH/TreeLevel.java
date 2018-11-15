import java.util.*;

public class TreeLevel 
{
    public List<List<Integer>> levelOrder(TreeNode root) 
    {
        List<List<TreeNode>> treeList = new ArrayList<List<TreeNode>>();
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        
        if(root == null)
        {
            return result;
        }

        treeList.add(new ArrayList<TreeNode>());
        treeList.get(0).add(root);

        int line = 0;
        while (true) 
        {
            List<TreeNode> newNodes = new ArrayList<>();
            List<Integer> newLine = new ArrayList<>();
            List<TreeNode> currNodes = treeList.get(line);
            
            for (TreeNode node : currNodes) {
                newLine.add(node.val);
                if (node.left != null) {
                    newNodes.add(node.left);
                    
                }
                if (node.right != null) {
                    newNodes.add(node.right);
                }
            }
            result.add(newLine);

            if (newNodes.isEmpty()) {
                break;
            }

            treeList.add(newNodes);
            
            ++line;
        }
        
        return result;
    }
}