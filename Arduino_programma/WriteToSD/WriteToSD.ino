// Data schrijven naar de SD kaart
// Vermeulen Gijs Feb 12 2020
// Versie 1.0

#include <SPI.h>
#include <SD.h>

const int chipSelect = 4; // de CS pin
File ConfigFile;

void setup() 
{
  // Open serial communications and wait for port to open:
  // seriele communicatie is om te debuggen
  
  Serial.begin(9600);
  while (!Serial) 
  {
   ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print("Initializing SD card...");

  // Check voor de SD kaart en of deze geinitialiseerd kan worden
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
   
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  
  ConfigFile = SD.open("datalog.txt", FILE_WRITE);
   // if the file is available, write to it:
  if (myFile) 
  {
     Serial.print("Writing to test.txt...");
     myFile.println("This is a test file :)");
     myFile.println("testing 1, 2, 3.");
     for (int i = 0; i < 20; i++) 
     {
        myFile.println(i);
     }
     // close the file:
     myFile.close();
     Serial.println("done.");
  }
  else 
  {
  // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
void loop() 
{
  // nothing happens after setup
}
