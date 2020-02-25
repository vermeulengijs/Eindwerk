// Ethernet connectie op de LAN aanzetten
// Vermeulen Gijs 13 feb 2020
// versie 1.0

// VIA IP adress kunnen we connecteren met de server van google en kunnen we een GET request doen en krijgen we de data dat we verwachten
// test 1

// ethernet shield pinnen:
// 11 MOSI, 12 MISO , 13 CLK
// CS ethernet controller pin 10
// CS SD kaart pin 4

#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

// MAC address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// aangezien we geen gebruik kunnen maken van een DNS
// IP addressen

IPAddress ip( 192, 168, 0, 177 );  // lokaal ip van de arduino
IPAddress server(172, 217, 21, 131); // ip van google.be

//IPAddress server (104,27,153,209);  // ip van de jason test server
//char Servername[] = "https://jsonplaceholder.typicode.com/";
// Test URL https://jsonplaceholder.typicode.com/
// test ip 104.27.153.209

// byte server[] = { 64, 233, 187, 99 }; // Google

// constante maken voor de ChipSelect pinnen
const int ChipSelectEthernet = 10;
const int ChipSelectSD = 4;

// initialisatie van de ethernet client library
EthernetClient client;


void setup()
{
  int a; // serverResponse

  Serial.begin(9600);
  while( !Serial )
  {
    ; // wait for serial port to connect ( debug )
  }
  Ethernet.init( ChipSelectEthernet );   
  Serial.println("Initialize ethernet ");
  /*
  if ( Ethernet.begin( mac ) == 0 )
  {
    Serial.println( "failed to configure ethernet using DHCP" );
    if ( Ethernet.hardwareStatus() == EthernetNoHardware )
    {
        Serial.println( " Ethernet shield was not found" );
    }
    if ( Ethernet.linkStatus() == LinkOFF )
    {
        Serial.println( "Ethernet cable is not connected" );
    }
  */
    Ethernet.begin( mac, ip );
    Serial.print( "Using fixed");
    /*
  }
  else
  {
    Serial.print( "DHCP assigned ");
  }*/
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
      client.println("GET /search?q=arduino HTTP/1.1");
      client.println("Host: www.google.be");
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
      Serial.println("No Response");
       Serial.println( "connection failed");
    }
 
  Connected();
  
}

void Connected()
{
   int b = 0 ; // counter
   while(client.connected() || client.available()) 
   { //connected or data available
    char c = client.read(); //gets byte from ethernet buffer
    Serial.print(c); //prints byte to serial monitor
  }
  if (!client.connected())
  {
    Serial.println( "Disconnecting" );
    client.stop();
  }
}

void loop() 
{

  // put your main code here, to run repeatedly:
}
