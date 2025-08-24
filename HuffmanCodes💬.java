import java.io.*;
import java.util.PriorityQueue;
class Huffman
{
    public static void main(String args[])throws IOException
    {
        char chars[] = {'a','b','c','d','e'};
        int values[] = {1, 2, 3, 4, 5};
        PriorityQueue <HuffmanNode> pq = new PriorityQueue<>(chars.length, (a,b) -> a.val - b.val);
        for(int i = 0; i < 5; i++)
        {
            HuffmanNode hn = new HuffmanNode(null, null, values[i], chars[i]);
            pq.add(hn);
        }
        HuffmanNode root = null;
        while(pq.size() > 1)
        {
            HuffmanNode one = pq.peek();
            pq.poll();
            HuffmanNode two = pq.peek();
            pq.poll();
            HuffmanNode use = new HuffmanNode(one, two, one.val + two.val, '-');
            root = use;
            pq.add(use);
        }
        print(root, "");
    }
    public static void print(HuffmanNode root, String code)
    {
        if(root.left == null && root.right == null && root.ch != '-')
        {
            System.out.println(root.ch + " " + code);
            return;
        }
        print(root.left, code + '0');
        print(root.right,code + '1');
    }
}
class HuffmanNode
{
    int val;
    char ch;
    HuffmanNode left;
    HuffmanNode right;
    HuffmanNode(HuffmanNode left, HuffmanNode right, int val, char ch)
    {
        this.left = left;
        this.right = right;
        this.val = val;
        this.ch = ch;
    }
}
