import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class DistinctNumbers1621 {
	public static void main (String[]args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int n = Integer.parseInt(br.readLine());
		int[] x = new int[n];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) x[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(x);

		int ans = 1;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] != x[i + 1]) ans++;
		}

		pw.print(ans);
		br.close();
		pw.close();
	}
}