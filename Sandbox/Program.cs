using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using PCL_CLI;

using PclSharp;

namespace Sandbox {
    internal class Program {
        static void Main(string[] args) {

			string filepath = @"C:\Users\Taole\source\repos\Pcl_Converter\Sandbox\test.csv";

			string[] strings = File.ReadAllLines(filepath);

			var cloudXYZ = new PointCloudXYZ();

			for (int i = 0; i < strings.Length; i++) {
				var coords = strings[i].Split(',');

				//Console.WriteLine(strings[i]);
                var p = new PointXYZ(
                    float.Parse(coords[0]),
                    float.Parse(coords[1]),
                    float.Parse(coords[2])
                    );
				//Console.WriteLine(p.ToString());
                cloudXYZ.Pushback(p);
            }

			var f = new Features();

			var normals = f.CalcNormals(cloudXYZ, 8f);

			for (int i = 0; i < normals.Size; i++) {
				var n = normals[i];
				Console.WriteLine($"n1: {n.ToString()}");
			}

			string outPath = @"..\..\output\normalsOut00.csv";
			string[] output = new string[normals.Size];
			using (StreamWriter writer = new StreamWriter(outPath)) {
				for (int i = 0; i < normals.Size; i++) {
					var n = normals[i];
					writer.WriteLine($"{n.Normal_X},{n.Normal_Y},{n.Normal_Z},{n.Curvature}");
				}
				Console.WriteLine("Writing To File Finished.");
			}
			


			//
			//Console.WriteLine(cloud.ToString());
			//PCL_CLI.;

			Console.ReadKey();

		}
	}
}
