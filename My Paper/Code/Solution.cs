using System;
using System.IO;
using System.Collections.Generic;

namespace Maples
{
    public class Solution
    {
        public static void Main(string[] args)
        {
            DirectoryInfo directoryInfo = new DirectoryInfo("/Users/maples/Documents/Project/My Paper/Classes");
            FileInfo[] files = directoryInfo.GetFiles();

            List<string> names = new List<string>();
            foreach (var file in files)
            {
                string name = file.Name;
                int index = name.IndexOf('.');

                if (index != 0) 
                {
                    names.Add(name.Substring(0, index));
                }
            }
            DirectoryInfo a = new DirectoryInfo("/Users/maples/Documents/Project/My Paper/Text");
            foreach (var name in names)
            {
                FileInfo file = new FileInfo(name + ".md");
                file.Create();
            }
        }   
    }
}