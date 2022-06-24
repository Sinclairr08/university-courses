import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WordCount {

  public static class TokenizerMapper
       extends Mapper<Object, Text, Text, IntWritable>{

    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();

    public void map(Object key, Text value, Context context
                    ) throws IOException, InterruptedException {
      StringTokenizer itr = new StringTokenizer(value.toString());
      while (itr.hasMoreTokens()) {
        word.set(itr.nextToken());
        context.write(word, one);
      }
    }
  }

  public static class IntSumReducer
       extends Reducer<Text,IntWritable,Text,IntWritable> {
    private IntWritable result = new IntWritable();

    public void reduce(Text key, Iterable<IntWritable> values,
                       Context context
                       ) throws IOException, InterruptedException {
      int sum = 0;
      for (IntWritable val : values) {
        sum += val.get();
      }
      result.set(sum);
      context.write(key, result);
    }
  }

  public static void main(String[] args) throws Exception {
    Configuration conf = new Configuration();
    Job job = Job.getInstance(conf, "word count");
    job.setJarByClass(WordCount.class);
    job.setMapperClass(TokenizerMapper.class);
    job.setCombinerClass(IntSumReducer.class);
    job.setReducerClass(IntSumReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
    FileInputFormat.addInputPath(job, new Path(args[0]));
    FileOutputFormat.setOutputPath(job, new Path(args[1]));
    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}

public static class JoinMapper1 extends Mapper <Object, Text, Text, Text> {

  public void map(Object key, Text value, Context context)
      throws IOException, InterruptedException {
    String record = value.toString(); // Read the input text value.
    String[] parts = record.split(","); // Split the input.

    // key) Select the B attribute that we want to join.
    // values) Add “R” string as a sign that where the mapped lists are came from.
    // values) Select the ‘A’ attribute that we want to print.

    context.write(new Text(parts[1]), new Text("R," + parts[0]));

  }
 }

public static class JoinMapper2 extends Mapper <Object, Text, Text, Text> {

  public void map(Object key, Text value, Context context)
      throws IOException, InterruptedException {
    String record = value.toString(); // Read the input text value.
    String[] parts = record.split(","); // Split the input.

    // key) Select the B attribute that we want to join.
    // values) Add “S” string as a sign that where the mapped lists are came from.
    // values) Select the ‘C’ attribute that we want to print.

    context.write(new Text(parts[0]), new Text("S," + parts[1]));

  }
 }

 public static class ReduceJoinReducer extends Reducer <Text, Text, Text, Text> {

  public void reduce(Text key, Iterable<Text> values, Context context)
      throws IOException, InterruptedException {

    ArrayList<String> name = new ArrayList<String>();
    String dept = "";

    // Each element is like (“R”, name) from R, or (“S”, dept) from S.
    for (Text t : values) {
      // By splitting, we will obtain a sign string (parts[0]) and a string to print (parts[1]).
      String parts[] = t.toString().split(",");

      // Find the list of name strings and store them into the name arraylist.
      if (parts[0].equals("R"))
        name.add(parts[1]);
      // Find the dept for a given key.
      else if (parts[0].equals("S"))
        dept = parts[1];
    }
    // Print each (name, dept) pair.
    for (String s : name) context.write(new Text(s), new Text(dept));
  }
}

