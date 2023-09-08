const int gasSensorPin = A0;   //mendefinisikan sensor gas ke pin arduino A0
const int ldrPin = A1;        //sensor ldr ke pinA1
const int apiPin = A2;        //sensor api ke pinA2
const int kipasPin = 7;       //kipas ke pin 7
const int buzzerPin = 8;      //buzzer ke pin 8
const int greenLedPin = 9;    //LED hijau ke pin 9

void setup() {  // untuk melakukan konfigurasi awal pada mikrokontroler
  pinMode(gasSensorPin, INPUT); //input --> untuk memberikan nilai sensor gas kepada mikrokontroler
  pinMode(kipasPin, OUTPUT); //Ouput --> mengirimkan sinyal perangkat external berupa kipas
  pinMode(buzzerPin, OUTPUT); //Ouput --> mengirimkan sinyal perangkat external berupa suara
  pinMode(ldrPin, INPUT); //input --> untuk memberikan nilai sensor ldr kepada mikrokontroler
  pinMode(apiPin, INPUT); //input --> untuk memberikan nilai sensor api kepada mikrokontroler
  pinMode(greenLedPin, OUTPUT); //Ouput --> mengirimkan sinyal perangkat external berupa lampu hijau
  Serial.begin(9600); //komunikasi serial 
}

void loop() { 
  // Sensor Gas
  int gasValue = analogRead(gasSensorPin); //untuk membaca nilai dari sensor gas 
  Serial.print("Gas Value: "); //menghasilkan nilai gas value di serial monitor
  Serial.println(gasValue); //untuk menghasilkan hasil dari pembacaan nilai dari sensor gas

  if (gasValue > 500) { // jika nilai gas lebih besar dari 600 
    digitalWrite(kipasPin, HIGH);// maka kipas hidup
  } else { // jika nilai gas lebih kecil dari 600
    digitalWrite(kipasPin, LOW);// maka kipas mati
  }

  // Sensor LDR
  int ldrValue = analogRead(ldrPin); // untuk membaca nilai dari sensor ldr
  Serial.print("LDR Value: "); // menghasilkan nilai ldr value di serial monitor
  Serial.println(ldrValue); //untuk menghasilkan hasil dari pembacaan nilai dari sensor ldr

  if (ldrValue > 200) { //jika nilai dari ldr lebih besar dari 200 
    digitalWrite(greenLedPin, LOW); //maka LED hijau mati
  } else { //jika nilai ldr lebih kecil dari 200
    digitalWrite(greenLedPin, HIGH);// maka lampu hijau akan hidup
  }

  // // Sensor Api
  int apiValue = analogRead(apiPin); // untuk membaca nilai dari sensor api
  Serial.print("Api Value: "); //menghasilkan nilai api value di serial monitor
  Serial.println(apiValue); //untuk menghasilkan hasil dari pembacaan nilai dari sensor api

  if (apiValue < 500) { //jika nilai dari api lebih kecil dari 500 
    digitalWrite(buzzerPin, HIGH);// maka buzzer hidup
  } else { // jika sensor api lebih besar dari 500 
    digitalWrite(buzzerPin, LOW);// maka buzzer mati
  }

  delay(1000); //delay 1 detik untuk membaca nilai dari sensor api, gas dan LDR
}
