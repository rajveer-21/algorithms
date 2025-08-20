import java.io.*;
import java.util.*;

class SegmentTree
{
    public final int segTree[];
    public final int maxTree[];
    public final int minTree[];
    SegmentTree(int len)
    {
        segTree = new int[len * 4];
        maxTree = new int[len * 4];
        minTree = new int[len * 4];
    }
    
    public void buildSEG(int node, int l, int r, int arr[])
    {
        if(l == r)
        {
            segTree[node] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        buildSEG(node * 2, l, m, arr);
        buildSEG(node * 2 + 1, m + 1, r, arr);
        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
    
    public void buildMAX(int node, int l, int r, int arr[])
    {
        if(l == r)
        {
            maxTree[node] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        buildMAX(node * 2, l, m, arr);
        buildMAX(node * 2 + 1, m + 1, r, arr);
        maxTree[node] = Math.max(maxTree[node * 2], maxTree[node * 2 + 1]);
    }
    
    public void buildMIN(int node, int l, int r, int arr[])
    {
        if(l == r)
        {
            minTree[node] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        buildMIN(node * 2, l, m, arr);
        buildMIN(node * 2 + 1, m + 1, r, arr);
        minTree[node] = Math.min(minTree[node * 2], minTree[node * 2 + 1]);
    }
    
    public int SUMQuery(int node, int l, int r, int ql, int qr)
    {
        if(qr < l || ql > r)
        {
            return 0;
        }
        if(ql <= l && r <= qr)
        {
            return segTree[node];
        }
        int m = (l + r) / 2;
        int sumLeft = SUMQuery(node * 2, l, m, ql, qr);
        int sumRight = SUMQuery(node * 2 + 1, m + 1, r, ql, qr);
        return sumLeft + sumRight;
    }
    
    public int MAXQuery(int node, int l, int r, int ql, int qr)
    {
        if(qr < l || ql > r)
        {
            return Integer.MIN_VALUE;
        }
        if(ql <= l && r <= qr)
        {
            return maxTree[node];
        }
        int m = (l + r) / 2;
        int maxLeft = MAXQuery(node * 2, l, m, ql, qr);
        int maxRight = MAXQuery(node * 2 + 1, m + 1, r, ql, qr);
        return Math.max(maxLeft, maxRight);
    }
    
    public int MINQuery(int node, int l, int r, int ql, int qr)
    {
        if(qr < l || ql > r)
        {
            return Integer.MAX_VALUE;
        }
        if(ql <= l && r <= qr)
        {
            return minTree[node];
        }
        int m = (l + r) / 2;
        int minLeft = MINQuery(node * 2, l, m, ql, qr);
        int minRight = MINQuery(node * 2 + 1, m + 1, r, ql, qr);
        return Math.min(minLeft, minRight);
    }
    
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int len = 0;
        System.out.println("Enter the size of the array : ");
        len = Integer.parseInt(br.readLine());
        SegmentTree SEGTREE = new SegmentTree(len);
        int arr[] = new int[len];
        System.out.println("Enter the elements : ");
        for(int i = 0; i < len; i++)
        arr[i] = Integer.parseInt(br.readLine());
        SEGTREE.buildSEG(1, 0, len - 1, arr);
        SEGTREE.buildMAX(1, 0, len - 1, arr);
        SEGTREE.buildMIN(1, 0, len - 1, arr);
        while(true)
        {
            System.out.println("enter the choice you want : 1 = SUM, 2 = MAX, 3 = MIN, Anything Else = EXIT");
            int choice = Integer.parseInt(br.readLine());
            switch(choice)
            {
                case 1:
                {
                    int ql, qr;
                    System.out.println("enter range to search : ");
                    ql = Integer.parseInt(br.readLine());
                    qr = Integer.parseInt(br.readLine());
                    System.out.println(SEGTREE.SUMQuery(1, 0, len - 1, ql, qr));
                    break;
                }
                case 2:
                {
                    int ql, qr;
                    System.out.println("enter range to search : ");
                    ql = Integer.parseInt(br.readLine());
                    qr = Integer.parseInt(br.readLine());
                    System.out.println(SEGTREE.MAXQuery(1, 0, len - 1, ql, qr));
                    break;
                }
                case 3:
                {
                    int ql, qr;
                    System.out.println("enter range to search : ");
                    ql = Integer.parseInt(br.readLine());
                    qr = Integer.parseInt(br.readLine());
                    System.out.println(SEGTREE.MINQuery(1, 0, len - 1, ql, qr));
                    break;
                }
                default:
                {
                    return;    
                }
            }
        }
    }
}
