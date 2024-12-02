// Déclaration des broches auxquelles sont connectés nos composants
const int trigPin = 9;        // Broche du trigger (envoi du signal)
const int echoPin = 10;       // Broche de l'écho (réception du signal)
const int ledGreen = 2;       
const int ledOrange = 3;      
const int ledRed = 4;         

// Initialisation des broches et de la communication série
void setup() {
  pinMode(trigPin, OUTPUT);   // trigPin en mode sortie (envoi du signal)
  pinMode(echoPin, INPUT);    // echoPin en mode entrée (réception du signal)
  // LEDs en mode sortie
  pinMode(ledGreen, OUTPUT);  
  pinMode(ledOrange, OUTPUT); 
  pinMode(ledRed, OUTPUT);    
  Serial.begin(9600);         // Démarrage de la communication en série
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
