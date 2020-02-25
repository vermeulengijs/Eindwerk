// Ethernet connectie op de LAN aanzetten
// Vermeulen Gijs 13 feb 2020
// versie 1.0

// ethernet shield pinnen:
// 11 MOSI, 12 MISO , 13 CLK
// CS ethernet controller pin 10
// CS SD kaart pin 4

// verbinden met de lokale dataserver via LAN WERKT
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

// MAC address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// aangezien we geen gebruik kunnen maken van een DNS
// IP addressen

IPAddress ip( 192, 168, 0, 177 );  // lokaal ip van de arduino
IPAddress server(192, 168, 0, 248); // ip lokale server kantoor

//IPAddress server (104,27,153,209);  // ip van de jason test server
//char Servername[] = "hercules/JULIETTELC/swagger/ui/index#!";

// constante maken voor de ChipSelect pinnen
const int ChipSelectEthernet = 10;
const int ChipSelectSD = 4;

// initialisatie van de ethernet client library
EthernetClient client;


void setup()
{
  int a; // serverResponse
  
  // disable SD SPI
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  
  Serial.begin(9600);
  while( !Serial )
  {
    ; // wait for serial port to connect ( debug )
  }
  Ethernet.init( ChipSelectEthernet );   
  Serial.println("Initialize ethernet ");
  Ethernet.begin( mac, ip);
  Serial.print( "Using fixed");
  // geef de ethernet shield 1 seconde om te initialiseren
  delay( 1000 );
  
  Serial.print( "IP = " );
  Serial.println( Ethernet.localIP() );

  // Als we een connectie kunnen maken
    a = client.connect(server, 80);
    if ( a == 1 )
    {
      Serial.println("Succes");
      Serial.print( "connected to ");
      Serial.println(client.remoteIP());
      // EEN HTTP request doen
      client.println("GET /JULIETTELC/api/Machine?MachineId=1&EventCode=1&Log=1 HTTP/1.1");
      client.println("Host: 192.168.0.248");
      client.println("Connection: close");
      client.println();
    }
    else if ( a == -1 )
    {
      Serial.println("Timed out");
       Serial.println( "connection failed");
    }
    else if ( a == -2 )
    {
      Serial.println("Invalid Server");
       Serial.println( "connection failed");
    }
    else if ( a == -3 )
    {
      Serial.println("Truncated");
       Serial.println( "connection failed");
    }
    else if ( a == -4 )
    {
      Serial.println("Invalid Response");
       Serial.println( "connection failed");
    }
    else
    {
      Serial.println(client.status());
      Serial.println("No Response");
      Serial.println( "connection failed");
    }
  
}

void loop() 
{
    int b = 0 ; // counter
  // put your main code here, to run repeatedly:
    if (client.connected() || client.available()) 
   { //connected or data available
    char c = client.read(); //gets byte from ethernet buffer
    Serial.print(c); //prints byte to serial monitor
  }
  if (!client.connected())
  {
    Serial.println( "Disconnecting" );
    client.stop();
    while(true)
    {
      // do niets
    }
  }

}
