import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class SumOfTwoValues1640 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] a = new int[n];
		HashSet<Integer> set = new HashSet<Integer>(0);
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			set.add(a[i]);
		}
		br.close();
		// check if set contains the other number needed to sum to x
		for (int i = 0; i < n; i++) {
			if (set.contains(x - a[i])) {
				for (int j = 0; j < n; j++) {
					if (a[j] == x - a[i] && i != j) {
						pw.print((i + 1) + " " + (j + 1));
						pw.close();
						return;
					}
				}
			}
		}

		pw.print("IMPOSSIBLE");
		pw.close();
	}
}