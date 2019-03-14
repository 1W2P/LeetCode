import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Interval {
    int start;
    int end;

    Interval() {
        start = 0; end = 0;
    }

    Interval(int s, int e) {
        start = s; end = e;
    }
}

class Solution {
    public List<Interval> merge(List<Interval> intervals) {

        if (intervals.size() <= 1) {
            return intervals;
        }

        Collections.sort(intervals, (i1, i2) -> {
            if (i1.start > i2.start) {
                return 1;
            } else if (i1.start == i2.start) {
                if (i1.end > i2.end) {
                    return 1;
                } else {
                    return 0;
                }
            }

            return -1;
        });

        List<Interval> result = new ArrayList<>();

        result.add(intervals.get(0));
        int resultIndex = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (result.get(resultIndex).end >= intervals.get(i).start) {
                result.get(resultIndex).end = intervals.get(i).end;
            } else {
                result.add(intervals.get(i));
                resultIndex++;
            }
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        Solution s = new Solution();

        List<Interval> list = new ArrayList<>();
        list.add(new Interval(1, 3));
        list.add(new Interval(15, 18));
        list.add(new Interval(2, 6));
        list.add(new Interval(8, 10));

        ArrayList<Interval> arrayList = (ArrayList<Interval>) s.merge(list);

        for (Interval interval : arrayList) {
            System.out.println(interval.start + " " + interval.end);
        }
    }
}