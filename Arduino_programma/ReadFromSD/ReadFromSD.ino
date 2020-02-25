// Data lezen van de SD kaart
// Vermeulen Gijs Feb 12 2020
// versie 1.0

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

  // check voor de SD kaart en of deze geinitialiseerd kan worden
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  
  Serial.println("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.

  // SD.open heeft 2 variabele nodig, de naam van de file, en of we gaan lezen of schrijven ( read is default )
  ConfigFile = SD.open("datalog.txt", FILE_READ);

  // if the file is available, read from it:
  if (dataFile) 
  {
    while (dataFile.available()) 
    {
      Serial.write(dataFile.read());
    }
    dataFile.close();
    Serial.println("done.");
  }
 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening datalog.txt");
  }
}

void loop() 
{
   // nothing happens after setup
}
