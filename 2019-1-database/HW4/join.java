import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
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
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.input.MultipleInputs;

public class join{

	public static class EmpMapper extends Mapper <Object, Text, Text, Text> {
		public void map(Object key, Text value, Context context)
				throws IOException, InterruptedException {
 			String record = value.toString(); 	// Reads the record
			String[] parts = record.split(","); // Split the input.
			context.write(new Text(parts[7]), new Text("emp," + parts[0]));
			// key : deptno, value: emp(sign that it is emp) + empno
	 	}
 	}

	public static class DeptMapper extends Mapper <Object, Text, Text, Text> {
		public void map(Object key, Text value, Context context) 
				throws IOException, InterruptedException {
			String record = value.toString(); 	// Reads the record
			String[] parts = record.split(","); // Split the input.
			context.write(new Text(parts[0]), new Text("dept," + parts[1]));
			// key : deptno, value: dept(sign that it is dept) + dept_name
		}
	}
	
	public static class ReduceJoinReducer extends Reducer <Text, Text, Text, IntWritable> {
		private IntWritable val = new IntWritable();
		public void reduce(Text key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
			
			ArrayList<String> empno = new ArrayList<String>();
			// String that stores the department name of each department number
			String dept_name = "";				

			// Records the emp, dept value that corresponds to dept_no
			for (Text t : values) {
				String parts[] = t.toString().split(",");
				if (parts[0].equals("emp")) empno.add(parts[1]);

				// Note that there is one department name for each department number
 				else if (parts[0].equals("dept")) 	dept_name = parts[1];	
			}

			// Counts the number of employee
			int sum = 0;
			for (String s : empno){
				sum += 1;
			}
			val.set(sum);
			// If there is no department name or employee, that it is not recorded
			if(sum != 0) context.write(new Text(dept_name), val);
		}
	}

	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();
		Job job = new Job(conf, "Reduce-side join");
		job.setJarByClass(join.class);
		job.setReducerClass(ReduceJoinReducer.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
	  
		MultipleInputs.addInputPath(job, new Path(args[0]),TextInputFormat.class, EmpMapper.class);
		MultipleInputs.addInputPath(job, new Path(args[1]),TextInputFormat.class, DeptMapper.class);
		
		Path outputPath = new Path(args[2]);
		FileOutputFormat.setOutputPath(job, outputPath);
		outputPath.getFileSystem(conf).delete(outputPath);
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
}