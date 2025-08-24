import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.*;
import java.util.*;

class HuffmanImages1
{
    public static HashMap<Integer, String> hcodes = new HashMap<>();
    public static void main(String args[])throws IOException
    {
        BufferedImage image = ImageIO.read(new File("C:\\Users\\ajman\\Downloads\\jpg2png\\zodd.png"));
        int rows = image.getHeight();
        int cols = image.getWidth();
        ArrayList<Integer> pixels = new ArrayList<>();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int c = image.getRGB(j, i);
                int r = (c >> 16) & 0xFF;
                int g = (c >> 8) & 0xFF;
                int b = c & 0xFF;
                pixels.add(r);
                pixels.add(g);
                pixels.add(b); 
            }
        }
        HashMap<Integer, Integer> values = new HashMap<>();
        for(int i = 0; i < pixels.size(); i++)
        values.put(pixels.get(i), values.getOrDefault(pixels.get(i), 0) + 1);
        PriorityQueue<HuffmanImagesNodes1> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.value));
        for(Map.Entry<Integer, Integer> entry : values.entrySet())
        pq.add(new HuffmanImagesNodes1(entry.getKey(), entry.getValue()));
        HuffmanImagesNodes1 root = null;
        while(pq.size() != 1)
        {
            HuffmanImagesNodes1 n1 = pq.poll();
            HuffmanImagesNodes1 n2 = pq.poll();
            root = new HuffmanImagesNodes1(-1, n1.value + n2.value);
            root.l = n1;
            root.r = n2;
            pq.add(root);
        }
        code(root, "");
        for(Map.Entry<Integer, String> entry : hcodes.entrySet())
        System.out.println(entry.getValue() + " " + entry.getKey());
        StringBuilder sb = new StringBuilder("");
        for(int i = 0; i < pixels.size(); i++)
        sb.append(hcodes.get(pixels.get(i)));
        BufferedWriter bw = new BufferedWriter(new FileWriter("C:\\Users\\ajman\\Downloads\\your_filename.txt"));
        bw.write(sb.toString());
        bw.close();

    }
    public static void code(HuffmanImagesNodes1 root, String code)
    {
        if(root == null)  return;
        if(root.isLeaf() == true)
        hcodes.put(root.pixel, code);
        code(root.l, code + '0');
        code(root.r, code + '1');
    }
}

class HuffmanImagesNodes1
{
    HuffmanImagesNodes1 l;
    HuffmanImagesNodes1 r;
    int pixel;
    int value;

    HuffmanImagesNodes1(int pixel, int value)
    {
        this.pixel = pixel;
        this.value = value;
    }

    public boolean isLeaf()
    {
        if(l == null && r == null)
        return true;
        else
        return false;
    }
}
