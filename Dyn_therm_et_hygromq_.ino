#include "DHT.h"

#define DHTPIN 2       // Broche DATA
#define DHTTYPE DHT11  // Type de capteur

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Lecture du DHT11...");
}

void loop() {
  // Lecture de l'humidité
  float h = dht.readHumidity();
  // Lecture de la température en °C
  float t = dht.readTemperature();

  // Vérification si la lecture a échoué
  if (isnan(h) || isnan(t)) {
    Serial.println("Erreur lecture capteur !");
    return;
  }

  // Affichage des résultats
  Serial.print("Humidité: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Température: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000); // Pause 2 secondes entre chaque lecture
}
