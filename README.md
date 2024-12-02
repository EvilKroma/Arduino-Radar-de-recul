# Radar de Recul avec Capteur à Ultrasons et LEDs

Ce projet Arduino utilise un capteur à ultrasons (HC-SR04) pour mesurer la distance entre un objet et le capteur, et allume différentes LEDs en fonction de cette distance. Le projet simule un radar de recul avec des LEDs indiquant si l'objet est proche ou loin, afin de faciliter le stationnement.

## Composants nécessaires

- Arduino Uno (ou toute autre carte Arduino compatible)
- Capteur à ultrasons HC-SR04
- 3 LEDs (rouge, orange, verte)
- 3 résistances de 220Ω pour les LEDs
- Câbles de connexion

## Connexions

Voici comment connecter les composants à l'Arduino :

### Capteur à ultrasons HC-SR04

- **VCC** → 5V de l'Arduino
- **GND** → GND de l'Arduino
- **Trig** → Pin 9 de l'Arduino
- **Echo** → Pin 10 de l'Arduino

### LEDs

- **LED verte**
  - Anode (patte longue) → Pin 2 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND
- **LED orange**
  - Anode (patte longue) → Pin 3 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND
- **LED rouge**
  - Anode (patte longue) → Pin 4 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND

## Code

```cpp
// Déclaration des broches auxquelles sont connectés nos composants
const int trigPin = 9;        // Broche du trigger (envoi du signal)
const int echoPin = 10;       // Broche de l'écho (réception du signal)
const int ledGreen = 2;       // LED verte
const int ledOrange = 3;      // LED orange
const int ledRed = 4;         // LED rouge

// Initialisation des broches et de la communication série
void setup() {
  pinMode(trigPin, OUTPUT);   // trigPin en mode sortie
  pinMode(echoPin, INPUT);    // echoPin en mode entrée
  pinMode(ledGreen, OUTPUT);  // LED verte en mode sortie
  pinMode(ledOrange, OUTPUT); // LED orange en mode sortie
  pinMode(ledRed, OUTPUT);    // LED rouge en mode sortie
  Serial.begin(9600);         // Démarrage de la communication série
}

void loop() {
  // Envoie une impulsion de 10 microsecondes pour déclencher la mesure du capteur
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesure le temps que met l'écho à revenir et le stocke dans 'duration'
  long duration = pulseIn(echoPin, HIGH);
  
  // Convertit la durée en distance (en centimètres)
  int distance = duration * 0.034 / 2;

  // Affiche la distance mesurée dans le moniteur série
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Allume les LEDs en fonction de la distance mesurée
  if (distance < 10) { // Si la distance est inférieure à 10 cm, on allume la LED rouge
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledGreen, LOW);
  } else if (distance >= 10 && distance < 30) { // Si la distance est entre 10 et 30 cm, on allume la LED orange
    digitalWrite(ledRed, LOW);
    digitalWrite(ledOrange, HIGH);
    digitalWrite(ledGreen, LOW);
  } else { // Si la distance est supérieure à 30 cm, on allume la LED verte
    digitalWrite(ledRed, LOW);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledGreen, HIGH);
  }

  // Attente de 100 ms avant de refaire une mesure
  delay(100);
}
