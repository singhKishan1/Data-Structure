package javarepo;

import java.util.Scanner;

public class CountTheNumberOfConsistentString {

    public static int solve(String allowed, String[] words) {
        int cnt = 0;
        for (String s1 : words) {
            boolean check = true;
            for (int i = 0; i < s1.length(); ++i) {
                if (allowed.indexOf(s1.charAt(i)) < 0) {
                    check = false;
                    break;
                }
            }

            if (check)
                ++cnt;
        }

        return cnt;
    }

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String allowed = sc.nextLine();
        int n = sc.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; ++i)
            words[i] = sc.nextLine();

        System.out.println(solve(allowed, words));
    }
}
