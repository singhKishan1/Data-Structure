package javarepo;
import java.util.Scanner;

public class XORQueriesOfASubarray {

    private static Scanner sc = new Scanner(System.in);

    private static int findRangeXor(int[]pf, int l, int r){
        if(l==0)return pf[r];
        return pf[r] ^ pf[l-1];
    }

    private static int[] solve(int[]arr, int[][]queries){
        int n= arr.length;
        int[] pf = new int[n];
        
        pf[0] = arr[0];
        for(int i=1; i<n; ++i)
            pf[i] = pf[i-1] ^ arr[i];
        
        int[]ans = new int[queries.length];
        for(int i=0; i<queries.length; ++i){
            ans[i] = findRangeXor(pf, queries[i][0], queries[i][1]);
        }

        return ans;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; ++i)arr[i] = sc.nextInt();

        int m = sc.nextInt();
        int[][] queries = new int[m][2];
        for(int i=0; i<m; ++i){
            queries[i][0] = sc.nextInt();
            queries[i][0] = sc.nextInt();
        }

        int[] ans = solve(arr, queries);
        for(int x:ans){
            System.out.print(x + "  ");
        }
    }
}
