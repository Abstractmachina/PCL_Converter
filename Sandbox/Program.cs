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

			//var p = new PCL_CLI.PointXYZ();

			for (int i = 0; i < strings.Length; i++) {
				var coords = strings[i].Split(',');

				Console.WriteLine(strings[i]);
                var p = new PointXYZ(
                    float.Parse(coords[0]),
                    float.Parse(coords[1]),
                    float.Parse(coords[2])
                    );

                cloudXYZ.Pushback(p);
            }

			var  cloud = new PointCloudXYZ();

			Console.WriteLine(cloud.ToString());
			//PCL_CLI.;

			Console.ReadLine();

		}
	}
}
