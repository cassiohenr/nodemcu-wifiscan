#include <ESP8266WiFi.h>

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Configurado.");
}

void loop() 
{
  Serial.println("/Iniciando Varredura.");
  int n = WiFi.scanNetworks(false, true);
  Serial.println("/Varredura Completa.");
  if (n == 0)
    Serial.println("/Não foi encontrada nenhuma rede.");
  else
  {
    Serial.print("/");
    Serial.print(n);
    Serial.println(" redes encontradas.");
    for (int i = 0; i < n; i++)
    {
      Serial.print(i);
      Serial.print(": SSID: ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | ENCRYP: ");
      Serial.print(WiFi.encryptionType(i));
      Serial.print(" | RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" | MAC_PA: ");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.print(" | CH: ");
      Serial.print(WiFi.channel(i));
      Serial.print(" | OCULTA? ");
      Serial.print(WiFi.isHidden(i));
      Serial.println();
      
    }
  }
  Serial.println("");

 delay(1000);
