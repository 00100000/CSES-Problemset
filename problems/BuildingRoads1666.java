// TLE on 5 cases likely because of java

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BuildingRoads1666 {
	private static ArrayList<Integer>[] list;
	private static boolean[] visited;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		list = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			list[i] = new ArrayList<Integer>(0);
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			list[a].add(b);
			list[b].add(a);
		}
		// dfs
		ArrayList<Integer> componentFirsts = new ArrayList<Integer>(0);
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				componentFirsts.add(i);
				dfs(i);
			}
		}

		pw.println(componentFirsts.size() - 1);
		for (int i = 0; i < componentFirsts.size() - 1; i++) {
			pw.println((componentFirsts.get(i)) + 1 + " " + (componentFirsts.get(i + 1) + 1));
		}
		br.close();
		pw.close();
	}
	static void dfs(int n) {
		if (visited[n]) {
			return;
		} else {
			visited[n] = true;
			for (Integer i : list[n]) {
				if (!visited[i]) {
					dfs(i);
				}
			}
		}
	}
}