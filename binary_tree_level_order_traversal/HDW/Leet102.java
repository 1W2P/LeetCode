import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

public class Leet102 {
	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) { val = x; }
	}
    public List<List<Integer>> levelOrder(TreeNode root) {
    		Queue<TreeNode> q = new LinkedList<>();
    		List<List<Integer>> list = new LinkedList<List<Integer>>();
    		
    		if(root == null){
    			return list;
    		}
    		q.offer(root);
    		
    		while(!q.isEmpty()){
    			int size = q.size();
    			List<Integer> l = new LinkedList<Integer>();
    			
    			for(int i=0; i<size; i++){
    				TreeNode tmp = (TreeNode)q.poll();
    				if(tmp.left != null){
    					q.offer(tmp.left);
    				}
    				if(tmp.right != null){
    					q.offer(tmp.right);
    				}
    				l.add(tmp.val);
    			}
    			list.add(l);
    		}
    		return list;
    }
}
