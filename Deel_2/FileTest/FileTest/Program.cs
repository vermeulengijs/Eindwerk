using System;
using System.IO;
using System.Text;

namespace FileTest
{
    class Program
    {
        static void Main()
        {
            string path = @"C: \Users\Gijs\Desktop\testmap\MyTest.txt";

            // kijken of de file bestaat op de aangegeven locatie
            if (File.Exists(path))
            {
                // file bestaat
                Console.WriteLine("File exists");

                // Open the stream and read it back.
                using (StreamReader sr = File.OpenText(path))
                {
                    string s = "";
                    while ((s = sr.ReadLine()) != null)
                    {
                        Console.WriteLine(s);
                    }
                }
            }
            else
            {
                // file bestaat niet
                Console.WriteLine("File does not exist");
            }
            
            /*
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }*/
        }
    }
}
