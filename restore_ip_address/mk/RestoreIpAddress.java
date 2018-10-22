package leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

/**
 * @author manki.kim
 **/
public class RestoreIpAddress {
	public List<String> restoreIpAddresses(String s) {
		List<String> results = new ArrayList<>();
		final int START = 1;
		final int END = 3;
		for (int a = START; a <= END; a++)
			for (int b = START; b <= END; b++)
				for (int c = START; c <= END; c++)
					for (int d = START; d <= END; d++) {
						if (a + b + c + d == s.length()) {
							String first = s.substring(0, a);
							String second = s.substring(a, a + b);
							String third = s.substring(a + b, a + b + c);
							String fourth = s.substring(a + b + c, a + b + c + d);
							if (Integer.parseInt(first) > 255 || Integer.parseInt(second) > 255
								|| Integer.parseInt(third) > 255 || Integer.parseInt(fourth) > 255) {
								continue;
							}

							if (isValid(first) || isValid(second) || isValid(third) || isValid(fourth)) {
								continue;
							}
							StringJoiner joiner = new StringJoiner(".");
							joiner.add(first).add(second).add(third).add(fourth);

							String ip = joiner.toString();
							if (ip.length() == s.length() + 3) {
								results.add(ip);
							}
						}
					}

		return results;
	}

	private boolean isValid(String s) {
		return !(s.length() > 1 && s.startsWith("0"));
	}
}
